# Project Templates

This repository contains my personal project templates which I often use and for convenience store in one place.
There are CMake, Meson and GNU Make example projects for C/C++ and also Python projects with custom `setup.py` file.

- CMake projects starts with prefix `cmake`.
- Meson projects starts with prefix `meson`.
- GNU Make projects starts with prefix `gmake`.

     
## Contents

How to 
- define a library with header files only. 
- define a library with header and source files.
  - define static library (.lib, .a)
  - define dynamic library (.dll, .so, .dylib)

All projects consists of at contains tests!

- Catch2
- GTest, GMock

## Getting Started

For all example projects follow these steps: 

	cmake -H. -Bbuild
	
	cmake --build build --config Debug
or
	cmake --build build --config Release
	
	cd build

	ctest -C Debug
or
	ctest -C Release

## Direct 3D and WinAPI

- http://winapi.foosyerdoos.org.uk/

### cmake-dx-01 (Window)

This example project shows how to create a window with help of WinAPI and DirectX 3D 12 context.

### cmake-dx-0x (Button Control)
### cmake-dx-0x (ComboBox Control)
### cmake-dx-0x (Edit Control)
### cmake-dx-0x (ListBox Control)
### cmake-dx-0x (RichEdit Control)
### cmake-dx-0x (ScrollBar Control)
### cmake-dx-0x (Date and Time Picker Control)
### cmake-dx-0x (Header Control)
### cmake-dx-0x (ListView Control)
### cmake-dx-0x (ProgressBar Control)
### cmake-dx-0x (StatusBar Control)
### cmake-dx-0x (ToolBar Control)
### cmake-dx-0x (ToolTip Control)
### cmake-dx-0x (TrackBar Control)
### cmake-dx-0x (TreeView Control)
### cmake-dx-0x (Up-Down Control)

## Project Templates

### cmake-project01

A header library with Catch tests.

### cmake-project02

A compiled library with Catch tests.

## Tips

- Use CMake variables to reduce repetition e.g use ${PROJECT_NAME} for library name.

	    project(my_project_name VERSION 1.0 LANGUAGES CXX)
	    ...
	    add_library(${PROJECT_NAME} INTERFACE)


- Use the newest CMake version as possible, but you can allow version ranges.

	    cmake_minimum_required(VERSION 3.1...3.15)


- Format the code with `clang-format`
  https://zed0.co.uk/clang-format-configurator/

        clang-format -i -style=Google ./include/project/project.hpp


## Python

- https://pyup.io
