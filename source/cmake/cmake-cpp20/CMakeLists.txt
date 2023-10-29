cmake_minimum_required(VERSION 3.5)

project(cpp_examples)

add_executable(hello hello.cpp)

set_property(TARGET hello PROPERTY CXX_STANDARD 20)

install(TARGETS hello DESTINATION bin)