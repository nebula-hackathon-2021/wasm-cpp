# wasmtime-cpp

Example for wasmtime-cpp

## How to develop
#### Get wasmtime 
Ref: https://github.com/bytecodealliance/wasmtime-cpp
```bash
wget https://github.com/bytecodealliance/wasmtime/releases/download/v0.32.0/wasmtime-v0.32.0-x86_64-linux-c-api.tar.xz
mkdir wasmtime-c-api&& tar -xvf wasmtime-v0.32.0-x86_64-linux-c-api.tar.xz --strip-components=1  -C wasmtime-c-api
wget https://raw.githubusercontent.com/bytecodealliance/wasmtime-cpp/main/include/wasmtime.hh -O wasmtime-c-api/include/wasmtime.hh
rm wasmtime-v0.32.0-x86_64-linux-c-api.tar.xz
```
#### Compile
```bash
cmake .
make
```