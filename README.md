# wasm-cpp

**The simple test of wasm in cpp does not include any performance evaluation.**

#### Include
* [wasmtime](https://github.com/bytecodealliance/wasmtime)
* [WasmEdge](https://github.com/WasmEdge/WasmEdge)
  
## How to develop

### wasmtime
[Official guide](https://github.com/bytecodealliance/wasmtime-cpp)

#### Get wasmtime kit 
Ref: https://github.com/bytecodealliance/wasmtime-cpp
```bash
wget https://github.com/bytecodealliance/wasmtime/releases/download/v0.32.0/wasmtime-v0.32.0-x86_64-linux-c-api.tar.xz
mkdir wasmtime-c-api&& tar -xvf wasmtime-v0.32.0-x86_64-linux-c-api.tar.xz --strip-components=1  -C wasmtime-c-api
wget https://raw.githubusercontent.com/bytecodealliance/wasmtime-cpp/main/include/wasmtime.hh -O wasmtime-c-api/include/wasmtime.hh
rm wasmtime-v0.32.0-x86_64-linux-c-api.tar.xz
```
#### Compile
```bash
mkdir build && cd build && cmake ../ 
make TestWasmtimeMain
```

### WasmEdge
[Official guide](https://github.com/WasmEdge/WasmEdge/blob/master/docs/c_api_quick_start.md)