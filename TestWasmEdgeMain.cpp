#include <wasmedge/wasmedge.h>
#include <stdio.h>
#include <vector>
#include <iostream>

int main() {
    // 1. set the vm
    WasmEdge_ConfigureContext *ConfCxt = WasmEdge_ConfigureCreate();
    WasmEdge_ConfigureAddHostRegistration(ConfCxt, WasmEdge_HostRegistration_Wasi);

    WasmEdge_VMContext *VMCxt = WasmEdge_VMCreate(ConfCxt, NULL);
    WasmEdge_Result Res;

    Res = WasmEdge_VMLoadWasmFromFile(VMCxt, "../demo/string/say/pkg/rust_bindgen_funcs_lib_bg.wasm");
    if (!WasmEdge_ResultOK(Res)) {
        printf("Loading phase failed: %s\n", WasmEdge_ResultGetMessage(Res));
        return 1;
    }
    Res = WasmEdge_VMValidate(VMCxt);
    if (!WasmEdge_ResultOK(Res)) {
        printf("Validation phase failed: %s\n", WasmEdge_ResultGetMessage(Res));
        return 1;
    }
    Res = WasmEdge_VMInstantiate(VMCxt);
    if (!WasmEdge_ResultOK(Res)) {
        printf("Instantiation phase failed: %s\n", WasmEdge_ResultGetMessage(Res));
        return 1;
    }

    // 2. set the memory
    auto Store = WasmEdge_VMGetStoreContext(VMCxt);
    uint32_t MemLen = WasmEdge_StoreListMemoryLength(Store);
    WasmEdge_String MemNames[MemLen];
    WasmEdge_StoreListMemory(Store, MemNames, MemLen);
    auto MemInst = WasmEdge_StoreFindMemory(Store, MemNames[0]);

    // 3
    // 3.1 insert function param
    std::string RequestStr = "12345678";
    std::vector<WasmEdge_Value> Args;
    // 3.1 set the magic number as first address
    uint32_t ResultMemAddr = 8;
    Args.emplace_back(WasmEdge_ValueGenI32(ResultMemAddr));

    // 3.2
    // 3.2.1 malloc memory
    uint32_t MallocSize = 0, MallocAddr = 0;
    std::string StrArg = RequestStr;
    MallocSize = StrArg.length();
    WasmEdge_Value Params = WasmEdge_ValueGenI32(MallocSize);
    WasmEdge_Value Rets;
    // must be `__wbindgen_malloc`
    WasmEdge_String memFuncName =
            WasmEdge_StringCreateByCString("__wbindgen_malloc");

    // 3.2.2 set the memory to vm
    WasmEdge_Result createResult =
            WasmEdge_VMExecute(VMCxt, memFuncName, &Params, 1, &Rets, 1);
    WasmEdge_StringDelete(memFuncName);

    MallocAddr = (uint32_t)WasmEdge_ValueGetI32(Rets);

    if (!WasmEdge_ResultOK(createResult)) {
        printf("set data failed: %s\n", WasmEdge_ResultGetMessage(createResult));
    }else{
        printf("set data success: %s\n", WasmEdge_ResultGetMessage(createResult));
    }

    Args.emplace_back(WasmEdge_ValueGenI32(MallocAddr));
    Args.emplace_back(WasmEdge_ValueGenI32(MallocSize));


    // 3.2.2 copy data to memory.
    std::vector<uint8_t> bufVector(StrArg.begin(), StrArg.end());
    WasmEdge_MemoryInstanceSetData(MemInst,bufVector.data(),MallocAddr,bufVector.size());


    // 4. run the function
    WasmEdge_String FuncName = WasmEdge_StringCreateByCString("say");
    WasmEdge_Value Ret;

    Res = WasmEdge_VMExecute(VMCxt, FuncName, Args.data(), Args.size(), &Ret, 1);
    WasmEdge_StringDelete(FuncName);
    if (!WasmEdge_ResultOK(Res)) {
        printf("get return failed: %s\n", WasmEdge_ResultGetMessage(Res));
    }else{
        printf("get return success: %s\n", WasmEdge_ResultGetMessage(Res));
    }

    // 5
    // 5.1 get the data address
    uint8_t ResultMem[8];
    Res = WasmEdge_MemoryInstanceGetData(MemInst, ResultMem, ResultMemAddr, 8);
    uint32_t ResultDataAddr = 0;
    uint32_t ResultDataLen = 0;
    if (WasmEdge_ResultOK(Res)) {
        ResultDataAddr = ResultMem[0] | (ResultMem[1] << 8) | (ResultMem[2] << 16) |
                         (ResultMem[3] << 24);
        ResultDataLen = ResultMem[4] | (ResultMem[5] << 8) | (ResultMem[6] << 16) |
                        (ResultMem[7] << 24);
    } else {
        printf("get data return failed: %s\n", WasmEdge_ResultGetMessage(Res));
        return 0;
    }
    // 5.2 get the data
    std::vector<uint8_t> ResultData(ResultDataLen);
    auto getFinalRes = WasmEdge_MemoryInstanceGetData(MemInst, ResultData.data(),
                                         ResultDataAddr, ResultDataLen);
    if (WasmEdge_ResultOK(getFinalRes)) {
        printf("get final data success\n");
    } else {
        printf("get final data return failed: %s\n", WasmEdge_ResultGetMessage(getFinalRes));
        return 0;
    }
    std::string ResultString(ResultData.begin(), ResultData.end());

    // hello 12345678
    std::cout << ResultString << std::endl;


    return 0;
}