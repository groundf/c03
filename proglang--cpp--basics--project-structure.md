extends: default.liquid

title: Struktura projektu v jazyce C++
date: 24 December 2016 21:25:00 +0200
tags: C++, project management
lang: cs
---

Práce s C/C++ projekty je z mého pohledu  od odts náročnější než s projekty v jiných jazycích. 
Za prvé není zcela přeně dáno jak strukturovat projekt a navíc C/C++ nemá žádného správce závislostí 
jako `npm`, `pip`. Každý projekt může mít tedy trochu jinou strukturu i přístup k tomu jak řeší získání 
a sestavení závislostí a pokud má být projekt multiplatformní pak se možnosti ještě více komplikují. 
V posledních letech se v C/C++ projekteech prosadil nástroj CMake, který nám pomůže projekt připravit 
pro sestavení na všech běžných platformách a vlastně umí svým způsobem získat a závislosti nutné pro 
sestavení projektu. V tomto přehledu se budu snažit ukázat několik způsobů ,jak strukturovaty projekt 
a sjednotit si alespoň své osobní projekty, protože jak již bylo řečeno, uplná shoda na tom, jak má 
tato struktura vypadata, není.

Každý podprojekt může být závislý jen na projektu, ketrý je na stejné úrovni.

1. Každý zdrojový soubor (`file.c*`) musí jako první vkládat odpovídající hlavičkový soubor (`file.h*`).
  (Pokud používáte předkompilované hlavičkové soubory, pak ty musí být ovšem vloženy první.)

2. Každý hlavičkový musí vložit všechny hlavičkové soubory nutné pro jeho funkčnost.

```
#ifndef FILE_H
#define FILE_H

#include <string>

struct C
{
	std::string hello() const;
};

#endif
```


Adresářová struktura projektu 

	
Project/
```
cmake/
	různé funkce použité kořenovém cmake souboru.

CMakeLists.txt

doc/
src/
	app/
		src/
		moc/
		uic/

	some_lib1/
		inc/
		src/

	some_lib2/
		inc/
		src/
lib/
test/

```

	testovací projekty
	zdrojové projekty

Každý zdrojový projekt, může být buď knihovnou nebo aplikcí.
Knihovna může být zkompilována jako statická nebo dynamická knihovna.
Dvě knihovny mohou závise jedna na druhé.
Výsledná aplikace je v adresáři app/

QtCreator `.pro` soubor:

```
TEMPLATE = subdirs


```


# Jak integrovat GoogleTest

Stáhneme si Google test (gtest)

Zkompilujeme gtest jako statickou knihovnu:
Kompilace musí proběhnout se stejným kompilátorem s jakým kompilujeme knihovny které tesrtujeme.
Visual Studio:
QtCreator:



Pokud máme projekt postavený na QMake postupujeme takto:

# Kompilace GoogleTest/GoogleMock (Windows)

Oba projekty naštěstí obsahují `.sln` soubor, takže stačí otevřít příslušné
soubory v Visual Studiu. (Případně zavolat MSBuild -- ukážeme si také toto?)

googletest/

googlemock/

### RTFM https://github.com/google/googletest/blob/master/googletest/README.md

Googletest adresář obsahuje trochu postarší `.sln` ... to ale nevadí, při jeho otevření
nám VS nabídne one-way upgrade, ketré využijeme.

Zajímá nás jen projek gtest_main (se závislotí gtest viz references)
gmock_test a gtest_test jsou pouze tyesty k samotným knihovnám -- a men se je nepodařilo sestavit, ale ani je nepotřebujeme.

GoogleTest i GoogleMock budeme kompilovat jako statciké knihovny
pro 64bit a na windows s flagem /MD (Multi-Threaded DLL)

	C/C++ -> Code Generation -> Runtime Library: Multi-threaded DLL (/MD)


Stáhnem celý obsah repozitáře: https://github.com/google/googletest 
Uvnitř se nachází jak GoogleTest (GTest) tak GoogleMock (GMock).


****
InMemoryRepository ukládá respondenty v std::map
jako klíč bereme ID a jako hodnotu referenci na respondenta.


Program může být buď aplikací nebo knihovnou.
V prvním případě musí obsahovat metodz main ... v druhém případě ji neobsahuje

Knihovna může mít závislost na jiné knihovně (1:N).
Pokud knihovna A závisí na knihovně B a naopak, říkáme tomu závislost a to není dobré.
Pokud si nakreslíme graf yívislostí meyi knihovnami, pak bychom neměli vidět czklus.

Aplikace nikdy nemůže mít závislost na jiné aplikaci, ale stejně jako knihvna může mít závislosti na knihovnách.

Každý modul má takovou adresářovou strukturu:

```
Makefile
bin/
inc/
src/
	Makefile
test/
	Makefile
```

3 x Makefile: v kořenovém adresáři, dále v adresáři `src` a nakonec v adresáři `test`.

vs

1 x Makefile
Pokud mu předáme parametr `test`, pak sestaví knihovnu a sestaví testy...


QMake

1. Struktura projektu

Projekt `library.` obsahuje podprojekty `src.pro` a  `test.pro`.

```
LIBRARY/
	library.pro
	inc/
	src/


		src.pro
	test/
		test.pro
```

2. Struktura projektu

Projekt `library.pro` obsahuje podmíněnou kompilaci pro zdrojový projekt a testovací projekt.

```
LIBRARY/
	library.pro
	inc/
	src/
	test/
```


bin
obj
inc
lib
src


1.A.
Pokud máme zdrojový a testovací projekt, jedna z možností je v testovacím
projektu vložit všechny potřebné cpp a h soubory ze zdrojového projektu.
Tím pádem musíme vždy vkládat informace dvkrát, naproti tomu nemusíme
linkovat výslednou knihovnu s testy a každá kompilace testovacího projektu
pracuje s aktuálními soubory...

1.B
Druhá možnost je při kompilaci testovacího soubory vždy přilinkovat i 
knihovnu, tzn. že před každou kompilací musíme také zkompilovat projekt!
To se dá zajisti zavislostí testovacího projektu na zdrojovém!

Různé špeky:
V projektu s testem:
#CONFIG  += console # POZOR pokud zapneme, jsou testy spo3t2ny v extern9 konzoli
# naopak při -= console se neslinkuje WinMai


QMAKE
DESTDIR říká, kam bude umístěn cíl `TARGET` ať již je to knihovna nebo spustitelný soubor.

Nastavení proměnné prostředí pro GTestDIR???

???
QMAKE_POST_LINK = copy $$OUT_PWD\debug\*.lib  ..\my-lib

Výsledný spustitelný test máme umístěn v adresáři test\bin\debug\domain_test.exe
Ten spustí všechny testy ... můžeme si například prohlédnou t´které test y obsahuje
	
	test\bin\debug\domain_test.exe --gtest_list_tests

Spustit konkrétní jeden test

	???






///////////////////////////////////////////////////////////////////////////////
POZNÁMKY
///////////////////////////////////////////////////////////////////////////////
MSVC++ kompilátor obsahuje dva zajímavé přepínače (flags)

/MD
/MT

V prvním případě linkujeme dynamicky oproti C++ runtime a v druhém případě staticky.

V prvnímk případě jsem tedy závislý, že runtime DLL musí být na stroji přítomno.

V druhém případě je to naopak, runtime je přilinkován spolu s aplikací.

Výhody:

nevýhody:



jak zjistíme typ prměnné v c++

#include <typeinfo>
std::cout << typeid(a).name() << '\n';

    
Try:

#include <typeinfo>

// …
std::cout << typeid(a).name() << '\n';
You might have to activate RTTI in your compiler options for this to work. Additionally, the output of this depends on the compiler. It might be a raw type name or a name mangling symbol or anything in between.

c++11
decltype(x)
http://stackoverflow.com/a/20170989/2490538


Poznámky ke Qt a SQL

V Qt používáme pro připojení k databázi třídu `QSqlDatabase`.
Taktéž budeme potřebovat ovladače pro náš databázový server.

Připojení:

Model a napojení na widget




Ovladače 



Nestatické tovární metody, které vytvářejí vytvářejí novou instanci s njějakým pozměněným atributem ze stávající pojmenováváme např`withChangedFirstName`.

Statické tovární metody, ketré vytvářejí zcela novou instaci pojmenováváme 
např. `create*`



