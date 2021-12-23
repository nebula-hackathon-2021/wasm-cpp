#include <wasmedge/wasmedge.h>
#include <stdio.h>
#include <vector>

int main(int Argc, const char *Argv[]) {
    /* 创建配置上下文以及 WASI 支持。 */
    /* 除非你需要使用 WASI，否则这步不是必须的。 */
    WasmEdge_ConfigureContext *ConfCxt = WasmEdge_ConfigureCreate();
    WasmEdge_ConfigureAddHostRegistration(ConfCxt, WasmEdge_HostRegistration_Wasi);
    /* 创建VM的时候可以提供空的配置。*/
    WasmEdge_VMContext *VMCxt = WasmEdge_VMCreate(ConfCxt, NULL);

    /* 参数以及返回的数组。 */
    std::vector<WasmEdge_Value> fpm;
    fpm.push_back(WasmEdge_ValueGenI32(23));
    fpm.push_back(WasmEdge_ValueGenI32(456));
    WasmEdge_Value Returns[1];
    /* 要调用的函数名。 */
    WasmEdge_String FuncName = WasmEdge_StringCreateByCString("one");
    /* 运行文件里的 WASM 函数。 */
    WasmEdge_Result Res = WasmEdge_VMRunWasmFromFile(VMCxt, Argv[1], FuncName, fpm.data(), fpm.size(), Returns, 1);


    if (WasmEdge_ResultOK(Res)) {
        printf("Get result: %d\n", WasmEdge_ValueGetI32(Returns[0]));
//      printf("Get result: %d\n", WasmEdge_ValueGetI32(Returns[1]));
    } else {
        printf("Error message: %s\n", WasmEdge_ResultGetMessage(Res));
    }

    /* 资源析构。 */
    WasmEdge_VMDelete(VMCxt);
    WasmEdge_ConfigureDelete(ConfCxt);
    WasmEdge_StringDelete(FuncName);
    return 0;
}