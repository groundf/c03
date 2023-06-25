# c03

C, C++, STL, CMake course

## Overview

<details>
<summary>C/C++</summary>
 
 - First steps
 - source (`.cpp`) files, header files (`.hpp`)
 - compilation  `g++ --std=c++2a <source> -o <ooutput>`
 - modules (`.ixx`) (C++20)
 - console input/output `<iostream>`
- Control structures
  - conditions (branching)
   - `if` statement
     - simple `if` statement
     - chained `if` statement
     - nested `if` statement
   - `switch` statement
   - iterations (lopping/cycles)
     - `while`
     - `for` with counter
     - `for` with iterator
   - range-based-loop (C++20)
- Compilation and Linking: gcc, clang, msvc
  - compile and link simple program
  - compile and link static library (statically linkable)
  - compile and link shared library (dynamically linkable)
- User Defined Types: structures & classes
  - struct vs class: private vs public,
  - inheritance: public, private
  - explicit/default constructor & default destructor
  - deleted constructor, destructor
- Enumarations
 - `enum` vs `enum class`
- Pointers & References
- Copy & Move Semantics
  - L, R values
- Templates
  - class and function template, selcialization, SFINAE
    - template parameter
    - template argument
- Concepts (C++20), Traits (C++11)
- C++ Standard Template Library (STL)
  STL data structures and algorithms.
  - containers
  - iterators

</details>

<details>
 
<summary>CMake</summary>

- Compilation and Linking: gcc, clang, msvc
  - compile and link simple program
  - compile and link static library (statically linkable)
  - compile and link shared library (dynamically linkable)

All examples can be build with these command.

```shell
cd path/to/example
```

Generate project files.

```shell
cmake -Bbuild -H. -G "Visual Studio 15 2017 Win64"
```

Build debug or release target.

```shell
cmake --build build --target 01_demo --config Debug
cmake --build build --target 01_demo --config Release
```

- cmake01_flatstructure: Project with flat structure without `src` or `include` directories.
- cmake02_subdirectories: Project with `src` and `include` subdirectories.
- cmake03_staticlibrary: Project with binary and linked static library.
- cmake03_sharedlibrary: Project with binary and linked shared library.

The standard CMake output

```
$ cmake --build build --target 02_demo --config Release
Microsoft (R) Build Engine verze 15.9.21+g9802d43bc3 pro .NET Framework
Copyright (C) Microsoft Corporation. Všechna práva vyhrazena.

Vytváření sestavení bylo zahájeno 11.1.2019 12:50:02.
Projekt C:\Users\dlanda\projects\personal\cmake-templates\02_demo\build\02_demo.vcxproj v uzlu 1 (výchozí cíle).
Probíhá sestavení projektu C:\Users\dlanda\projects\personal\cmake-templates\02_demo\build\02_demo.vcxproj (1) -
C:\Users\dlanda\projects\personal\cmake-templates\02_demo\build\ZERO_CHECK.vcxproj (2) v uzlu 1 (výchozí cíle).
PrepareForBuild:
  Probíhá vytváření adresáře x64\Release\ZERO_CHECK\.
  Probíhá vytváření adresáře x64\Release\ZERO_CHECK\ZERO_CHECK.tlog\.
InitializeBuildStatus:
  Probíhá vytváření souboru x64\Release\ZERO_CHECK\ZERO_CHECK.tlog\unsuccessfulbuild v důsledku zadání AlwaysCrea
  te.
CustomBuild:
  Checking Build System
  CMake does not need to re-run because C:/Users/dlanda/projects/personal/cmake-templates/02_demo/build/CMakeFile
  s/generate.stamp is up-to-date.
FinalizeBuildStatus:
  Probíhá odstraňování souboru x64\Release\ZERO_CHECK\ZERO_CHECK.tlog\unsuccessfulbuild.
  Probíhá aktualizace časového razítka pro x64\Release\ZERO_CHECK\ZERO_CHECK.tlog\ZERO_CHECK.lastbuildstate.
Sestavení projektu C:\Users\dlanda\projects\personal\cmake-templates\02_demo\build\ZERO_CHECK.vcxproj (s výchozím i cíli) bylo dokončeno.

PrepareForBuild:
  Probíhá vytváření adresáře 02_demo.dir\Release\.
  Probíhá vytváření adresáře C:\Users\dlanda\projects\personal\cmake-templates\02_demo\build\Release\.
  Probíhá vytváření adresáře 02_demo.dir\Release\02_demo.tlog\.
InitializeBuildStatus:
  Probíhá vytváření souboru 02_demo.dir\Release\02_demo.tlog\unsuccessfulbuild v důsledku zadání AlwaysCreate.
CustomBuild:
  Building Custom Rule C:/Users/dlanda/projects/personal/cmake-templates/02_demo/CMakeLists.txt
  CMake does not need to re-run because C:/Users/dlanda/projects/personal/cmake-templates/02_demo/build/CMakeFile
  s/generate.stamp is up-to-date.
ClCompile:
  C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Tools\MSVC\14.16.27023\bin\HostX86\x64\CL.exe
   /c /I"C:\Users\dlanda\projects\personal\cmake-templates\02_demo\include" /nologo /W3 /WX- /diagnostics:classic
   /O2 /Ob2 /D WIN32 /D _WINDOWS /D NDEBUG /D "CMAKE_INTDIR=\"Release\"" /D _MBCS /Gm- /EHsc /MD /GS /fp:precise
  /Zc:wchar_t /Zc:forScope /Zc:inline /GR /Fo"02_demo.dir\Release\\" /Fd"02_demo.dir\Release\vc141.pdb" /Gd /TP /
  FC /errorReport:queue "C:\Users\dlanda\projects\personal\cmake-templates\02_demo\src\core.cpp" "C:\Users\dlanda
  \projects\personal\cmake-templates\02_demo\src\main.cpp"
  core.cpp
  main.cpp
  Generování kódu...
Link:
  C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Tools\MSVC\14.16.27023\bin\HostX86\x64\link.e
  xe /ERRORREPORT:QUEUE /OUT:"C:\Users\dlanda\projects\personal\cmake-templates\02_demo\build\Release\02_demo.exe
  " /INCREMENTAL:NO /NOLOGO kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uui
  d.lib comdlg32.lib advapi32.lib /MANIFEST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /PD
  B:"C:/Users/dlanda/projects/personal/cmake-templates/02_demo/build/Release/02_demo.pdb" /SUBSYSTEM:CONSOLE /TLB
  ID:1 /DYNAMICBASE /NXCOMPAT /IMPLIB:"C:/Users/dlanda/projects/personal/cmake-templates/02_demo/build/Release/02
  _demo.lib" /MACHINE:X64  /machine:x64 02_demo.dir\Release\core.obj
  02_demo.dir\Release\main.obj
  02_demo.vcxproj -> C:\Users\dlanda\projects\personal\cmake-templates\02_demo\build\Release\02_demo.exe
FinalizeBuildStatus:
  Probíhá odstraňování souboru 02_demo.dir\Release\02_demo.tlog\unsuccessfulbuild.
  Probíhá aktualizace časového razítka pro 02_demo.dir\Release\02_demo.tlog\02_demo.lastbuildstate.
Sestavení projektu C:\Users\dlanda\projects\personal\cmake-templates\02_demo\build\02_demo.vcxproj (s výchozími c íli) bylo dokončeno.
```

</details>


## Resources

- C++ reference https://en.cppreference.com/w/
- C++ core guidelines, https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
- https://cppinsights.io/s/35155190
- https://devblogs.microsoft.com/cppblog/moving-a-project-to-cpp-named-modules/
- https://www.jetbrains.com/help/clion/quick-cmake-tutorial.htm

- Bjarne Stroustrup
- Herb Sutter
- Scott Meyers
- Alexander Alexandrescu
- Alexander Stepanov
