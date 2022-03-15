# wasm-cpp

**Please see our [main repository](https://github.com/nebula-hackathon-2021/nebula) for the application of the demo below.**

## How to use
```shell
cd demo && python3 -m http.server 8080
```
## Demo List

| Name                          | Description                      | Runtime  | Param                    | USAGE |
|-------------------------------|----------------------------------|----------|--------------------------|-------|
| [addTwo](./demo/addTwo)       | add two number                   | wasmtime | (INT32 INT32) -> (INT32) |       |
| [gcd](./demo/gcd)             | greatest common divisor          | wasmtime | (INT32 INT32) -> (INT32) |       |
| [string](./demo/string)       | return string                    | WasmEdge | (STRING) -> (STRING)     |       |
| [Feishu Bot](./demo/feishu)   | call Feishu api and send message | WasmEdge | (STRING) -> (STRTING)    |       |
| [calcutor](./demo/feishu)     | an calcutor                      | WasmEdge | (STRING) -> (STRTING)   |       |


### The SQL
#### addTwo
```gcd
CREATE FUNCTION gcd_main(x INT32, y INT32) RETURN INT32 FROM WAT://KG1vZHVsZQogIChmdW5jICRnY2QgKHBhcmFtIGkzMiBpMzIpIChyZXN1bHQgaTMyKQogICAgKGxvY2FsIGkzMikKICAgIGJsb2NrICA7OyBsYWJlbCA9IEAxCiAgICAgIGJsb2NrICA7OyBsYWJlbCA9IEAyCiAgICAgICAgbG9jYWwuZ2V0IDAKICAgICAgICBicl9pZiAwICg7QDI7KQogICAgICAgIGxvY2FsLmdldCAxCiAgICAgICAgbG9jYWwuc2V0IDIKICAgICAgICBiciAxICg7QDE7KQogICAgICBlbmQKICAgICAgbG9vcCAgOzsgbGFiZWwgPSBAMgogICAgICAgIGxvY2FsLmdldCAxCiAgICAgICAgbG9jYWwuZ2V0IDAKICAgICAgICBsb2NhbC50ZWUgMgogICAgICAgIGkzMi5yZW1fdQogICAgICAgIGxvY2FsLnNldCAwCiAgICAgICAgbG9jYWwuZ2V0IDIKICAgICAgICBsb2NhbC5zZXQgMQogICAgICAgIGxvY2FsLmdldCAwCiAgICAgICAgYnJfaWYgMCAoO0AyOykKICAgICAgZW5kCiAgICBlbmQKICAgIGxvY2FsLmdldCAyCiAgKQogIChleHBvcnQgIm1haW4iIChmdW5jICRnY2QpKSA7OyBleHBvcnQgd2l0aCBtYWluCik=;
RETURN UDF("gcd",[12,27]);
```

#### gcd
```sql

```
#### string
```shell
cd demo/string/say && rustwasmc build
cd demo && python3 -m http.server 8080
```

```sql
CREATE FUNCTION thestring_say(x STRING) RETURN STRING FROM PATH://http://0.0.0.0:8080/string/say/pkg/rust_bindgen_funcs_lib_bg.wasm;
RETURN UDF("thestring",["triplez"])
```


#### Feishu Bot
```sql

```








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