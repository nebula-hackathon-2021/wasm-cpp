# wasm-cpp

**Please see our [main repository](https://github.com/nebula-hackathon-2021/nebula) for the application of the demo below.**

## Demo List

| Name   | Description             | Runtime  | Param                    |
| ------ | ----------------------- | -------- | ------------------------ |
| [addTwo](./demo/addTwo) | add two number          | wasmtime | (INT32 INT32) -> (INT32) |
| [gcd](./demo/gcd)    | greatest common divisor | wasmtime | (INT32 INT32) -> (INT32) |
| Feishu Bot | call Feishu api and send message | WasmEdge | (STRING) -> BOOL |
| Data Clustering by TensorFlow |                         |          |  |













## How to develop

#### Include runtime
* [wasmtime](https://github.com/bytecodealliance/wasmtime)
* [WasmEdge](https://github.com/WasmEdge/WasmEdge)

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

```bash
mkdir build && cd build && cmake ../ 
make TestWasmEdgeMain
```