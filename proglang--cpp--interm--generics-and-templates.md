extends: default.liquid

title: C++ a generické programování pomocí šablon (1. část)
date: 24 December 2016 21:59:00 +0200
tags: C++, generics, templates
lang: cs
---

Tento článek je úvodem do šablon a praktickými poznámkami, který se snaží podat odpověď na otázky:

+ Jak zapsat funkci tak, aby mohla přijmout parametry jakéhokoliv typu?
+ Jak zapsat funkci tak, aby mohla přijmout parametry jakéhokoliv typu, splňující však nějakou podmínku?

> Generické programování / Generický program ... doplnit

Jestli je na C++ něco obtížného, pak je to právě generické programování a to 
ne kvůli tomu, že by bylo obtížné čeho pomocí něho chceme dosáhnout, ale jakým způsobem
se v C++ toho dosahuje. 

C++ edfinuje tzv. šablony (*templates*), které mohou být definovány pouze v hlavičkovém
souboru. Rozlišujem šablony šablony funkcí (*function templates*) a šablony tříd (*class templates*). 

Už z názvuje je jasné, že šablony funkcí slouží pro definování samotných generických funkcí a šablony tříd pro definování generických tříd, a tedy i generických členských funkcí nebo-li metod.

## Generické typy v podobných imperativních jazycích

### C\#

```csharp
class C<T> : where T : Comparable 
{
    public 
}
```

Začneme jednoduchým požadavkem na funkci. Chceme takovou funkci, která vrací
např. dvojnásobek svého argumentu.

### Java

Jazyk Java tomu říká *bounded type parameters* viz https://docs.oracle.com/javase/tutorial/java/generics/bounded.html a rozeznává pouze dva druhy omezení. První omezení je že typ rozšiřuje nějakou 
třídu nebo implementuje rozhraní. Oboje je vyjádřeno pomocí klauzule `extends`.

např. `public <T extends Number> void inspect(T t) { ... }`

Pokud požadujem aby T rezšiřoval nebo dědil z více rozhraní, respektive tříd, zapisujeme to pomocí 
`&` takto.

    public <T extends C1 & C2 & I1 & I2> void method(T t) { ... }    

Pozor záleží na pořadí, třídy uvádíme první!

## Šablony funkcí (function templates)

Kdy je funkce generická?
Jaká je výhoda napsat funkci jako šablonu namísto ručního overloadingu?

Generická funkce přijímající generický parametr.

```cpp    
template<typename T>
T generic_add(T x, T y)
{   
    return x + y;   
}
```

Jaký je rozdíl mezi `template<class T>` a `template<typename T>`?

```cpp    
template<typename T>
T generic_add(T x, T y)
{
    T result;
    result = x + y;
    return result; 
}
```

- T musí mít výchozí konstruktor, protože `T result`;
- T musí podporovat operátor `+` , protože `x + y`;
- T musí mít přístupný copy/move konstruktor, protože `return result`;

## Zdroje

- http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part
- http://accu.org/index.php/journals/272
- http://cpptruths.blogspot.cz/2015/11/covariance-and-contravariance-in-c.html
