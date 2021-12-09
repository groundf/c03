cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)

project(window_sample VERSION 0.1.0 LANGUAGES CXX)

# set(SOURCES window.cpp "The C++ source files.")

# set(HEADERS window.hpp "The C++ header files.")


add_executable(window_sample WIN32)


message(${CMAKE_CURRENT_SOURCE_DIR})


target_sources(window_sample PRIVATE window.cpp)
target_include_directories(window_sample PRIVATE 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)