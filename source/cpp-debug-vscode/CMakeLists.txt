cmake_minimum_required(VERSION 3.20)

project(
    cpp-debug-vscode
    VERSION 0.1.0
    LANGUAGES CXX    
)

add_library(SimpleLib STATIC simple_lib.cpp simple_lib.h)

add_executable(Simple simple_main.cpp)

target_link_libraries(Simple PRIVATE SimpleLib)