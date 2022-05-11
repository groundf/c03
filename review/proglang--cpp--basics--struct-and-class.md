---
extends: default.liquid
title: C++ struktura a třída
date: 20 November 2016 22:24:00 -0500
tags: C++, basics
lang: cs
---

Na jednoduchém bodu si můžeme ukázat několik základních konceptů C++, pro
práci se strukturami a třídami.

Pro jednoduché demonstrační příklady si vytvoříme bod jako strukturu se dvěma
atributy x, y, které reprezentují jeho souřadnice v euklidovském prostoru.

```cpp
struct Point { 
  double x, y; 
};
```

Podobně bychom vytvářeli i strukturu v C, ale struktura v C++ se sémanticky
liší od struktury v C v několika ohledech (porovnání s C na konci článku). 

Struktura v C++ je vlastně třída, jejíž všechny členské proměnné (případně
metody) jsou veřejné, tedy označené modifikátorem `public`. Následující 
deklarace je tedy stejná jako první.

```cpp
class Point {
  public: double x, y;
}
```

Případně tato verze, kdy členy deklarujeme jako soukromé, jsou stejné.

```cpp
class Point {           struct Point {
  double x, y;            private: double x, y;
}                       } 
```

Dále budeme pro jednoduchost pracovat s první uvedenou strukturou a budeme 
se ptát, co se děje na pozadí, když kompilátor narazí na takovouto deklaraci
struktury.

V tomto případě za nás kompilátor měl vytvořit následující věci:

### Default parameterless constructor

> **Výchozí konstruktor** je takový konstruktor, který nepřebírá žádné parametry, nebo pokud má nějaké parametry, pak všechny mají nastaveny výchozí hodnoty.

... abychom mohli struktur vytořit i bez inicializace.

Následující deklarace vytvoří instanci, ale bez inicializace členských
proměnných, tzn., že hodnota `x` a `y` může být jakákoliv!

    Point point;  // Proměnné x a y jsou neinicializované!

V lepším případě si můžeme vynutit inicializaci členských proměnných na nulové hodnoty.
    
    Point point = {} // Hodnoty x a y jsou inicializované na hodnotu 0.
nebo 
    Point point{};

### Copy constructor

abychom mohli vytvořit instanci, z jiné existující instance.

    Point p1{};   
    Point p2(p1);

### Move constructor

abychom...

Kompilátor generuje MOVE CONTRUCKTOR pokud,


Rozdíl mezi strukturou v C a C++.
V C++ může mít struktura členské funkce, zatímto v C je to realizovatelné
jena jako ukazatele na funckce.


//// přebrat

# Struktura v C a C++.

Struktura je jednou je jedním ze základních složených typů v C i C++ (*compunded type*).
Protože v praxi se často prolíná C i C++ kód, je dobré vědět jaký je rozdíl mezi 
strukturou v jazku C a C++. Pojďme si to připomenout.
    
V C++ se nerozlišuje mezi strukturou a třídou, ty se však liší ve dvou ohledech.
Struktura má ve výchozím stavu všechny své členy veřejné, zatímco třída je má 
naopak soukromé, pokud nedefunujem jinak. 

V C může struktura obsahovat jen data, nikoliv funkce. Obejít to lze pouze tak, že
jeden z datových členů je ukazatelem na funkci.

V C++ může struktura obsahovat jak data, tak funkce (stejně jako třída).

V C je klíčové slovo struct součástí názvu typu, musíme ho prot uvádět při vytváření 
nového typu. Obejít to lze tak, že uděláme alias pomocí `typedef` (někdo to nedoporučuje kvůli čitelnosti).


__Q__ Může mít struktura v C statický člen?

__A__ Ne, v *C* není pro struktutu definován statický člen. Následující kód je 
neplatnou definici struktury. 
    
    struct C {
        static char c;
    }

__Q__ Může mít struktura v C++ statický člen?

__A__ Ano, v *C++* může struktura obsahovat satický člen, pukud ovšem nejde
o lokální strukturu. Následující kód je platnou definicí struktury.
    
    struct S {
        static char c;
    }

Lokální struktura (nebo třída) je taková, ketrá je definovaná uvnitř nějaké 
funkce nebo jiné struktury. Následují kód není platný nai v C++.

    int main() {

    }

Pokud je odpověď ano, co to znamená?