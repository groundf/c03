extends: default.liquid

title: C++ a dynamická alokace pole
date: 29 December 2016 14:03:00
lang: cs
tags: C++, memory
---

Pole prvků se v C++ dá alokovat několika způsoby, podle toho, jak moc v minulosti chceme nebo musíme zůstávat. Ukážeme obě možnosti chronologicky, tedy první způsob před a po verzi C++11. Musíme poznamenat, že zde používáme pole, tak jak ho známe z jazyka C nebo-li [*C-style array*](http://en.cppreference.com/w/cpp/language/array). Protože v C++11 máme opět možnost použít kontejner [`std::array`](http://en.cppreference.com/w/cpp/container/array).

## Operátor `new []`

V dneš již klasickém C++ z roku 2003 a dříve s pamět pro pole na haldě alokovala pomocí operátoru `new`. V  následujícím příkladu je `T` generický typ, představte si pro jednoduchost třeba `int`.

```c++
T * array = new T[size];
delete [] array           // NUTNÉ!
```

Pokud bychom takové pole měli jako členskou proměnnou (atribut) třídy, pak alokaci provedem při konstrukci objekty, tedy v konstruktoru a dealokaci paměti provedeme v destruktoru.

```c++ 
template <typename T>
struct C {
    // Construcktor
    C(std::size_t size) 
        : array(new T[size]) 
    {}
    
    // Destruckror
    ~C()
    {
        delete [] array;
    }

    T * array;
};
```

## Unique pointer a automatická zpráva paměti

```c++
std::unique_ptr<T[]> array(new T[size]);
```

```c++
auto array = std::make_unique<T[]>(size)
```

