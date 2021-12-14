
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
    void runWatFile(const std::string &fileName) const;
    void runWat(const std::string &watString) const;
};