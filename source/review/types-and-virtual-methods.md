extends: default.liquid
title: C++ Virtual Methods
date: 20 November 2016 22:24:00 -0500
---

1) Static

2) Dynamic 

Pokud překrýváme (override) virtuální funkci z rodičovské typu v potomkovi,
pak je `virtual` nepovinné a přesto je funkce virtuální:

```cpp
struct Parent { 
    virtual void f() { 
        //  todo
    } 
} 

    struct Child_A {
        void f() {
            // todo
        }
    }
```

Od verze C++11 můžeme použít označení `override`, což nám pohlídá velmi častou chybu!

    struct Child_B : Parent {
        void f() override { // << ERROR
            //
        }
    }

Třída uvedená výše je označena jako `override`, ale kompilace skončí s chybou.
    
    'virtual void Child_B::vf()' marked override, but does not override

Proč? Protože funkce v rodičovském typu je označnena jako `const` avšak funkce
v podtypu nikoliv. Pokud vynecháme označení `override` 

## VIRTUÁLNÍ METODY 

V C++ jsou ukazatele na metody v samostatné tabulce mimo samotný objekt, jde 
o tzv. virtuální tabulka metod aka *v-table*.

```c++
struct Parent { 
    virtual void f() const {} 
};

struct Child1 { 
    virtual void f() const override {
        //
    } 
};

struct Child2 { 
    virtual void f() const override {
        //
    }
};

struct Child2 { 
    virtual void f() const override {
        //
    }
};

PRAVIDLA
Pokud metoda nemění vnitřní stav objektu, pak ji označ klíčovým slovem `const`.
Pokud překrýváme metodu rodiče, pak označ metodu potomka klíčovým slovem `override`. 


```

```
            [vtable|f1|f2|f3]
            ^ ^ ^
            | | |
[obj1] -----+ | |
[obj2]--------+ |
[obj3]----------+
```
(+) Je  flexibilnější než *static binding*.
(+) Je efektivnější než např. *method dispatching*, jen konstantní koefocient
    zpomalení.
(-) Často nemožná optimalizace pomocí `inline`.
