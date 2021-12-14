project(wasmtime-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(${CMAKE_SOURCE_DIR}/wasmtime-c-api/include)
link_directories(${CMAKE_SOURCE_DIR}/wasmtime-c-api/lib)


add_executable(TestMain WasmFunction.cpp TestMain.cpp)

target_include_directories(TestMain INTERFACE wasmtime-c-api/include)
target_link_libraries(TestMain libwasmtime.a libwasmtime.so stdc++ pthread dl)
