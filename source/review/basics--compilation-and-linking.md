# Úvod

V tomto krátkém seriálu si vysvětlíme proces při kterém ze zdrojových souborů, vznikne výsledný spustitelný program. Začneme nejjednoduší moznou variantou, kdy s jedením zdrojovým souborem. Na tomto příkladu si ukážeme a popíšeme všechny kroky, které kompilátor provádí. V dalších částech si ukážeme jak používat knihovny třetích stran a rozdíl mezi statickou a dynamickou knihovnou. Nakonec si jednu malou knihovnu sami napíšememe vytvoříme jak statickou, tak dynamickou verzi této knihovny. Příklady se pokusíme zpracovat na Linuxu i Windows. Pro práci s příklady potřebujeme nástroje, jejiž nastavení a instalace je popsána [zde](---) (todo).

# Sestavení programu
 
_PROCESSOR, COMPILER, ASSEMBLER, LINKER, LOADER_

Procesu transformace zdrojových souborů do výsledného spustitelného programu se říká sestavení (*building*). Zdrojovými soubory s ohledem na jazky C a C++ chápeme hlavičkové a implementační soubory (přípona `.h/hpp` vs `.c/.cpp`)
Cesta od zdrojového kódu ke spustitelnému programu může často vypadat jako jeden proces, skláda se však z několika kroků. I když často mluvíme pro jednoduchost o kompilaci programu, je právě samotná kompilace jen jedním z kroků. Vysvětlíme si tedy stručně všechny kroky tohoto procesu, které jsou nutné pro vytvoření spustitelného programu.

Jednotlivé kroky procesu sestavení:

1. **preprocesor**
2. **kompiler**
3. **assembler**
4. **linker**

Další kroky po slinkování (po kroku 4):
- loader (Pozn)

Předpokládejme, že máme zdrojový soubor `program.c` a chceme vytvořit spustitelný program `program` (případně `program.exe` na Windows :)

V tom případě, použijeme příkaz `gcc program.c -o program`

## 1. Preprocessing

Preprocesor přichází na řadu jako první. Stará se o zpracování tzv. direktiv preprocesoru.

V C a C++ můžeme používat např. tyto direktivy. `#if` `#ifdef`, `#ifndef`, `#define`, `#include` `##` `#error`.

Např. při zpracování direktiv `#include` se preprocesor stará o vložení požadovaných hlavčikových souborů (přípona `.h`), které  obsahují deklarace funkcí, kostant atd., které náš program používá.

Dále se stará o expanzi maker a substituci maker a konstan, které jsou definvány pomocí ditektuvy `#define`  často zapsaných právě v hlavičkových souborech anebo v samotných implementačních souborech (přípona `.c`).

Dále jsou samozřejmě zpracovány ostní direktuvy jako #if` `#ifdef`, `#ifndef`

Ukažmě si jak vypadá soubor po zpracování preprocesorem. Kompilátor totiž umožňuje proces pozastavit po tété pevní fázi. Většina kompilátorů používá direktivu `-E` pro přesměřování výsledku na standardní výstup.

    gcc -E main.c

Pokud si chceme prohlédnou výstup v textovém editoru můžeme přesměřovat výstup do souboru (proč mu dáváme příponu `.i` se dozvíme dále).

    gcc -E main.c > main.i`

Výsledkem bude soubor s názvem `main.i` obsahující výsledek zpracování preprocerorem.

Výsledný soubor i pro takto jednoduchý soubor je docela dlouhý co do počtu řádek. Na začátek našeho programu totiž byla vložen obsah hlavičkového souboru ve kterém samotném jsou vloženy další potřebné hlavičkové soubory, definice tipů a došlo k rozvinutí makrer a nahrazení konstant -- což může platiti i pro tyto do něj vložené hlav. soub.

Na konci tohoto souboru `main.i` je samotná funkce `main`. Můžeme si všimnout, že námi definovaná kostanta ve funkci `printf` je již nahrazena odpovídající číselnou hodnotou, jak jsem již poznamenal.

```
int main()
{
    printf("%d\n", 7);
    return 0;
}
```

???Soubor `main.i` a obcně další soubory, pokud by náš program byl složen z více zdrohových souborů je vstupem pro další krok procesu.

It also adds some special markers that tell the compiler where each line came from so that it can use those to produce sensible error messages.

The preprocessor works on a stream of preprocessing tokens. Macro substitution is defined as replacing tokens with other tokens (the operator ## enables merging two tokens when it make sense).

Ještě nutno poznamenat, že preprocesor je samotatný program, který je pravděpodobně již v cestě, takže ho můžeme zavolat samostatně jako cpp (C PreProcessor -- neplést s C++).

    cpp main.c

respektive, pokud chceme výstyp přesměřovat do souboru:

    cpp main.c > main.i

Obecně je výsledkem preprocesoru prouy bunárních dat (binary stream), který je vstypem pro parser kompulátoru -- textový výstyp vsniká tedy jen pokud ho explicitně vyvoláme vyše zmíněným postupem.

**Poznámka pro uživatele Windows:**
> cl.exe, the command line interface to Microsoft Visual C++, has three different options for outputting the preprocessed file (hence the inconsistency in the previous responses about Visual C++):
/E: preprocess to stdout (similar to GCC's -E option)
/P: preprocess to file
/EP: preprocess to stdout without #line directives

## 2. Compilation

Kompilace je prováděna na každém výstypu preporcesoru
volán assembler
Kompilátor parsuje zdrohový kód a profukuje obejktové soubory.

Direktiva kompilátoru `-c` zamezí následnému slinkování, tzn., výsledkem budou objektové soubory (.o nebo .obj).

    gcc -c main.c -o main

    gcc [options] source_1 [source_2 ... source_N]

## 3. Assembly

## 4. Linking

## Symbol table

## Další otázky

- **Co je to transtaltion unit?**
- **Vytváření spustitelného programu není to samé co kompilace!**
- **Kdy jsou prováděny optimalizace?**
- **Co je to ABI (Application Binary Interface)**

Něco o sdílených knihovnách v linuxu:
/usr/lib
/usr/local/lib

mpilace s knihovanmi

V unixovém systému jako Debian jsou knihovny instalovány na určené lokace. Pokud chce me kompilovat nějaký program, tak za předpokladu, že máme knihovnu správně naunstalovanou můžeme použít package-congig

Programování s knihovnou XCB

máme naistalovanou knihovnu XCB a knohovnu X11

kompilace příkladů

gcc source.c -o ouput -l X11 -l xcb -std=c11


Proč někdy kompilace selže při záměně pořadí linkovaných knihoven?
Protože knihovny zavísí jedna na druhé -- nějakým způsobem


statické vs dynamické knihovny
Jaký je rozdíl mezi statickou a dynamickou knihovnou?
.so/.a vs .dll/.lib