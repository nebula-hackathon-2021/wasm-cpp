#include <fstream>
#include <iostream>
#include <sstream>
#include "WasmFunction.h"

int main() {
  WasmFunction wasmFunction;
  wasmFunction.runWatFile("gcd.wat");
}