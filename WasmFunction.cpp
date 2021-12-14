#include <fstream>
#include <iostream>
#include <sstream>
#include "WasmFunction.h"


WasmFunction::WasmFunction()
{
  engine = new  wasmtime::Engine;
  store = new  wasmtime::Store(*engine);
}

WasmFunction::~WasmFunction()
{
  delete (store);
  delete (engine);
}

std::string readFile(const std::string name)
{
  std::ifstream watFile;
  watFile.open(name);
  std::stringstream strStream;
  strStream << watFile.rdbuf();
  return strStream.str();
}

void WasmFunction::runWatProgram(const std::string &fileName) const
{
  // Read our input file, which in this case is a wat text file.
  auto wat = readFile(fileName);
  // 
  auto module = wasmtime::Module::compile(*engine, wat).unwrap();
  auto instance = wasmtime::Instance::create(store, module, {}).unwrap();

  // Invoke `gcd` export
  auto func = std::get<wasmtime::Func>(*instance.get(store, "main"));
  auto results = func.call(store, {6, 27}).unwrap();
  
  std::cout << "gcd(6, 27) = " << results[0].i32() << "\n";
}

