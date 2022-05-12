# Kompilace knihovny Qt na Windows OS

Stáhnutí zdrojových souborů

Nejprve potřebujeme stáhnot zdrojový kód ...

Git

`git clone https://code.qt.io/qt/qt5.git`

`git branch -r`

`origin/5.3`

`origin/5.3.0`

`origin/5.3.1`

`origin/5.3.2`

`origin/5.4`

`origin/5.4.0`

`origin/5.4.1`

`origin/5.4.2`

`origin/5.5`

`origin/5.5.0`

`origin/5.5.1`

`origin/5.6`

`origin/5.6.0`

`origin/5.6.1`

`origin/5.7`

`origin/5.7.0`

`origin/HEAD -> origin/5.6`

`origin/dev`

Vyberem větev

```
git checkout 5.6.1
```

Stáhneme submoduly

Pokud nepotřebujeme QWebKit, pak ho zavoláme takto:

```
perl init-repository --module-subset=default,-qtwebkit,-qtwebkit-examples,-qtwebengine
```

Budeme potřebovat stáhnout všechny submoduly a od toho je zde Perl skript init-repository.

Ujistěte se, že máte novou verzi Perlu, která je v cestě před Gitem, nikoliv tu, keterá přichází s Gitem.

WARNING: Using static linking will disable the use of plugins.

```
     Make sure you compile ALL needed modules into the library.
```

Kompilace zdrojových souborů

spustíme configure.bat

V průběhu budeme dotázáni na licenci Qt.

```
napíšeme o pro open source

napíšeme y pro akceptování licence
```

Na konci bude

Qt is now configured for building. Just run nmake.

To reconfigure, run nmake confclean and configure.

Nastavíme též multiprocessing, aby kompilátor využil všechna jádra.

```
SET CL=/MP
```

Spustíme nmake -- začáná kompilace .\)

Doplněk do Visual Studio: Qt5Package

Upgrade Qt

Pakliže máme již jednou Qt naistalováno, stačí spustit update v kořenovém adresáři Qt.

Potřebujeme-li ICU&gt; stáhneme si odpovídající verzi

[http://download.icu-project.org/files/icu4c/57.1/icu4c-57\\_1-src.zip](http://download.icu-project.org/files/icu4c/57.1/icu4c-57\_1-src.zip)

