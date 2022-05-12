---
title: Pointers
---

# Práce s pamětí a ukazateli

## Ukazatel na funkci

    int (*fun_p)(int a, int b);

Tomuto ukazateli vyhovují všechny tyto funkce

    int add(int a, int b) { return a + b; };
    int sub(int a, int b) { return a - b; };

    fun_p = &add; // nebo fun_p = add;

nebo 

    fun_p = &sub; // nebo fun_p = sub;

    int result = (*add)(1, 2)  // explicitní dereference
    int result = add(1, 2);    // implicitní dereference       

## Ukazatel na proměnou

Ukazatel (pointer) je jedním ze základních datových typů jazyka C i C++
a také jedním z nejvíce nepochopených. Vysvětlit co je ukazatel není
nijak obtížné, to co je je obtížné je neomylná práce s nimi, a proto
jsou zdrojem mnoha velmi zalůdných chyb, které se těžko odhalují a
nastávají většinou až za běhu programu (*runtime error*), což jsou
ty vůbec nejhorší chyby.

To je také důvod pro některé jazyky práci s ukazateli vůbec nepovolují a
nechávají tyto "hrátky" s pamětí na překladači respektive interpreteru
jazyka (např. Java, Python). Odpověď, proč se tedy ukazateli vůbec
zabývat je skryta v předchozí větě. Umožňůjí přímo pracovat s
pamětí a lze tedy pomocí nich vytvářet mnohem efektivnější programy.

## Paměť

Pro běh programu (procesu) je nutné vyčlenit blok paměti. Velikost této
paměti, která může být přidělena na 32-bitové architektuře procesoru
je 4GB (poznamenám jen, že tato omezující hodnota nesouvisí s tím, kolik
operační paměti mámem vloženo ale právě s architekturou procesoru --
to je detail se kterým se teď nemusíme zabývat ale vychází to z tohoto
přepočtu: 32bitů = 2^32 = 4GB).

Takovou pamět si představíme jako pás buněk, každá z nich má
přidělenou unkátní adresu -- adresa s nejmenší hodnotou na obrázku
vlevo a stoupá  směrem doprava. Písmeno h na konci adresy označuje,
že adresa je zapsána v hexadecimální tvaru.

    počáteční buňka 00000000h           poslední buňka FFFFFFFFh |
    | +----+----+----+----+----+----+----+----+ |    |    |    |    |    |
    |    |    | +----+----+----+----+----+----+----+----+

Definice: Ukazatel je celočíselná proměná ve které může být uložena
adresa proměnné jakéhokoliv povoleného typu.

Vytvoříme jednu proměnnou typu `int` a ukazatel na tuto proměnnou pomocí
znaku `*`.

    int num = 10; *ptr = num;

Proměnná `ptr` teď jako svoji hodnotu uchovává adresu proměnné `num`;

    printf("hodnota num: %d", num); printf("hodnota ptr: %d", ptr);

## Kolik zabírají základní datové typy v paměti?

Některé datové typy můžeme označit jako znaménkové (signed) nebo
neznaménkové (unsigned).  V paměti sice obě varianty zabírají stejné
místo, označením typu jako unsigned říkáme, že do proměnné lze uložit
pouze nazápornou hodnotu. Typy jsou implicitně označené jako znaménkové
(signed), proto např. píšeme zkráceně int místo signed int, což je
to samé.

```
+--------------------------------+ |char, unsigned char             |
+--------------------------------+ |short int, short                |
|unsigned short int, unsigned int| +--------------------------------+
|signed int, int                 | |unsigned int, usigned           |
+--------------------------------+ |long int, long                  |
|unsigned long int, unsigned long| +--------------------------------+ |long
long                       | +--------------------------------+
```
## Uložení jednorozměrného pole v paměti

    int a[5] = {1, 2, 3, 4, 5}; for(int i = 0; i < 5; i++) {
        printf(&a[i]);
    }

obr.: Obsazení paměti prvky jednorozměrného pole.

     a[0]  a[1]  a[2]  a[3]  a[4]
    +-----+-----+-----+-----+-----+ |  |  |  |  |  |  |  |  |  |  |
    +-----+-----+-----+-----+-----+

## Uložení dvojrozměrné pole v paměti

obr.: Obsazení paměti prvky dvojrozměrného pole.

    int a[3][2]

     a[0][0] a[0][1] a[1][0] a[1][1] a[2][0] a[2][1]
    +-------+-------+-------+-------+-------+-------+ |   |   |   |   |   |
    |   |   |   |   |   |   | +-------+-------+------+--------+------+--------+

## Uložení struktury v paměti

## Zásobník

implementace pomocí pole nebo spojového seznamu

Struktury

Struktury patří mezi složené datové typy, to znamená, jednu nebo více
položek, které mohou být nejrůznějšího typu a tedy  i typu struktury

Definice komplexního čísla jako struktury s položkami pro reálnou a
imaginární část.

struct Complex; {
    double re; double im;
}

Definujeme si funkci pro sčítání komplexnách čísel.

Complex add(Complex a, Complex b) {

};

Complex operator +

# Ukazatel na funkci
Opakování: ukazatel je entita, která uchovává adresu jiné entity.
Ukazatel na funkci tedy uchovává adresu funkce, tedy adresu, na kterou se v paměti realizuje skok.

Co je callback?

Callback není ukazatel na funkci! I když v C je takto (a jedině takto) realizován (ale např. v C++ existuje více způsobů jak callback realizovat)

Callback je funkce, předaná jiné funcki


http://ccodearchive.net/info/typesafe_cb.html
