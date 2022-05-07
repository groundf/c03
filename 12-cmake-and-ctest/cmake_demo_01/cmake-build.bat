@echo off

:: Globální proměnné
set VS14_HOME=...

:: Sestavíme projekt v Debug/Release 64bit.
cmake --build build/vs14_x64 --config Debug
cmake --build build/vs14_x64 --config Release

:: Sestavíme projekt v Debug/Release 32bit.
cmake --build build/vs14_x32 --config Debug
cmake --build build/vs14_x32 --config Release
