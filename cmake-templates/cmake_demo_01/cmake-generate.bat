@echo off

:: Generujeme `.sln` zvlášť pro 32/64 bit verzi do oddělených adresářů.
cmake -H. -Bbuild/vs14_x32 -G "Visual Studio 14 2015"
cmake -H. -Bbuild/vs14_x64 -G "Visual Studio 14 2015 Win64"
