
#include <wasmtime.hh>


class WasmFunction
{
private:
    wasmtime::Engine *engine;
    wasmtime::Store *store;
    /* data */
public:
    WasmFunction();
    ~WasmFunction();
    void runWatProgram(const std::string &fileName) const;
};