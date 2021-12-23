project(wasmtime-cpp)
cmake_minimum_required(VERSION 3.16/3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/wasmtime-c-api/include)
link_directories(${CMAKE_SOURCE_DIR}/wasmtime-c-api/lib)

add_executable(TestWasmtimeMain WasmFunction.cpp TestWasmtimeMain.cpp)

target_include_directories(TestWasmtimeMain INTERFACE wasmtime-c-api/include)
target_link_libraries(TestWasmtimeMain  libwasmtime.a libwasmtime.so stdc++ pthread dl)

# WasmEdge
include_directories(${CMAKE_SOURCE_DIR}/wasmedge/include)
link_directories(${CMAKE_SOURCE_DIR}/wasmedge/lib)

add_executable(TestWasmEdgeMain TestWasmEdgeMain.cpp)

target_include_directories(TestWasmEdgeMain INTERFACE ${CMAKE_SOURCE_DIR}/wasmedge/include)
target_link_libraries(TestWasmEdgeMain libwasmedge_c.so)

