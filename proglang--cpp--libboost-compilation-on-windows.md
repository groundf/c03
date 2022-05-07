## Jak zkompilovat knihovnu Boost pro OS Windows

Ačkoliv velká část knihovny Boost je napsána pomocí šablonových tříd a 
funkcí a tedy většina definice funkcí a tříd je zapsána přímo v hlavičkových 
souborech, přesto je nutné některé její části kompilovat. většinou se jedná o 
části knihovny, které jsou závislé na oparačním sustému, jako např boost/filesystem.

C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat 

### Předkompilované instalační balíčky knihovny Boost pro OS Windows

První možností je stáhnout si předkompilovaný balík z [https://sourceforge.net/projects/boost/files/boost-binaries/](https://sourceforge.net/projects/boost/files/boost-binaries/)

boost\_1\_61\_0-msvc-14.0-64.exe

# Návod na kompilaci knihovny Boost pro OS Windows

Zdrojové soubory knihovny si stáhneme zde \(aktuální verze v článku je 1.6\):

[https://sourceforge.net/projects/boost/files/boost/1.61.0/](https://sourceforge.net/projects/boost/files/boost/1.61.0/)

### Kompilace pro 64bit systém; kompilátor MSVC 14.0 \(Visual Studio 2015\)

```
b2 --build-dir=build_msvc14_64 toolset=msvc address-model=64 --build-type=complete --stagedir=stage_64 > build64.log 2>&1
```

### Kompilace pro 32bit systém; kompilátor MSVC 14.0 \(Visual Studio 2015\)

```
b2 --build-dir=build_msvc14_32 toolset=msvc address-model=32 --build-type=complete --stagedir=stage_32 > build32.log 2>&1
```

Pokud v logu uvidíme řádky níže uvedenou zapsanou informaci proběhlo vše v pořádku.

> The Boost C++ Libraries were successfully built!

The following directory should be added to compiler include paths:

```
C:\Libraries\boost\boost_1_60_0
```

The following directory should be added to linker library paths:

```
C:\Libraries\boost\boost_1_60_0\stage_64\lib
```



