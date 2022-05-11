## C++ 11  R-Value reference

V C++ můžeme parametr funkci předat jako hodnotu nebo referenci.

Pokud funkci předáváme parametr jako hodnotu, pak je vytvořena její kopie se 
kterou se pracuje jen uvnitř této funkce. Tomuto způsobu volání funkce se též 
říká volání hodnotou (*call-by-value*).
    
Definujeme-li strukturu `S` jako `struct S { };` pak funkce, které předáváme
tuto strikturu jako hodnotu by mohla vypadat takto

    void fn (S s) {
        // do something
    };

Funkci můžeme pak volat respektive parametr můžeme předat dvěma způsoby.
    
V prvním případě exsituje-li proměnná typu S;
    S x;

Pak můžeme ji mlžeme přímo vložit jako argument.

    fn(s);

Protože v C++ je struktur třídou můžeme jivytvořit přímo při vkládání argumentu.

    fn(S());



