## Semigroup



## Monoid


Příklad monoidu v C++ zpracovaný pomocí šablony s paramatrem `T`, který představuje
 typ prvku množiny a paramtr `O` představuje binární operaci.

```
namespace algebra {

    template<typename T>
    struct Semigroup {};

    template<typename T, T O(const T&, const T&)>
    struct Monoid {
        
        typedef T type;

        static T combine(const T& a, const T& b) {
            return F(a, b);
        }

        static const T zero;

        // static Monoid<T zero, SemiGroup<T>> of() { }
    }
```

Jak ji můžeme využít v programování? Jistě se shodneme na tom, že abstrakce je dobrá věc.
Pokud nějaký jsme nějaký objekt schopni identifikovat jako monoid má to několik výhod.
Představme si, že děláme analýzu dat a každý výpočetní proces běží odděleně např. na různých procesorech nebo dokonce strojích. Jak získáme konečný výsledek? Pokud jde o komutativní monoid, pak víme, že můžeme jednoduše sečíst
výsledné hodnoty a to v jakémkoliv pořadí (na uzávorkování ani pořadí nezáleží). Výpočty prakticky skončí v různých 
časech a mi jen postupně sbíráme výsledné hodnoty.



(a + b) + c == a + (b + c)
0 + a == a + 0 + == a
(a * b) * c == a * (b * c)
1 * a == a * 1 == a


K čemu to ale vše je?






Mějme prvek typu T, binární operaci O a neutrální prvke N. 


## Zdroje

http://mathworld.wolfram.com/Monoid.html

