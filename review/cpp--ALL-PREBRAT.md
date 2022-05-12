extends: default.liquid
title: C++ toto se musí přebrat 2!
date: 1 January 2017 20:30:00 +0200
lang: cs
tags: C++
---

# Poznámky k programování v C++

Operační systémy splňující POSIX normu, jkao je např Linux a jiné unixové 
systémy nedělají rozdíl mezi binárním a texttovým souborem. 
Funkce pro manipulaci se soubory se nacházejí v hlavičkovém souboru 
`fopen() fread() freopen() fclose()`.

---

## Obsah

+ [Třídy a objekty](#)
+ [Zapouzdření](#)
+ [Dědičnost](#)
+ [Polymorfismus](#)
+ [Abstraktní třída](#)
+ [Rozhraní](#)

---

## Cyklus

### Nekonečný cyklus

```
for(;;) { }

	while(1) { }

	while(true) { }
	//V C musíme vložit hlavičkový soubor `stdbool.h`
```


# Proměnné, konstanty a základní datové typy

**Celá čísla**

short int (short)<br>
int <br>
long (long int)<br>

    #include <iostream>

    int main()
    {
      int a = 1;
      int b = 2;
      int c = a + b;

      std::cout << c << std::endl;

      return 0;
    }

Pro stručnější vyjádření, můžeme na začátku programu deklarovat použití jmeného
prostoru (*namespace*) do kterého patří i funkce `cout` a `endl`, pak nemusíme
jmenný prostor uvádět pomocí operátoru `::`

    #include <iostream>

    using namespace std;
    int main()
    {
      int a = 1;
      int b = 2;
      int c = a + b;

      cout << c << endl;

      return 0;
    }

**Reálná čísla**, s desetinnou částí

**znaky**

### globální a lokální proměnná, obor platnosti

# Složené datové typy: struktura, unie, třída

- Jak se vytváří struktura?
- Jak se vytváří a jaká má omezení *anonymní struktura*?
- Jak se přistupuje ke členům struktury?
- Jak se vyrváří a kčemu se využívý typ unie `union`?

# Třída, Objekt

---

Návrh tříd v C++ je obdobný jako v jazyce Java, jsou zde jen rozdíly jejich
programové konstrukce. Předně narozdíl od Javy je často třída rozdělena do dvou
 souborů &ndash; <em>hlavičkového</em> souboru, kde jsou uvedeny deklarace
 členských proměnných a funkcí (metod) třídy s příponou <code>.h</code>
 a soubor, kde jsou ve kterém jsou metody třídy implementovány, ten má příponu
  <code>.cpp</code>

## Konstruktor a Destruktor

Pro vytvoření instance třídy se tradičně používá funkce, která vytvoří objekt
ze zvolené třídy neboli <em>konstruktor</em>. Pro uvolnění paměti již
nepotřebém objektu se využívá <em>destruktor</em>, to je významný rozdíl oproti
 zazuku Java, kde ve většině případů za más tutuo prácí udělá <em>garbagge
 collector</em>.

### Konstruktor

+ Je pojmenován stejně jako třída.
+ Nemá návratovou hodnotu (ani typ <code>void</code>), ale můžeme definovat
vstupní parametry.
+ Kostruktor může být v rámci jedné třídy více, ale musí se lišit počtem nebo
typem parametrů.

### Destruktor

+ Je pojmenován stejně jako třída a navíc ho předchází znak `~`.
+ Nemá návratovou hodnotu (ani typ <code>void</code>) ani mu nepředáváme žádné
parametry.
+ Destruktor může být v rámci jedné třídy pouze jeden.


### Dědičnost

## Použití externí knihovny ve Visual Studio 2010 Express Ed.


## Rozdělení programový knihoven

+ statická knihovna (angl. **static linking library**)
+ dynamická knihovna (angl. **dynamic linking library**)
+ sdílená knihovna (angl.	 **shared library**)
+ nesdílená knihovna

### Statická knihovna
Statická knihovna tvoří s výsledným programem jeden celek.
Statická knihovna obvykle používá příponu `.dll `(Windows) nebo `.a`, `.lib` (Linux).

### Dynamická knihovna

Narozdíl od statické knihovny netvoří dynamická knihovna s výsledným programem
 jeden celek, ale program si při překladu vytvoří odkazy na volané funkce
 z dynamické knihovny. Dynamické knihovny pak ale musí být stále dostupné pro
 správný běh programu. Proto programy, které využívají dynamických knihoven
 nějakého systému, provádějí instalaci, při které se vytvoří vazba na tyto
 knihovny. Další možností je, že jsou knihovny distribuovány spolu s programem
 ve nějaké společné složec (adresáři).

Dynamická knihovna obvykle používá příponu `.dll` (Windows) nebo `.o`, `.so` (Unix/Linux).

### Sdílená knihovna

## Reference:
http://cs.wikipedia.org/wiki/Knihovna_(programov%C3%A1n%C3%AD)

# Funkce s proměnným počtem parametrů

Funkce s proměnným počtem parametrů neboli *variadické funkce*

	int Sum(int num, ...)
	{
		for (int i = 0; i < n; i++)
		{
			sum += va_list()
		}

		return sum;
	}


# Abstraktní třída, čistě abstraktní třída (rozhraní)

Abstraktní třída obsahuje jednu nebo více čistě virtuálních (abstraktních)
metod. Ty musí být implementovány ve třídě, která rozšiřuje abstraktní třídu.

Pojem čistě abstraktní třída označuje třídu, která obsahuje jen čistě virtuální
metody a neobsahuje žádné členské proměnné -- to v podstatě odpovídá tzv.
rozhraní, tak jak ho známe např. z jazyka Java.

Abstraktní třída nemůže být přímo instanciována, protože obsahuje alespoň jednu
abstraktní metodu, která nemá tělo -- je tedy navržena jako bázová třída.

---

# Generika

---

# Templates, STL (Standard Template Library)

---

Typová parametrizace neboli šablony (*templates*). Možnost znovupoužití
zdrojového kódu (podobně jako dědičnost a kompozice). Namísto vícenásobné
deklarace (přetížení) stejné funkce pro různé datové typy, vytvoříme šablonu,
 podle níž kompilátor v době překladu odvodí potřebné datové typy parametrů,
 případně i navratovou hodnotu funkce.

Vlastnosti šablon:

+ jsou instanciovány v době překladu (*compile time*)
+ jsou typově bezpečné
+ umožnují uživatelsky definovanou specializaci
+ umožnují beztypové parametry
+ používají *lazy structural constraints*
+podmorují *mixins*

Šablony jsou používány v době překladu:

Rozeznáváme dva typy šablon:

+ šablony funkcí (*function templates*)
+ šablony tříd (*class templates*)

[http://msdn.microsoft.com/en-us/library/sbh15dya.aspx](http://msdn.microsoft.com/en-us/library/sbh15dya.aspx)
[http://msdn.microsoft.com/en-us/library/sbh15dya.aspx](http://msdn.microsoft.com/en-us/library/sbh15dya.aspx)

## Syntax

Preferuj zápis (2) před (1).
```
template <class T>
template <typename T>
``

Místo neustálého přetěžování funkce, pro jiné typy parametrů:
Kdy použít přetěžování a kdy šablonu?
```
void PrintData(int data)
{
	std::cout << data << std::endl;
}

void PrintData(double data)
{
	std::cout << data << std::endl;
}
```

## Šablony funkcí (*function templates*)

Šablonové funkce jsou parametrizované funkce, jde tedy o rodinu funkcí, které
se liší jen v typu parametrů a případně typu návratové hodnoty. To zajištuje,
že stejnou funkci můžeme volat pokaždé s jiným datovým typem jejího argumentu.
---
```
template < comma-separated-list-of-parameters >

///
template <typename T>
inline T const& MaxFromTwo(T const& a, T const& b)
{
	return a > b ? a : b;
}
///
template <typename T>
inline T const& MaxFromThree(T const& a, T const& b, T const& c)
{
	return a > b
		? (a > c ? a : c)
		: (b > c ? b : c);
}
///
template <typename T>
inline T const& MaxFromAny(T const& a, ... )
{
	return a;
}


template <class T>
void PrintTwice(T data)
{
	std::cout << data << std::endl;
}
```
Funkce přijímá  a vrací typ T, který odvodí kompilátor. U všech parametrů, pro
které je definován operátor `>` lze tuto funkci použít.

	template <class T>
	T Max(T a, T b)
	{
		return a > b ? a : b;
	}

Pro řetězce vytvoříme specializovanější šablonovou funkci:

	template <class T>
	T Max(T a, T b)
	{
		return a > b ? a : b;
	}

	char *Max(char *a, char *b)
	{
		return strncmp(a, b) > 0 ? a : b;
	}

	// AVERAGE
	template <class T>

	double Average(T arr[], int count)
	{
		T sum = T();  // sum = 0

		for (int i = 0; i < count; i++)
		{
			sum += arr[i];
		}

		return double(sum) / count;
	}

	int main()
	{
		int iArray[] = {1, 2, 3};
		float fArray[] = {1.1f, 2.2f, 3.3f};
		double dArray[] =  {1.1, 2.2, 3.3};

		std::cout << Average(iArray, 3) << std::endl;
		std::cout << Average(fArray, 3) << std::endl;
		std::cout << Average(dArray, 3) << std::endl;
	}

Zlepšení funkce `Average`:

	template <class T>
	T Average(T *arr, int count) {}

Najdi vetší číslo ze tří:

	template <typename Comparable>
	Comparable Max(Comparable a, Comparable b, Comparable c)
	{
		return (a > b)
			? ((a > c) ? a : c)
			: ((b > c) ? b : c);
	}

	int Max<>(1, 2, 3);


## Šablony třídy (*class templates*)

---

Šablony tříd jsou nejčastěji používány pro vztváření generických datových
kontejnerů např.: STL: `list<int>`, `list<string>` atd.

	/////////////////
	// MyClass.HPP //
	/////////////////

	template <typename T> class MyClass
	{
	  public:
	    MyClass();
	    ~MyClass();
	    void OneFunction();
	    T TwoFunction();

	  private:
	    int oneVar;
	    T twoVar;
	}

	/////////////////
	// MyClass.CPP //
	/////////////////

	#include<MyClass.hpp>

	template <typename T> MyClass<T>::MyClass()
	{                         // ^------------------ Musíme napsat typ!
		oneVar = 0;
	}

	template <typename T> void MyClass<T>::setTwoVar(T var)
	{
		twoVar = var;
	}

	template <typename T> T MyClass<T>::getTwoVar()
	{
		return twoVar;
	}

## Iterátory

Jde o zobecnění pojmu ukazatele.

## Odkazy

[http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part](http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part)

---

# Datové kontejnery

---

## Array `std::array`

#### Konstruktory

	std::array<int> arr = {1, 2, 3}

	std::array<int, 3> arr;
	arr = {1, 2, 3};


#### Modifikátory


 **`swap()`**

	#include<iostream>
	#include<array>

	std::array<int> A = {1, 2, 3};
	std::array<int> B = {4, 5, 6};

	A.swap(B);

	std::cout << "A: ";

	for (int &item : A)
		std::cout << ' ' << item;

	std::cout << "B: ";

	for (int &item : A)
		std::cout << ' ' << item;


**`fill()**

**`size()**

---

## Vector `std::vector`

metody, iterátory, aksesory, modifikátory
Vektor neboli dynamické pole je datový kntajner, který uchovává prvky stejného
typu a jehož velikost se může dynamicky měnit. Pokud při přidání prvku
překračujeme deklarovanou velikost vektoru, je automaticky zdvojnásobena jeho
kapacita. Přesněji řečeno se vztvoří nové pole dvojnásobné velikosti, do
kterého jsou všechny prvky přemístěny.

begin()
end()
size()		vrací aktuální velikost (počet prvků)
max_size()	vrací maximální velikost
empty()		zjistí, jestli je vektor prázdný
resize()	navíší kapacitu
[]
at()
front()
back()
push_back()
pop_back()
insert()
erase()
swap()
clear

## Dequeue `std::deque`

---

## Forward List

---

## Map `std::map`

---

## Set `std::set`

---

## Stack `std::stack`

---

##



# Použiti modifikátoru `const`

**Funkce nemůže změnit hodnotu hodnotu proměnné, kterou přebírá jako parametr(ukazatel)**

	MyFunction(const &int number) {...}


## Pojmenovaná konstanta (named constant)

"Proměnnou", kterou definujeme s modifikátorem `const` nelze již změnit jednou
přiřazenou hodnotu (neplatí to tak úplně jak si ukážeme později). Místo slova
`const` si také můžeme jednoduše myslet slovo *read-only* (porovnej s C#).
Protože hodnotu takovéto proměnné nelze již dále v programu měnit, nestačí ji
jen deklarovat, ale musíme ji přiřadit hodnotu okamžitě při deklaraci
(deklarace + inicializace = definice proměnné) -- později by se nám to již
nepovedlo.

	const int N;
	N = 10       // error: assignment of read-only variable 'M'

Všimněte si, že nezáleží na pořadí `const` a `int`, oba následující zápisy jsou
platné.

	const int N = 10;
	int const M = 20;

Jak jsem řekli, hodnotu jednou definované konstanty nelze později změnit.

	int N = 20; // CHYBA: Nelze změnit hodnotu N.

	[Poznámka] Pokud použijeme ukazatel, jde to: TODO, BUT: You should not being
    changing the const value) c++ const_cast<>

Použití `const` namísto `#define`;

## Ukazatele a `const`

viz dále oddíl [Ukazatele a modifikátor `const]

<!--
================================================================================
================================================================================
POINTERS
-->


<!--
================================================================================
================================================================================
ARRAYS
-->

# Pole

---

+ při deklaraci musíme zadat celočíselnou hodnotu větší než nula.
+ prvky pole nesmí být typu:
	+ reference
 	+ funkce
 	+ abstraktní třída
 	+ void

## Jak vytvořit jednorozměrné pole a přistupovat k jeho prvkům

### Vytvoření standardního pole

Standardním polem myslíme pole, ketré je přímo zabudované do jazyka (C, C++),
tedy nikoliv rozšíření jako `std::array` (viz dále).

Deklarace pole o velikosti tří prvků: `int arr[3]`;

Nastavení hodnot prvků pole pomocí indexu.

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

**Inicializace pole pomocí výčtu všech hodnot:**

	int arr[3] = {1, 2, 3};

&hellip; je totéž jako předchozí zápis.

**Pozor:** Nelze zadat více prvků než jsme deklarovali v `[]`!

	int arr[5] = {1, 2, 3, 4, 5, 6} // Chyba!

Pokud pole rovnou inicializujeme nemusíme jeho velikost zadávat -- překladač si
ji doplní sám.

	int arr[] = {1, 2, 3, 4, 5};
	int arr[] {1, 2, 3, 4, 5};    // rovnítko nemusíme zadávat (pouze C++)

**Inicializace pole pomocí všech prvků na stejnou hodnotu:**

	int arr[5] = {};   // všechny hodnoty se inicializují na hodnotu 0
	int arr[5] = {0};  // totéž jako předchozí

Rovnítko (v C++) můžeme vynechat:

	int arr[5] {};
	int arr[5] {0};

**Pozor:** Bez udání velikosti ho nelze inicializovat prvky na nulovou hodnotu!

	int arr[] = {};   // Nelze!
	int arr[] = {0};  // Nelze!

**Pozor:**
Prvky pole nelze inicializovat na hromadně na jinou hodnotu než nulovou!

	int arr[5] = {5}  // Nastaví první prvek na 5 a ostatní na hodnotu 0.

**POZOR:** Nelze přiřadit jedno pole jako hodnotu druhému poli!

	int arr1[3] = { 1, 2, 3};
    int arr2[3] = arr1; // CHYBA!

### Vytvoření pole s pomocí ukazatele a operátoru `new`

Vytvoří pole prvků na haldě (*heap*) a nastaví ukazatel na jeho první prvek;

Deklarace pole:

	int *arr = new int[5];            // po deklaraci obsahuje pole náhodné hodnoty

Definice pole:

	int *arr = new int[5] {};         // všechny hodnoty pole jsou nastaveny na 0
    int *arr = new int[5] {0};        // stejné jako předchozí příklad
    int *arr = new int[5] {1, 2, 3};  // obsahuje zadané hodnoty a dále doplněné 0

**Pozor:** Pamět musíme z paměti později sami uvolnit:

	delete [] arr;

### Vytvoření pole s použitím šablony `std::array` (C++11)

	std::array<int, 5> arr = {1, 2, 3, 4, 5};   // (1)
	std::array<int, 5> arr{ {1, 2, 3, 4, 5} };  // (2) Oboje složené závorky jsou nutné.

Přistup k prvkům pole (1)

	for (unsigned int i = 0; i < 5; i++)
	    printf("%d", arr[i]);

	for (unsignedint i = 0; i < arr.size(); i++)
        printf("%d", arr[i]);

	for (int item : arr)
		printf("%d", arr[i];

## Jak vytvořit standardní dvourozměrné pole

      0 1 2 3 4
     +---------+
	0| | | | | |
     +---------+
	1| | | | | |
	 +---------+
	2| | | | | |
	 +---------+

## Jak vytvořit standardní pseudo-dvourozměrné pole a přistupovat k jeho prvkům

	int WIDTH = 5;
	int HEIGHT = 3;

	int arr[WIDTH * HEIGHT];

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			arr[]
		}
	}

#### Jak zjistit počet prvků pole

+ Použitím funkce `sizeof()` ANSI/ISO C

		int arr_size = sizeof(arr) / sizeof(arr[0]);


+ Použitím funkce `size()` z `std::array`

		int arr_size = arr.size();

    [http://en.cppreference.com/w/cpp/container/array](http://en.cppreference.com/w/cpp/container/array)


#### Co znamená `(int const& arg)`

Pozor: v tomto případě není `&` tzv. adresní operátor! Poznamenejme ještě, že zápis:

	void function(int const &);

je stejný jako:

	void function(const int &);

Dále víme, že datové typy se v C++ čtou zprava doleva takže:

	int const &

#### Co je to reference

Reference je něco jako konstantní ukazatel:

	int i = 10;
	int j = 20;

	int *const p = &i;
	int &r = &i;

	p = j; // Chyba, nelze změnit...
	r = j; // Chyba, nelze změnit...

[http://stackoverflow.com/a/596750/2490538](http://stackoverflow.com/a/596750/2490538)

#### Reference vs Ukazatel

Ukazatel můžeme změnit

	int i = 10;
	int j = 20;

	int *p;
	p = &i;
	p = &j;

Reference je jen další zástupné jméno pro pojmenovanou hodnotu (proměnnou);
Musíme ji přiřadit "hodnotu" při její deklaraci a nemůžeme ji již změnit;

	int &k = i; // j můžeme nyní volat jménem k

Pokud změníme `i` hodnotu je dostupná i pod jménem `k`.

	i = 30;
	// k je také 30

	k = j // error

---

# Kompilace

## GCC, G++, Clang

## Make, Automake

## Vytvoření sdílené knihovny

.a, .lib

## Vytvoření dynamické knihovny

.so, .dll

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# Organizace zdrojových souborů

---

Rozdělení souborů

+ **zdrojový** soubor *source file* (`.c` nebo `cpp`)
+ **hlavičkový** soubor *header file* (`.h` nebo `hpp`)

Proč rozdělujeme soubory

+ zvyšuje rychlost kompilace
+ zlepšuje organizaci souborů
+ umožňuje znovupoužití kódu
+ umožňuje sdílení kódu
	+ mezi projekty
  	+ mezi programátory

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# C++ Reference

---

cstdarg/stdarg.h

+ va_list
+ va_start
+ va_arg
+ va_end
+ va_copy

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# Ukázky

---

**XorSwap**

	template <class T>
	void XorSwap (T *x, T *y)
	{
	     if (x != y)
	     {
	         *x ^= *y;
	         *y ^= *x;
	         *x ^= *y;
	     }
	 }

**AddSwap**

	template <class T>
	void AddSwap (unsigned T *x, unsigned T *y)
	{
	     if (x != y)
	     {
	         *x = *x + *y;
	         *y = *x - *y;
	         *x = *x - *y;
	     }
	 }

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

**Kdy použít `size_t`?**

Použijem vždy, když očekáváme nezáporný integer.
Here's how stddef.h defines it:

	typedef unsigned long size_t;

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# Benchmarking

---

http://stackoverflow.com/questions/483164/looking-for-benchmarking-code-snippet-c

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# C++ Coding Standard (Style Guide)

---

+ [http://www.possibility.com/Cpp/CppCodingStandard.html#pnames](http://www.possibility.com/Cpp/CppCodingStandard.html#pnames)
+ [http://duramecho.com/ComputerInformation/WhyCPointers.html](http://duramecho.com/ComputerInformation/WhyCPointers.html)
+ ttp://stackoverflow.com/questions/10252837/pointer-to-array-c](http://stackoverflow.com/questions/10252837/pointer-to-array-c)
+ [http://en.cppreference.com/w/cpp/container/array](http://en.cppreference.com/w/cpp/container/array)
+ [http://www.cplusplus.com/doc/tutorial/arrays/](http://www.cplusplus.com/doc/tutorial/arrays/)
+ [http://stackoverflow.com/questions/201101/how-to-initialize-an-array-in-c](http://stackoverflow.com/questions/201101/how-to-initialize-an-array-in-c)
+[http://stackoverflow.com/questions/1065774/c-c-initialization-of-a-normal-array-with-one-default-value](http://stackoverflow.com/questions/1065774/c-c-initialization-of-a-normal-array-with-one-default-value)
+[http://www.codeproject.com/Articles/7042/How-to-interpret-complex-C-C-declarations#right_left_rule](http://www.codeproject.com/Articles/7042/How-to-interpret-complex-C-C-declarations#right_left_rule)

+[http://en.wikibooks.org/wiki/C%2B%2B_Programming](http://en.wikibooks.org/wiki/C%2B%2B_Programming)


+ Použití klíčového slova `explicit` pro kontruktor.

Klíčové slovo explicit zamezuje konstruktoru implicitní konverzi paramateru.

```
class SomeClass {
  public:
    explicit SomeClass(int i) m_i(i) {
        // code here
    }
}
```



# Ukazatele (*Pointers*)
---

### Obsah

+ [Paměť počítače](#)
+ [Definice ukazatele](#)
+ [Ukazatel na základní typ](#)
+ [Ukazatel na typ `NULL`](#)
+ [Ukazatel na typ `void`](#)
+ [Ukazatel na složené typy](#)
+ [Ukazatel na ukazatel](#)
+ [Ukazatel na funkci](#)
+ [Ukazatelová aritmetika](#)
+ [Porovnávání ukazatelů](#)
+ [Přetypování ukazatele](#)
+ [Ukazatel na pole](#)
+ [Ukazatel na prvek pole](#)
+ [Ukazatel a modifikátor `const`](#)
+ [Ukazatel na strukturu](#)
+ [Ukazatel na objekt](#)
+ [Ukazatel vs reference](#)

## Paměť počítače
---

Adresy jednotlivých buňek zapisujem v hexadecimálním tvaru. ˇčíslo v xexadecimálním tvaru předznamenáváme `0x`. Převod  z hexadecimálního tvaru do dekadického zde [todo](#).

    0x00ADA03
      |
      +------> číslo v HEX tvaru

### RAM (*Random Access Memory*)

      OBSAH   ADRESA (HEX)
    +-------+
    |       | 0x00ADA03
    +-------+
    |       | 0x00ADA04
    +-------+
    |       | 0x00ADA05
    +-------+
    |       | 0x00ADA06
    +-------+

       ...

    +-------+
    |       | 0x00ADA10
    +-------+

## Definice ukazatele (*pointer* a *pointee*)
---

Ukazatel (angl. *pointer*) je jeden ze základních datový typů jak v jazyce *C* tak i *C++*. Podobně jako proměnná, která je pojmenovaným míste v paměti, na kterém se uchovává nějaká hodnota, je ukazatel

## Ukazatel na základní datové typy
---

Mezi základní datové typy budeme počítat `char`, `short`, `int`, `long` `float` a `double`. Ukazatale na složené datové typy jako jsou struktura a pole si ukážeme dále.

Rozlišujeme mezi pojmy *pointer* a *pointee* &mdash; pointer je prvkem, který někam ukazuje a pointee je naopak prvek, na který je ukazováno. Jinak řečeno pointer je referencí na nějaký prvek. (S pojmem reference se můžete setkat i v jazyce jako je Java.)

Pro deklaraci ukazatele používáme znak `*`, který je umístíme kamkoliv mezi jméno a typ ukazatele.

    int * p;

Deklarovali jsme proměnnou `p` jako *ukazatel* na typ `int`. I když to vypadá jednoduše, tak se zde na chvíli zastavíme a vysvětlíme si některé důležité vlastnosti takové deklarace.

Při případné kompilaci programu s deklarací `int * p;` se vytvoří proměnná typu ukazatel na datový typ `int`. To znamená, že se vyhradí v paměti místo které je dostatečně velké na to, aby se do ní uložila adresa paměti. Proměnná typu ukazatel většinou zabírá v paměti 4 byte. V tomto ohledu je jedno jestli ukazatel ukazuje ne typ `int` nebo `double` či jiný. Důvod, proč je u deklarace ukazatele důležité uvést na jaký typ bude ukazovat je ten, že tím určíme to, jak má program případně interpretovat data uložená na adrese, kterou ukazatel uchovává &mdash; , pokud s nimi budeme pomocí ukazatele pracovat.

Ukazatel opravdu není nic jiného než "obyčejná" proměnná, která uchovává adresu paměti, např. hodnotu `0x00ADA10`, ale při další manipulaci s proměnnou pomocí ukazatele a ukazatelové aritmetiky musí program vědět jak má interpretovat data uložená na této adrese. Pokud uložíme nějaká data do proměnné typu `int` nebo `double`, budou v paměti obvykle zabírat stejné místo (4 byte), ale to jak jsou tyto Byty respektive sekvence bitů interpretovány programem se zásadně liší! [viz způsob uložení čísel v počítači](#).

Další důležitou poznámkou je, že pouhou deklarací pouze vyhradíme místo v paměti &mdash; nepřiřadíme tím proměnné žádnou hodnotu a to je u ukazatelů obzvláště nebezpečné a může to vést k záludným chybám v programu. Takovému neinicializovanému ukazateli se říká

Pro určení, kam má ukazatel směřovat, použijeme znak `&`, který umístíme před název proměnné.

    int * pointer = & pointee;
    [*] ---> (1)

Stejně jako proměnné bysme měli přiřadit hodnotu, tak ukazateli bysme měli přiřadit adresu proměnné.

Stejne jako při deklaraci jiného datového typu musíme určit na jaký typ může ukazovat, adresu jakého typu může uchovávat.

    int* ptr;
    int *ptr;
    int * ptr;

Všechny zápisy jsou povolené, avšak **doporučit lze druhý nebo třetí zápis**. Podívejme se totiž, jak situace vypadá při vícenásobné deklaraci.

    int* ptr, i;

Zde je `ptr` opravdu ukazatel, ale `i` je obyčejná proměnná typu `int`. Lepší je tedy přisunout znak více nebo úplně těsně ke jménu ukazatele.

    int *ptr, i;
        ^     ^___ proměnná typu `int`
        |_________ ukazatel na typ `int`

## Operátor adresy `&` a dereference `*`
---

### Inicializace ukazatele pomocí adresního (referenčního) operátoru `&`

Ukazatel bychom  měli vždy inicializovat [poznámka]. Neinicializovaný ukazatel (*wild pointer*) je zdrojem mnoha potíží! K inicializaci ukazatele slouží *referenční* též nazývaný *adresní* operátor (*reference/adress-of operator*). Pomocí něho získáme adresu proměnné, kterou inicializujeme náš ukazatel.

    int *ptr; // tady to není OK!

    int i = 42;
    ptr = &i;

nebo rovnou

    int i;
    int *ptr = &i;

    i = 42;
    *p = 43;



### Dereferenční operátor `*`

Hned na začátku jsme si vysvětlili, že rozeznáváme *pointer* a *pointee*. Pokud máme vždy jasno, co je v našem kódu pointer a pointee, nemůže nás mást, že znak * se v souvislosti s ukazateli používá dvěma různými způsoby: a to pro deklaraci nového ukazatele, tak získání hodnoty z adresy, kam ukazatel směřuje

Vytvoříme-li nový ukazatel, který ukazuje na místo, kde je uložena nějaká proměnná, pak musí  existivat způsob, jakým získat hodnotu proměnné, jen pomocí ukazatele. Pro tento účel se opět použije * av3ak v jin9m kontextu:

    int pointee = 1;
    int *pointer = &pointee;






&, *

### Inicializace ukazatele na `NULL`

Pokud mu nechceme přiřadit adresu ihned (pomocí adresního operátoru), alespoň ho inicializujeme na hodnotu `NULL`. I to mů že vést k potížím, při snaze získat hodnotu (dereference) ukazatele inicializovaného na NULL, alespoň však můžeme použít test `if (ptr == NULL)` aj. Ukazateli inicializovanému na hodnotu `NULL` se říká *null pointer* a důležité místo v datových strukturách jako je spojový seznam aj.

    int *p = 0;

nebo můžeme použít definované makro `NULL`. Toto makro bývá nejčastěji definované v jednom z těchto  hlavičkových souborů `stdio.h`, `stdlib.h`, `stddef.h` (v C++: `cstdio`, `cstdlib`, `cstddef`).

    int *p = NULL;

**Pozor:** Ukazatel na `NULL` nemůžeme dereferencovat, stejně jako neinicializovaný ukazatel:

    int i = &p;  // CHYBA!

Avšak narozdíl od neinicializovaného ukazatele můžeme alespoň testovat na hodnotu `NULL`:

    if (p != NULL) {
        int i = &p;
    }

### Inicializace ukazatele na `void`

Pokud v čase kompilace nevíme na jaký typ bude náš ukazatel ukazovat, můžeme definovat tzv. ukazatel na typ `void`. Pak je možné takový ukazatel inicializovat na libovolný typ. Je zřejmé, že zde vyvstávají problémy s typovou kontrolou. Nicméně přesně takto se postupuje, pokud chceme vytvořit něco jako generickou datovou strukturu.

    void * p;

    int i = 1;
    double d = 1.2;
    char c = 'a';

    p = &i;
    p = &d;
    p = &a;


## Ukazatel a struktura (unie)
---

### Ukazatel na strukturu

`(*p).item` vs `p->item`

    struct cube {
        double a;
        double b;
        double c;
    } mycube;

    struct cube *cube_ptr = mycube;

    mycube->a = 1.0;
    mycube->b = 2.0;
    mycube->c = 3.0;

    double volume = mycube->a * mycube->b * mycube->c;

### Struktura s ukazatelem na strukturu

    struct node {
        double value;
        struct node *prev;
        struct node *next;
    }


## Ukazatel a pole
---

Rozdíl mezi **ukazatelem na pole** a **ukazatelem na prvek pole** je důležité znát.

Formula for computing the address of ptr + i where ptr has type T *. then the formula for the address is:

addr( ptr + i ) = addr( ptr ) + [ sizeof( T ) * i ]

For for type of int on 32bit platform, addr(ptr+i) = addr(ptr)+4*i;

### Ukazatel na prvek pole

Mějme pole se třemi prvky typu `int`:

    int arr[] = {1, 2, 3};

Potom ukazatal na typ `int` můžeme deklarovat stejně těmito dvěma způsoby:

    int(*p);  // (1)
    int *p;   // (2) závorky kolem ukazatele nejsou nutné

Oba následující příklady jsou stejné a nastavují ukazatel **na první prvek** pole.<a name="uk"></a>

    p = &arr[0];  // reference na první prvek pole (jeho adresa)
    p = arr;      // taktéž reference na první prvek pole


    p1 = arr + 3 ; // p1 == & arr[ 3 ]
p2 = p1 - 2 ; // p1 == & arr[ 1


### Průchod polem pomocí ukazatele

#### Jednorozměrné pole

Ještě jednou vše v jednom zápise a hned si ukážeme, jak můžeme *traverzovat* polem pomocí ukazatele a operátoru inkrementace `++` a dekrementace `--`.

    int arr[] = {1, 2, 3};
    int *p = arr;

Průchod polem od začátku ke konci:

    printf("%d", *p);  // -> 1
    p++;

    printf("%d", *p);  // -> 2
    p++;

    printf("%d", *p);  // -> 3

Průchod polem od konce k začátku:

    printf("%d", *p);  // -> 3
    p--;

    printf("%d", *p);  // -> 2
    p--;

    printf("%d", *p);  // -> 1


**Pomocí cyklu `for`:**

Není tajemstvím, že překročit mez pole pomocí ukazatele je častou chybou!
Místo postupné inkrementace, zvláště při průchodu velkým polem, můžeme použít cyklus.

    for (int i = 0; i < 3; i++)
    {
        printf("%d", *p);
        p++;
    }

nebo

    for (int i = 0; i < 3; i++, p++)
    {
        printf("%d", *p);
    }

Pokud neznáme předem velikost pole ani jeho typ, lze počet prvků spočítat pomocí operátoru `sizeof` a použít ho jako mezní honotu v cyklu. Počet prvků pole dostaneme, pokud celkovou velikost pole dělíme velikostí prvního prvku (velikost je v *Byte*).

    const int SIZE = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < SIZE; i++, p++)
    {
        printf("%d", *p);
    }

#### Dvourozměrné pole


## Ukazatel na objekt
---


## Ukazatel na ukazatel
---

## Ukazatel na funkci
---

Stejně jako máme ukazatel na jakýkoliv typ (int, double pole atd.), můžeme ho deklarovat jako ukazatel na funkci.


Mějme funkci pro součet dvou čísel:

    int Add(int x, int y)
    {
        return x + y;
    }

Ukazatel na takovouto funkci deklarujeme takto:

    int (*funcPtr)(int, int);
    ^    ^         ^    ^
    |    |         |    |
    |    |         +----+-- typy argumentů předávané funkce
    |    +----------------- ukazatel na funkci
    +---------------------- typ návratové hodnoty funkce

Nyní můžeme našemu ukazateli předat referenci na funkci, která splňuje jeho deklaraci a ukážeme si, že obě následující varianty jsou možné (podobně jako u ukazatele na prvek pole). [^](#uk)

    funcPtr = &Add;
    // nebo
    funcPtr = Add;

Uděláme to ještě jednou spolu s předchozí deklarací.

    int (*funcPtr)(int, int) = &Add;
    // nebo
    int (*funcPtr)(int, int) = Add;

**Pozor:** Všimněme si, že **vynecháváme závorky** za názvem funkce. To by znamenalo, že chceme ukládat návratovou hodnotu funkce, a to nechceme!


 Nyní můžeme tento ukazatel používat stejně jako funkci.

    int result = *(funcPtr)(1, 2);  // -> 3

### Kde se používají?

+ Pokud chceme vztvořit pole ukazatelů na funkce.

        void f1() { printf("f01\n"); }
        void f2() { printf("f01\n"); }
        void f3() { printf("f01\n"); }

        void(*func[])() = { f1, f2, f3 };

        // nebo

        typedef void(*funcPtr)();
        funcPtr func[] = { f1, f2, f3 };

        // funkce voláme jako

        func[0]();  // -> f01
        func[1]();  // -> f02
        func[2]();  // -> f03


+ Pokud chceme předat funkci jako parametr jiné funkci (např. tzv. *callback*).

## Ukazatelová (adresní) aritmetika
---

S ukazateli můžeme počítat podobně jako s celočícelnými proměnnými jsem však omezeni na **sčítání**, **odčítání**, **porovnání** a sepciální případy sčítání a odčítání, kterými jsou **inkrementace** a **dekrementace**.


### Sčítání a odčítání


Aritmetiku můžeme aplikovat jak na samotné ukazatele tak na hodnoty, na které ukazují. Nechť `p` je ukazatel a `i` je proměnná.

    int i = 42;
    int *p = &i;

Pak všechny následující zápisy mění hodnotu na kterou ukazuje `p`.

    *p = *p + 1;  // i je 43
    (*p)++;       // i je 44

    *p = *p - 1;  // i je 43
    (*p)--;       // i je 42

    *p = *p - 2;  // i je 40

    ++*p;         // i je 41
    --*p;         // i je 40

    *p = *p + 2;  // i je 42

V tomto případě je jedno jestli použíjeme *pre*/*post*-inkrementaci respektive dekrementaci. Všimněme si ale, že při postinkrementaci či postdekrementaci musíme použít uzávorkování `(*p)++` a `(*p)--`. Důvod je ten, že vyhodnocení takového výrazu probíhá zprava.

Přičtení nebo odečtení celočíselné hodnoty k ukazateli znamená vlastně posun v paměti o *příslušný* počet bytů. O kolik bytů dopředu nebo vzad se pohybujeme určuje to, kolik zabírí v paměti datový typ, na který ukazatel ukazuje.

Mějme pole a ukazatel jemuž přiřadíme adresu druhého prvku pole (prvek s indexem 1):

    int arr[] = {1, 2, 3};
    int *ptr = &arr[1];

Pak můžeme procházet pamětí (pole) pomocí přičítání nebo odčítání hodnoty k ukazateli. Tato hodnota je rovna počtu bytů datového typu, na který ukazatel ukazuje. Např. pro typ `int` je na většině počítačů vyhrazeno 4 byte. Zápis ptr + 1, znamená posun v paměti o 4 byty dopředu a zápis ptr - 1 znamená posun o stejný počet bytů zpět.

    printf( "%d", *(ptr - 1));
    printf( "%d", *(ptr) );
    printf( "%d", *(ptr + 1));

**Pozor**: U zápisu *(ptr) lze závorky vynechat, nikoliv dalších výrazů, tedy uzávorkování je zde nutné `*(ptr + 1)`!

Stejný zápis s opravdovou změnou hodnoty ukazatele:

    ptr = ptr - 1;
    printf( "%d", *ptr); // => 1

    ptr = ptr + 1;
    printf( "%d", *ptr); // => 2

    ptr = ptr + 1;
    printf( "%d", *ptr); // => 3


Zápis `ptr = ptr + 1;` můžeme v tomto případě zapsat úsporněji:

    ptr += 1; ptr -= 1;

    // nebo
    ptr++;
    ++ptr;
    ptr--;
    --ptr;

Tot se vlastně děje na pozadí, pokud napíšeme např `ptr = ptr + N`

        (ptr + (N * sizeof(*ptr)));

### Další příklady

    int length(char *s)
    {
       char *str = s;
       while(*str++);
       return str - s;
    }


    while(*n++ != '\0'){
        len++;
    }

### Porovnávání ukazatelů

## Přetypování ukazatele
---

## Ukazatel a modifikátor `const`
---

### Ukazatel na pojmenovanou konstantu

Pokud má ukazatel ukazovat na pojmenovanou konstantu, musíme modifikátor `const` uvést už při deklaraci. Stejně jako u definice konstantní proměnné můžeme použít oba možné zápisy.

    const int *p = &N;
    int const *q;

    [int const] [*p] = [&N;]
    |           |      +----> přiřazená hodnota (adresní operátor)
    |           +-----------> deklarace ukazatele
    +-----------------------> typ proměnné, na kterou se ukazuje

### Konstantní ukazatel na proměnnou

Pokud požadujeme, aby ukazatel ukazoval na stále stejné místo v paměti (stejnou proměnnou) můžeme i jemu přiřadit modifikátor `const`. Ten **musí následovat vždy za znakem `*`** a hlavně musíme ukazateli přiřadit referenci (`&` operátor reference), stejně jako konstantní proměnné přiřazujem hodnotu.

    int q = 10

    int *const p = &q;

### Konstantní ukazatel na pojmenovanou konstantu`.

Tou mohou být např. adresy proměnných `N` a `M`. Jak vidíme, to na co ukazatel ukazuje, se dá zapsat opět dvěma platnými způsoby.

    const int *const p = &N;
    int const *const q = &M;

Protože můžeme tvořit ukazatele na ukazatele a ještě přidávat různě modifikátor `const`, řekneme si o pravidle RTL.

### RTL (Right-to-Left) nebo též spirálové pravidlo pro ukazatele

Vše čteme zprava doleva, či po spirále, jak uvádí odkaz níže.


**Příklad 1**

         +-------->
         | +-->   |
         | |  |   |
         | |  |   |
    char * var[10];
    ^    ^    |   |
    |    |    |   |
    |    <----+   |
    |             |
    <-------------+

+ **Co je `var`?**<br>
  Vyrazíme od `var` nahoru a doprava (po směru hodin), pak dolu a narazíme na `[10]`.<br>
  Vidíme, že `var` je pole&hellip;

+ **Pole jakých prvků?**
  Pokračujeme dolu, jakoby po spirále (stále po směru hodin) a narazíme na `*`.<br>
  Jde o pole ukazatelů&hellip;

+ **Ukazatelů na co?**
  Pokračujeme po spirále, narazíme na `;`, pokračujeme dále a před námi je `char`.<br>
  Jde o pole ukazatelů na datový typ `char`.

Další příklady zde: [http://www.c-faq.com/decl/spiral.anderson.html](http://www.c-faq.com/decl/spiral.anderson.html)


### Ukázky

    char **p1;              // ukazatel na ukazatel na typ `char`
    const char **p2;        // ukazatel na ukazatel na konstantní typ `char`
    char *const *p3;        // ukazatel na konstantní ukazatel na typ `char`
    const char *const *p4   // ukazatel na konstantní ukazatel na konstantí typ `char`


+ `const char * variable`
  je **měnitelný** ukazatel na typ `char` na neměnitelnou proměnnou typu `char`.

+ `char * const variable`
  je **neměnitelný** ukazatel (může ukazovat pouze na zadanou proměnnou) na typ, ale hodnotu proměnné je možné **změnit**.

+

## Reference (pouze C++)
---

[http://www.eternallyconfuzzled.com/tuts/languages/jsw_tut_pointers.aspx#ptrtype](http://www.eternallyconfuzzled.com/tuts/languages/jsw_tut_pointers.aspx#ptrtype)

## Pointers to members (pouze C++)
---

## Ukazatel na objekt (pouze C++)
---

Velmi využívaný je ukazatel na objekt.

    T obj = new T();

    T * objPtr = &obj;

Stejně jako máme ukazatel na jakýkoliv typ (int, double pole atd.), můžeme ho deklarovat jako ukazatel na objekt




---

Stejně jako máme ukazatel na jakýkoliv typ (int, double atd.), můžeme ho deklarovat jako ukazatel na pole prvků.

    int arr = {1, 2, 3};

    int (*p)[3] = &arr;


**Pozor:** Kulaté závorky jsou důležité, jinak by šlo o jiný případ ukazatele[doplnit odkaz]! Stejně tak velikost uvedená v hranatých závorkách!

Pokud neznáme velikost pole předem může být zadána jako konstanta (`SIZE`) nebo jako výraz, nebo dosadíme známý výraz pr výpočet velikosti neznámého pole:

    int (*p)[SIZE] = &arr;

nebo

    int (*p)[sizeof(arr) / sizeof (arr[0])] = &arr;

**Pozor:** Argument `SIZE` opravdu musí být typu `const int`, alespoň MVC++ kompilátor to vyžaduje.


## Vztah ukazatele a reference
---

[http://www.codeproject.com/Articles/4894/Pointer-to-Pointer-and-Reference-to-Pointer](http://www.codeproject.com/Articles/4894/Pointer-to-Pointer-and-Reference-to-Pointer)

+ **Proč předávat parametr funkce jako ukazatel?**
+ **Proč definovat návratovou hodnotu funkce jako ukazatel?**

ukazatele můžeme uložit do pole

dvojrozměrné pole jsou pole ukazatelů na pole.

    int a[10][20]; // deklarace dvojrozměrného pole 10 x 20

    int * b[10];   // deklarace pole pro deset ukazatelů na typ `int`

    int n
    int *p

    int* i, j
    vs
    int *i, j

    char **argv

    int array[4][3];

    int (*p)[3];  // *ukazatel na pole* pro tři prvky typu `int`
    int *p[3];    // *pole pro ukazatele* na typ `int`

    int **p1;     // p1 je ukazatelem  na ukazatel  na typ `int`
    int *&p2;     // p1 je referencí   na ukazatel  na typ `int`

    int &*p3;     //  ERROR: Pointer    to a reference is illegal.
    int &&p4;     //  ERROR: Reference  to a reference is illega

    hvězdička nedpředchází křížek


+ Referenci nemůžeme přiřadit NULL.
+ Referenci nelze změnit hodnotu.


    double x = 10;
    double y = 10;


    double *p1 = &x;
    double *p3 = &y;

    // int *p2 = new int;  // ukazuje na nepojmenovaný int

Reference

    double &r1 = x;
    double &r2 = y;


### Předání parametru pomocí ukazatele a reference


    void swap_with_ptr(int *x, int *y)
    {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }


    void swap_with_ref(int &x, int &y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }


    swap_with_ptr(&x, &y);
    swap_with_ref(x, y);


Pokud se koukneme na volání obecné funkce `swap(x, y);`, nemůžeme si být jisti, jestli dosazujeme za parametry hodnoty (*call-by-value*) nebo předáváme reference, bez toho abysme se podívali definici funkce.

### Reference na ukazatel


    func_A(int *&arg)
    {

    }

    func_B(int *arg)
    {

    }

### pass-by-value

### pass-by-reference



### Reference na ukazatel


### Ukazatel na ukazatel



Pokud předáváme ukazatel hodnotu, vytvoří se jeho kopie uvnitř funkce. Samotný ukazatel je neměnný!

    #include <iostream>

    int global_i = 0;

    void fun(int *ptr)
    {
        ptr = &global_i;
    }

    int main()
    {
        int local_i = 1;
        int *ptr = &local_i;

        std::cout << *ptr << endl; // 2

        fun(ptr);

        std::cout << *ptr << endl;  // 2

        return 0;
    }




<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# Správa paměti v C
---

## Dynamická alokace paměti
--

### Zásobník

### Halda (*heap*)

Všecchny následující funkce najdem v hlavičkovém souboru `<stdlib.h>`

### `malloc()`

Funkce `malloc()` alokuje paměť specifikované velikosti (v bytech) a vrací ukazatel na záčátek tohoto bloku paměti.

    void *malloc(size_t size);

**Příklad**

    char *ptr = malloc(5);

                  -----------
    [ptr]-------->| | | | | |
                  -----------
                   0 1 2 3 4

V předchozím příkladě jsme alokovali blok paměti o velikost 5 byte a vytvořili ukazatel na `char` ukazující na začátek paměti (adresu první buňky). Protože v případě C je na všech platformách vyhrazen pro typ `char` 1 byte, můžeme jednoduše psát `malloc(5)`.

                  -----------
    [ptr]-------->|a|b|c|d|e|
                  -----------
                   0 1 2 3 4


### Type casting

    *ptr = (int *) malloc( sizeof(int) );



### Vždy testujeme jestli byla paměť opravdu přidělena

    if (ptr == NULL)
    {
        printf("ERROR");
        return -1;
    }

Namísto `printf` je lepší použít `fprintf`:

    fprintf(stderr, "Failed to allocate memory for chars.");

### `calloc()`

Funkce `calloc()` alokuje paměť specifikované velikosti v bytech a naství je na hodnotu 0.


### Rozdíl mezi `malloc()` a `calloc()`

Funkce `malloc` pouze alokuje potřebné množství paměti, zatímco `calloc` inicializuje hodnoty proměnných na 0.


## Příklady
---

Vytvoření pole neumožňuje za běhu programu změnit jeho velikost.

    int array[10];

Vytvoříme ukazatel na typ `int`, který ukazuje na začátek bloku paměti o velikosti 10 * velikost typu `int` (obvykle 4 byty, tedy 10*4=40 byte)

    int *array_ptr1 = malloc(10 * sizeof(int));

Vytvoříme ukazatel na typ `int`, který ukazuje na začátek bloku paměti o velikosti 10 * velikost typu `int` a inicializuje je nahosnotu 0;

    int *array_ptr2 = calloc(10, sizeof(int));

### Ověření příkladů

    for (array_ptr1 != NULL; array_ptr1++) {
        printf("%d", )
    }

### `realoc()`

Funkce `realloc()` zvětší nebo zmenší velikost alokované paměťi.

### `free()`

Funkce `free()` uvolní alokovanou paměť.

# Správa paměti v C++
---

### `new` a `new[]`

### `delete` a `delete[]`


## Odkazy
Odkaz: http://www.stroustrup.com/bs_faq2.html#constplacement


## Chytré ukazatele (**Smart Pointers**)
---

A smart pointer is an object that acts, looks and feels like a normal pointer but offers more functionality. In C++, smart pointers are implemented as template classes that encapsulate a pointer and override standard pointer operators. They have a number of advantages over regular pointers. They are guaranteed to be initialized as either null pointers or pointers to a heap object. Indirection through a null pointer is checked. No delete is ever necessary. Objects are automatically freed when the last pointer to them has gone away. One significant problem with these smart pointers is that unlike regular pointers, they don't respect inheritance. Smart pointers are unattractive for polymorphic code. Given below is an example for the implementation of smart pointers.

    template <class X>
    class smart_pointer
    {
              public:
                   smart_pointer();                          // makes a null pointer
                   smart_pointer(const X& x)            // makes pointer to copy of x

                   X& operator *( );
                   const X& operator*( ) const;
                   X* operator->() const;

                   smart_pointer(const smart_pointer <X> &);
                   const smart_pointer <X> & operator =(const smart_pointer<X>&);
                   ~smart_pointer();
              private:
                   //...
    };

    smart_pointer <employee> p= employee("Harris",1333);
    cout<<*p;
    p->raise_salary(0.5);

## Proč?

    MyObject *obj_ptr = new MyObject();
    obj_ptr->DoSomething();
    delete obj_ptr;

Co když se vyskytne výjimka při volání `DoSomething()`? Pak se neuvolní pamět!

Řešení:


### **unique pointer**

`std::unique_ptr` v hlavičkovém soubrou `<memory>`

### **scoped pointer**

`boost::scoped_ptr`

### **shared pointer**

`std::shared_ptr`
`boost::shared_ptr`


### **weak pointer**

`std::weak_ptr`
`boost::weak_ptr`

### **intrusive pointer**


## Odkazy

+ [http://stackoverflow.com/a/106614/2490538](http://stackoverflow.com/a/106614/2490538)
+ [http://www.boost.org/doc/libs/1_55_0/libs/smart_ptr/smart_ptr.htm](http://www.boost.org/doc/libs/1_55_0/libs/smart_ptr/smart_ptr.htm)


# RAII (*Resource Acquisition Is Initialization*)

# Lexikon

`type * ptr;`  deklarujem proměnnou jménem *ptr* typu ukazatel na typ *type*
např. `int *  ptr;` je ukazatel na typ int, nebo též můžeme řící ukazatel typu int.

`* ptr`  získáme hodnotu proměnné, na kterou ukazuje `ptr`.
`*(ptr)` to samé jako v předchozím příkladě

`*(ptr + 1)` zíkáme hodnotu, která je uložena v paměti, na kterou ukazuje `ptr` + 1, což je ofset -- ten je tak velký jaký zabírá v paměti uvedený typ.

```
int * ptr = NULL;

int a = 1;
int b = 2;
int c = 3

ptr = &a;  // `ptr` ukazuje na `a`
ptr = &b;  // `ptr` ukazuje na `b`
ptr = &(b + 1);

``

QUESTIONS
Pokud provádím test jestli jestli není ukazatel NULL mám dělat:
1. `if (ptr) {...}` nebo `if (ptr != NULL) {...}` nebo `if (NULL != ptr) {...}`.

Q:
Co je to statická funkce (např. `static void func();`?
A:
Statická funkce je taková, která je viditelná pouze v souboru ve kterém byla
deklarována -- neplést se statickou funkcí/metodou třídy.



    http://stackoverflow.com/a/1025604/2490538
Setting unused pointers to NULL is a defensive style, protecting against
dangling pointer bugs.
If a dangling pointer is accessed after it is freed, you may read or overwrite
random memory.
If a null pointer is accessed, you get an immediate crash on most systems,
telling you right
away what the error is.
For local variables, it may be a little bit pointless if it is "obvious" that
the pointer isn't accessed anymore after
being freed, so this style is more appropriate for member data and global variables.
Even for local variables, it may be a good approach if the function continues
after the memory is released.
To complete the style, you should also initialize pointers to NULL before they
 get assigned a true pointer value.

Nastavit hodnotu ukazatele který byl uvolněn z paměti pomocí funkce free()
zamezí chybám při nedovoleném přístupu k paměti. Poté co je ukazatel uvolněn
z paměti, můžeme k němu stále přistupovat  a číst již zcela nesprávný blok paměti
nebo přemazat již používanou paměť. Pokud však přistupujem k NULL ukazateli, pak
to bude vést k chybě... To je více důležiteé u globbálních ukazatelých než u
lokálních např v nějaké funkci,kde je mnohem snažší ověřit si, že v tomto bloku
 již nepřistupujem pomocí volného ukazatele.


---


# Poznámky k programování v C++

natavení kompilátoru h++ na Windows.
Stáhneme si MinGW verze pro 64 bitovou architekturu.
Přidáme mingw do cesty -- pozor musíme dát so system path a pak do user path, protože system path se vyhodnocuje jako první.

http://stackoverflow.com/questions/7132340/static-build-glew-glfw-on-linux

https://isocpp.org/blog/2015/04/gcc-5.1-released
Aby se v tom prase vyznalo!

Toolchain MingGW
https://wiki.qt.io/MinGW
https://fedoraproject.org/wiki/MinGW/Tutorial
http://mingw-w64.org/doku.php
http://sourceforge.net/p/mingw-w64/wiki2/FAQ/

!!!
http://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download
!!!
C:\Program Files\mingw-w64\x86_64-5.1.0-posix-sjlj-rt_v4-rev0

http://www.bogotobogo.com/cplusplus/libraries.php
http://stackoverflow.com/questions/15670169/what-is-difference-between-sjlj-vs-dwarf-vs-seh


    SJLJ (setjmp/longjmp): – available for 32 bit and 64 bit – not “zero-cost”: even if an exception isn’t thrown, it incurs a minor performance penalty (~15% in exception heavy code) – allows exceptions to traverse through e.g. windows callbacks

    DWARF (DW2, dwarf-2) – available for 32 bit only – no permanent runtime overhead – needs whole call stack to be dwarf-enabled, which means exceptions cannot be thrown over e.g. Windows system DLLs.

    SEH (zero overhead exception) – will be available for 64-bit GCC 4.8.

source: http://qt-project.org/wiki/MinGW-64-bit

CMake, short for "Cross-patform Make"
Make sure you choose to add CMake to the system PATH.
After this, press WinKey+R - a "Run" dialog appears, type "cmd"
cmake --version


---

## Obsah

+ [Třídy a objekty](#)
+ [Zapouzdření](#)
+ [Dědičnost](#)
+ [Polymorfismus](#)
+ [Abstraktní třída](#)
+ [Rozhraní](#)

---

# Úvod

V tomto textu jsou shromáždeny poznámky o programování v jazyce C++. Není
to však úvod do programování, předpokládá se tedy znalost základní terminologie
programování a nejlépe také znalost objektově orientovaného prgramování, kvůli
kterému lze snad jedině C++ doporučit namísto jazuka C.

Pokud máte zkušenosti z jazykem Java, nebo Python, směle do studia, jiak vás
odkážu buď na řadu článků o programování v v jazyce Java, které jsem napsali paralelně, nebo na příslušnou literatur.

## Cyklus

### Nekonečný cyklus

	for(;;) { }

	while(1) { }

	while(true) { }

Poznámka: V C musíme vložit hlavičkový soubor `stdbool.h`

## Větvení

	if () {
		//
	}

	if () {
		//
	} else {
		//
	}


	if () {
		//
	} else if () {
		//
	}

# Proměnné, konstanty a základní datové typy

**Celá čísla**

short int (short)<br>
int <br>
long (long int)<br>

    #include <iostream>

    int main()
    {
      int a = 1;
      int b = 2;
      int c = a + b;

      std::cout << c << std::endl;

      return 0;
    }

Pro stručnější vyjádření, můžeme na začátku programu deklarovat použití jmeného
prostoru (*namespace*) do kterého patří i funkce `cout` a `endl`, pak nemusíme
jmenný prostor uvádět pomocí operátoru `::`


    #include <iostream>

    using namespace std;
    int main()
    {
      int a = 1;
      int b = 2;
      int c = a + b;

      cout << c << endl;

      return 0;
    }

**Reálná čísla**, s desetinnou částí

**znaky**

### globální a lokální proměnná, obor platnosti

# Složené datové typy: struktura, unie, třída

# Struktura, Třída, Objekt

## Struktura

    struct Point {
      int x;
      int y;
    }

    Point p1;
    Point p2;

 nebo

    struct Point {
      int x;
      int y;
    } p1, p2;

    p1.x = 10;
    p1.y = 20;

    p2.x = 20;
    p2.y = 10;

#### Nepojmenovaná (anonymní) struktura

    struct {
      int x;
      int y;
    } p1;

    p1.x = 10;
    p2.x = 20;

### Unie

# Třída, Objekt

---

Návrh tříd v C++ je obdobný jako v jazyce Java, jsou zde jen rozdíly jejich
programové konstrukce. Předně narozdíl od Javy je často třída rozdělena do dvou
 souborů &ndash; <em>hlavičkového</em> souboru, kde jsou uvedeny deklarace
 členských proměnných a funkcí (metod) třídy s příponou <code>.h</code>
 a soubor, kde jsou ve kterém jsou metody třídy implementovány, ten má příponu
  <code>.cpp</code>

## Konstruktor a Destruktor

Pro vytvoření instance třídy se tradičně používá funkce, která vytvoří objekt
ze zvolené třídy neboli <em>konstruktor</em>. Pro uvolnění paměti již
nepotřebém objektu se využívá <em>destruktor</em>, to je významný rozdíl oproti
 zazuku Java, kde ve většině případů za más tutuo prácí udělá <em>garbagge
 collector</em>.

### Konstruktor

+ Je pojmenován stejně jako třída.
+ Nemá návratovou hodnotu (ani typ <code>void</code>), ale můžeme definovat
vstupní parametry.
+ Kostruktor může být v rámci jedné třídy více, ale musí se lišit počtem nebo
typem parametrů.

### Destruktor

+ Je pojmenován stejně jako třída a navíc ho předchází znak `~`.
+ Nemá návratovou hodnotu (ani typ <code>void</code>) ani mu nepředáváme žádné
parametry.
+ Destruktor může být v rámci jedné třídy pouze jeden.

#### Příklady

Nejprve s i ukážemem třídu zapsanou v jednom souboru, bez členské proměnné, jen
 s konstruktorem a destruktorem, které jen vypíší zprávu o svém volání.

    #include <iostream>;
    using namespace std;

    class Simple {
      public:
        Simple();  // Constructor
        ~Simple(); // Destructor
    };

    Simple::Simple() {
      cout << "Constructor called!" << endl;
    }

    Simple::~Simple() {
      cout << "Destructor called!" << endl;
    }

    int main()
    {
        Simple s = Simple();
        return 0;
    }

Příklad, kde jsou použity tři konstruktory se stejným typem, ale různým počtem
parametrů.

	class Point
	{
	  public:
	    int x;
	    int y;

	    Point();
	    Point(int x);
	    Point(int x, int y)
	    ~Point();
	};

	Point::Point()
	{
		this.x = 0;
		this.y = 0;
	}

	Point::Point(x)
	{
		this.x = x;
		this.y = x;
	}

	Point::Point(x, y)
	{
		this.x = x;
		this.y = y;
	}

	~Point()
	{
		std::cout << "Destructor called!" << std::endl;
	}

Příklad, kde jsou použity tři konstruktory se stejným typem, ale různým počtem
 parametrů.


    class Point {
      public:
        Point(float x; float y); // konstruktor
        ~Point();                // destruktor
        void setX(float x);
        void setY(float y);
        float getX();
        floar getY();

      private:
        float x;
        float y;
    };

    //implementace metod

    Point::Point(float x; float y) {
      this->x = x;
      this->y = y;
    }

    Point::~Point() {
      delete x;
      delete y;
    }

    void Point::setX(float x) {
      this->x = x;
    }
    void Point::setY(float y) {
      this->y = y;
    }

    float Point::getX() {
      return x;
    }

    float Point::getY() {
      return y;
    }


### Dědičnost

## Použití externí knihovny ve Visual Studio 2010 Express Ed.


## Rozdělení programový knihoven

+ statická knihovna (angl. **static linking library**)
+ dynamická knihovna (angl. **dynamic linking library**)
+ sdílená knihovna (angl.	 **shared library**)
+ nesdílená knihovna

### Statická knihovna
Statická knihovna tvoří s výsledným programem jeden celek.
Statická knihovna obvykle používá příponu `.dll `(Windows) nebo `.a`, `.lib` (Linux).

### Dynamická knihovna

Narozdíl od statické knihovny netvoří dynamická knihovna s výsledným programem
 jeden celek, ale program si při překladu vytvoří odkazy na volané funkce
 z dynamické knihovny. Dynamické knihovny pak ale musí být stále dostupné pro
 správný běh programu. Proto programy, které využívají dynamických knihoven
 nějakého systému, provádějí instalaci, při které se vytvoří vazba na tyto
 knihovny. Další možností je, že jsou knihovny distribuovány spolu s programem
 ve nějaké společné složec (adresáři).

Dynamická knihovna obvykle používá příponu `.dll` (Windows) nebo `.o`, `.so` (Unix/Linux).

### Sdílená knihovna

## Reference:
http://cs.wikipedia.org/wiki/Knihovna_(programov%C3%A1n%C3%AD)

# Funkce s proměnným počtem parametrů

Funkce s proměnným počtem parametrů neboli *variadické funkce*

	int Sum(int num, ...)
	{
		for (int i = 0; i < n; i++)
		{
			sum += va_list()
		}

		return sum;
	}


# Abstraktní třída, čistě abstraktní třída (rozhraní)

Abstraktní třída obsahuje jednu nebo více čistě virtuálních (abstraktních)
metod. Ty musí být implementovány ve třídě, která rozšiřuje abstraktní třídu.

Pojem čistě abstraktní třída označuje třídu, která obsahuje jen čistě virtuální
metody a neobsahuje žádné členské proměnné -- to v podstatě odpovídá tzv.
rozhraní, tak jak ho známe např. z jazyka Java.

Abstraktní třída nemůže být přímo instanciována, protože obsahuje alespoň jednu
abstraktní metodu, která nemá tělo -- je tedy navržena jako bázová třída.

---

# Generika

---

# Templates, STL (Standard Template Library)

---

Typová parametrizace neboli šablony (*templates*). Možnost znovupoužití
zdrojového kódu (podobně jako dědičnost a kompozice). Namísto vícenásobné
deklarace (přetížení) stejné funkce pro různé datové typy, vytvoříme šablonu,
 podle níž kompilátor v době překladu odvodí potřebné datové typy parametrů,
 případně i navratovou hodnotu funkce.

Vlastnosti šablon:

+ jsou instanciovány v době překladu (*compile time*)
+ jsou typově bezpečné
+ umožnují uživatelsky definovanou specializaci
+ umožnují beztypové parametry
+ používají *lazy structural constraints*
+podmorují *mixins*

Šablony jsou používány v době překladu:

Rozeznáváme dva typy šablon:

+ šablony funkcí (*function templates*)
+ šablony tříd (*class templates*)

[http://msdn.microsoft.com/en-us/library/sbh15dya.aspx](http://msdn.microsoft.com/en-us/library/sbh15dya.aspx)
[http://msdn.microsoft.com/en-us/library/sbh15dya.aspx](http://msdn.microsoft.com/en-us/library/sbh15dya.aspx)

## Syntax

Zápis (1) je stejný jako (2), avšak druhý je preferovaný...

	template <class T>

	template <typename T>


Místo nestálého přetěžování funkce, pro jiné typy parametrů:

	void PrintData(int data)
	{
		std::cout << data << std::endl;
	}

1. přetížení funkce

	void PrintData(double data)
	{
		std::cout << data << std::endl;
	}

1. přetížení funkce

	void PrintData(double data)
	{
		std::cout << data << std::endl;
	}

Požijeme **šablonu** pro tuto funkci.


## Šablony funkcí (*function templates*)

Šablonové funkce jsou parametrizované funkce, jde tedy o rodinu funkcí, které
se liší jen v typu parametrů a případně typu návratové hodnoty. To zajištuje,
že stejnou funkci můžeme volat pokaždé s jiným datovým typem jejího argumentu.
---

	template < comma-separated-list-of-parameters >

	///
	template <typename T>
	inline T const& MaxFromTwo(T const& a, T const& b)
	{
		return a > b ? a : b;
	}
	///
	template <typename T>
	inline T const& MaxFromThree(T const& a, T const& b, T const& c)
	{
		return a > b
			? (a > c ? a : c)
			: (b > c ? b : c);
	}
    ///
	template <typename T>
	inline T const& MaxFromAny(T const& a, ... )
	{
		return a;
	}


	template <class T>
	void PrintTwice(T data)
	{
		std::cout << data << std::endl;
	}

Funkce přijímá  a vrací typ T, který odvodí kompilátor. U všech parametrů, pro
které je definován operátor `>` lze tuto funkci použít.

	template <class T>
	T Max(T a, T b)
	{
		return a > b ? a : b;
	}

Pro řetězce vytvoříme specializovanější šablonovou funkci:

	template <class T>
	T Max(T a, T b)
	{
		return a > b ? a : b;
	}

	char *Max(char *a, char *b)
	{
		return strncmp(a, b) > 0 ? a : b;
	}

	// AVERAGE
	template <class T>

	double Average(T arr[], int count)
	{
		T sum = T();  // sum = 0

		for (int i = 0; i < count; i++)
		{
			sum += arr[i];
		}

		return double(sum) / count;
	}

	int main()
	{
		int iArray[] = {1, 2, 3};
		float fArray[] = {1.1f, 2.2f, 3.3f};
		double dArray[] =  {1.1, 2.2, 3.3};

		std::cout << Average(iArray, 3) << std::endl;
		std::cout << Average(fArray, 3) << std::endl;
		std::cout << Average(dArray, 3) << std::endl;
	}

Zlepšení funkce `Average`:

	template <class T>
	T Average(T *arr, int count) {}

Najdi vetší číslo ze tří:

	template <typename Comparable>
	Comparable Max(Comparable a, Comparable b, Comparable c)
	{
		return (a > b)
			? ((a > c) ? a : c)
			: ((b > c) ? b : c);
	}

	int Max<>(1, 2, 3);


## Šablony třídy (*class templates*)

---

Šablony tříd jsou nejčastěji používány pro vztváření generických datových
kontejnerů např.: STL: `list<int>`, `list<string>` atd.

	/////////////////
	// MyClass.HPP //
	/////////////////

	template <typename T> class MyClass
	{
	  public:
	    MyClass();
	    ~MyClass();
	    void OneFunction();
	    T TwoFunction();

	  private:
	    int oneVar;
	    T twoVar;
	}

	/////////////////
	// MyClass.CPP //
	/////////////////

	#include<MyClass.hpp>

	template <typename T> MyClass<T>::MyClass()
	{                         // ^------------------ Musíme napsat typ!
		oneVar = 0;
	}

	template <typename T> void MyClass<T>::setTwoVar(T var)
	{
		twoVar = var;
	}

	template <typename T> T MyClass<T>::getTwoVar()
	{
		return twoVar;
	}

## Iterátory

Jde o zobecnění pojmu ukazatele.

## Odkazy

[http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part](http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part)

---

# Datové kontejnery

---

## Array `std::array`

#### Konstruktory

	std::array<int> arr = {1, 2, 3}

	std::array<int, 3> arr;
	arr = {1, 2, 3};


#### Modifikátory


 **`swap()`**

	#include<iostream>
	#include<array>

	std::array<int> A = {1, 2, 3};
	std::array<int> B = {4, 5, 6};

	A.swap(B);

	std::cout << "A: ";

	for (int &item : A)
		std::cout << ' ' << item;

	std::cout << "B: ";

	for (int &item : A)
		std::cout << ' ' << item;


**`fill()**

**`size()**

---

## Vector `std::vector`

Vektor neboli dynamické pole je datový kntajner, který uchovává prvky stejného
typu a jehož velikost se může dynamicky měnit. Pokud při přidání prvku
překračujeme deklarovanou velikost vektoru, je automaticky zdvojnásobena jeho
kapacita. Přesněji řečeno se vztvoří nové pole dvojnásobné velikosti, do
kterého jsou všechny prvky přemístěny.


### Metody


#### Iterátory

	begin()
	end()

#### Kapacita

	size()		vrací aktuální velikost (počet prvků)
	max_size()	vrací maximální velikost
	empty()		zjistí, jestli je vektor prázdný
	resize()	navíší kapacitu

#### Přístup k prvkům

	[]
	at()
	front()
	back()

#### Modifikátory

	push_back()
	pop_back()
	insert()
	erase()
	swap()
	clear

## Dequeue `std::deque`

---

## Forward List

---

## Map `std::map`

---

## Set `std::set`

---

## Stack `std::stack`

---

##



# Použiti modifikátoru `const`

**Funkce nemůže změnit hodnotu hodnotu proměnné, kterou přebírá jako parametr(ukazatel)**

	MyFunction(const &int number) {...}


## Pojmenovaná konstanta (named constant)

"Proměnnou", kterou definujeme s modifikátorem `const` nelze již změnit jednou
přiřazenou hodnotu (neplatí to tak úplně jak si ukážeme později). Místo slova
`const` si také můžeme jednoduše myslet slovo *read-only* (porovnej s C#).
Protože hodnotu takovéto proměnné nelze již dále v programu měnit, nestačí ji
jen deklarovat, ale musíme ji přiřadit hodnotu okamžitě při deklaraci
(deklarace + inicializace = definice proměnné) -- později by se nám to již
nepovedlo.

	const int N;
	N = 10       // error: assignment of read-only variable 'M'

Všimněte si, že nezáleží na pořadí `const` a `int`, oba následující zápisy jsou
platné.

	const int N = 10;
	int const M = 20;

Jak jsem řekli, hodnotu jednou definované konstanty nelze později změnit.

	int N = 20; // CHYBA: Nelze změnit hodnotu N.

	[Poznámka] Pokud použijeme ukazatel, jde to: TODO, BUT: You should not being
    changing the const value) c++ const_cast<>

Použití `const` namísto `#define`;

## Ukazatele a `const`

viz dále oddíl [Ukazatele a modifikátor `const]

<!--
================================================================================
================================================================================
POINTERS
-->


<!--
================================================================================
================================================================================
ARRAYS
-->

# Pole

---

+ při deklaraci musíme zadat celočíselnou hodnotu větší než nula.
+ prvky pole nesmí být typu:
	+ reference
 	+ funkce
 	+ abstraktní třída
 	+ void

## Jak vytvořit jednorozměrné pole a přistupovat k jeho prvkům

### Vytvoření standardního pole

Standardním polem myslíme pole, ketré je přímo zabudované do jazyka (C, C++),
tedy nikoliv rozšíření jako `std::array` (viz dále).

Deklarace pole o velikosti tří prvků: `int arr[3]`;

Nastavení hodnot prvků pole pomocí indexu.

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

**Inicializace pole pomocí výčtu všech hodnot:**

	int arr[3] = {1, 2, 3};

&hellip; je totéž jako předchozí zápis.

**Pozor:** Nelze zadat více prvků než jsme deklarovali v `[]`!

	int arr[5] = {1, 2, 3, 4, 5, 6} // Chyba!

Pokud pole rovnou inicializujeme nemusíme jeho velikost zadávat -- překladač si
ji doplní sám.

	int arr[] = {1, 2, 3, 4, 5};
	int arr[] {1, 2, 3, 4, 5};    // rovnítko nemusíme zadávat (pouze C++)

**Inicializace pole pomocí všech prvků na stejnou hodnotu:**

	int arr[5] = {};   // všechny hodnoty se inicializují na hodnotu 0
	int arr[5] = {0};  // totéž jako předchozí

Rovnítko (v C++) můžeme vynechat:

	int arr[5] {};
	int arr[5] {0};

**Pozor:** Bez udání velikosti ho nelze inicializovat prvky na nulovou hodnotu!

	int arr[] = {};   // Nelze!
	int arr[] = {0};  // Nelze!

**Pozor:**
Prvky pole nelze inicializovat na hromadně na jinou hodnotu než nulovou!

	int arr[5] = {5}  // Nastaví první prvek na 5 a ostatní na hodnotu 0.

**POZOR:** Nelze přiřadit jedno pole jako hodnotu druhému poli!

	int arr1[3] = { 1, 2, 3};
    int arr2[3] = arr1; // CHYBA!

### Vytvoření pole s pomocí ukazatele a operátoru `new`

Vytvoří pole prvků na haldě (*heap*) a nastaví ukazatel na jeho první prvek;

Deklarace pole:

	int *arr = new int[5];            // po deklaraci obsahuje pole náhodné hodnoty

Definice pole:

	int *arr = new int[5] {};         // všechny hodnoty pole jsou nastaveny na 0
    int *arr = new int[5] {0};        // stejné jako předchozí příklad
    int *arr = new int[5] {1, 2, 3};  // obsahuje zadané hodnoty a dále doplněné 0

**Pozor:** Pamět musíme z paměti později sami uvolnit:

	delete [] arr;

### Vytvoření pole s použitím šablony `std::array` (C++11)

	std::array<int, 5> arr = {1, 2, 3, 4, 5};   // (1)
	std::array<int, 5> arr{ {1, 2, 3, 4, 5} };  // (2) Oboje složené závorky jsou nutné.

Přistup k prvkům pole (1)

	for (unsigned int i = 0; i < 5; i++)
	    printf("%d", arr[i]);

	for (unsignedint i = 0; i < arr.size(); i++)
        printf("%d", arr[i]);

	for (int item : arr)
		printf("%d", arr[i];

## Jak vytvořit standardní dvourozměrné pole

      0 1 2 3 4
     +---------+
	0| | | | | |
     +---------+
	1| | | | | |
	 +---------+
	2| | | | | |
	 +---------+

## Jak vytvořit standardní pseudo-dvourozměrné pole a přistupovat k jeho prvkům

	int WIDTH = 5;
	int HEIGHT = 3;

	int arr[WIDTH * HEIGHT];

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			arr[]
		}
	}

#### Jak zjistit počet prvků pole

+ Použitím funkce `sizeof()` ANSI/ISO C

		int arr_size = sizeof(arr) / sizeof(arr[0]);


+ Použitím funkce `size()` z `std::array`

		int arr_size = arr.size();

    [http://en.cppreference.com/w/cpp/container/array](http://en.cppreference.com/w/cpp/container/array)


#### Co znamená `(int const& arg)`

Pozor: v tomto případě není `&` tzv. adresní operátor! Poznamenejme ještě, že zápis:

	void function(int const &);

je stejný jako:

	void function(const int &);

Dále víme, že datové typy se v C++ čtou zprava doleva takže:

	int const &

#### Co je to reference

Reference je něco jako konstantní ukazatel:

	int i = 10;
	int j = 20;

	int *const p = &i;
	int &r = &i;

	p = j; // Chyba, nelze změnit...
	r = j; // Chyba, nelze změnit...

[http://stackoverflow.com/a/596750/2490538](http://stackoverflow.com/a/596750/2490538)

#### Reference vs Ukazatel

Ukazatel můžeme změnit

	int i = 10;
	int j = 20;

	int *p;
	p = &i;
	p = &j;

Reference je jen další zástupné jméno pro pojmenovanou hodnotu (proměnnou);
Musíme ji přiřadit "hodnotu" při její deklaraci a nemůžeme ji již změnit;

	int &k = i; // j můžeme nyní volat jménem k

Pokud změníme `i` hodnotu je dostupná i pod jménem `k`.

	i = 30;
	// k je také 30

	k = j // error

---

# Kompilace

## GCC, G++, Clang

## Make, Automake

## Vytvoření sdílené knihovny

.a, .lib

## Vytvoření dynamické knihovny

.so, .dll

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# Organizace zdrojových souborů

---

Rozdělení souborů

+ **zdrojový** soubor *source file* (`.c` nebo `cpp`)
+ **hlavičkový** soubor *header file* (`.h` nebo `hpp`)

Proč rozdělujeme soubory

+ zvyšuje rychlost kompilace
+ zlepšuje organizaci souborů
+ umožňuje znovupoužití kódu
+ umožňuje sdílení kódu
	+ mezi projekty
  	+ mezi programátory

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# C++ Reference

---

cstdarg/stdarg.h

+ va_list
+ va_start
+ va_arg
+ va_end
+ va_copy

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# Ukázky

---

**XorSwap**

	template <class T>
	void XorSwap (T *x, T *y)
	{
	     if (x != y)
	     {
	         *x ^= *y;
	         *y ^= *x;
	         *x ^= *y;
	     }
	 }

**AddSwap**

	template <class T>
	void AddSwap (unsigned T *x, unsigned T *y)
	{
	     if (x != y)
	     {
	         *x = *x + *y;
	         *y = *x - *y;
	         *x = *x - *y;
	     }
	 }

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

**Kdy použít `size_t`?**

Použijem vždy, když očekáváme nezáporný integer.
Here's how stddef.h defines it:

	typedef unsigned long size_t;

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# Benchmarking

---

http://stackoverflow.com/questions/483164/looking-for-benchmarking-code-snippet-c

<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# C++ Coding Standard (Style Guide)

---

+ [http://www.possibility.com/Cpp/CppCodingStandard.html#pnames](http://www.possibility.com/Cpp/CppCodingStandard.html#pnames)
+ [http://duramecho.com/ComputerInformation/WhyCPointers.html](http://duramecho.com/ComputerInformation/WhyCPointers.html)
+ ttp://stackoverflow.com/questions/10252837/pointer-to-array-c](http://stackoverflow.com/questions/10252837/pointer-to-array-c)
+ [http://en.cppreference.com/w/cpp/container/array](http://en.cppreference.com/w/cpp/container/array)
+ [http://www.cplusplus.com/doc/tutorial/arrays/](http://www.cplusplus.com/doc/tutorial/arrays/)
+ [http://stackoverflow.com/questions/201101/how-to-initialize-an-array-in-c](http://stackoverflow.com/questions/201101/how-to-initialize-an-array-in-c)
+[http://stackoverflow.com/questions/1065774/c-c-initialization-of-a-normal-array-with-one-default-value](http://stackoverflow.com/questions/1065774/c-c-initialization-of-a-normal-array-with-one-default-value)
+[http://www.codeproject.com/Articles/7042/How-to-interpret-complex-C-C-declarations#right_left_rule](http://www.codeproject.com/Articles/7042/How-to-interpret-complex-C-C-declarations#right_left_rule)

+[http://en.wikibooks.org/wiki/C%2B%2B_Programming](http://en.wikibooks.org/wiki/C%2B%2B_Programming)


+ Použití klíčového slova `explicit` pro kontruktor.

Klíčové slovo explicit zamezuje konstruktoru implicitní konverzi paramateru.

```
class SomeClass {
  public:
    explicit SomeClass(int i) m_i(i) {
        // code here
    }
}
```



# Ukazatele (*Pointers*)
---

### Obsah

+ [Paměť počítače](#)
+ [Definice ukazatele](#)
+ [Ukazatel na základní typ](#)
+ [Ukazatel na typ `NULL`](#)
+ [Ukazatel na typ `void`](#)
+ [Ukazatel na složené typy](#)
+ [Ukazatel na ukazatel](#)
+ [Ukazatel na funkci](#)
+ [Ukazatelová aritmetika](#)
+ [Porovnávání ukazatelů](#)
+ [Přetypování ukazatele](#)
+ [Ukazatel na pole](#)
+ [Ukazatel na prvek pole](#)
+ [Ukazatel a modifikátor `const`](#)
+ [Ukazatel na strukturu](#)
+ [Ukazatel na objekt](#)
+ [Ukazatel vs reference](#)

## Paměť počítače
---

Adresy jednotlivých buňek zapisujem v hexadecimálním tvaru. ˇčíslo v xexadecimálním tvaru předznamenáváme `0x`. Převod  z hexadecimálního tvaru do dekadického zde [todo](#).

    0x00ADA03
      |
      +------> číslo v HEX tvaru

### RAM (*Random Access Memory*)

      OBSAH   ADRESA (HEX)
    +-------+
    |       | 0x00ADA03
    +-------+
    |       | 0x00ADA04
    +-------+
    |       | 0x00ADA05
    +-------+
    |       | 0x00ADA06
    +-------+

       ...

    +-------+
    |       | 0x00ADA10
    +-------+

## Definice ukazatele (*pointer* a *pointee*)
---

Ukazatel (angl. *pointer*) je jeden ze základních datový typů jak v jazyce *C* tak i *C++*. Podobně jako proměnná, která je pojmenovaným míste v paměti, na kterém se uchovává nějaká hodnota, je ukazatel

## Ukazatel na základní datové typy
---

Mezi základní datové typy budeme počítat `char`, `short`, `int`, `long` `float` a `double`. Ukazatale na složené datové typy jako jsou struktura a pole si ukážeme dále.

Rozlišujeme mezi pojmy *pointer* a *pointee* &mdash; pointer je prvkem, který někam ukazuje a pointee je naopak prvek, na který je ukazováno. Jinak řečeno pointer je referencí na nějaký prvek. (S pojmem reference se můžete setkat i v jazyce jako je Java.)

Pro deklaraci ukazatele používáme znak `*`, který je umístíme kamkoliv mezi jméno a typ ukazatele.

    int * p;

Deklarovali jsme proměnnou `p` jako *ukazatel* na typ `int`. I když to vypadá jednoduše, tak se zde na chvíli zastavíme a vysvětlíme si některé důležité vlastnosti takové deklarace.

Při případné kompilaci programu s deklarací `int * p;` se vytvoří proměnná typu ukazatel na datový typ `int`. To znamená, že se vyhradí v paměti místo které je dostatečně velké na to, aby se do ní uložila adresa paměti. Proměnná typu ukazatel většinou zabírá v paměti 4 byte. V tomto ohledu je jedno jestli ukazatel ukazuje ne typ `int` nebo `double` či jiný. Důvod, proč je u deklarace ukazatele důležité uvést na jaký typ bude ukazovat je ten, že tím určíme to, jak má program případně interpretovat data uložená na adrese, kterou ukazatel uchovává &mdash; , pokud s nimi budeme pomocí ukazatele pracovat.

Ukazatel opravdu není nic jiného než "obyčejná" proměnná, která uchovává adresu paměti, např. hodnotu `0x00ADA10`, ale při další manipulaci s proměnnou pomocí ukazatele a ukazatelové aritmetiky musí program vědět jak má interpretovat data uložená na této adrese. Pokud uložíme nějaká data do proměnné typu `int` nebo `double`, budou v paměti obvykle zabírat stejné místo (4 byte), ale to jak jsou tyto Byty respektive sekvence bitů interpretovány programem se zásadně liší! [viz způsob uložení čísel v počítači](#).

Další důležitou poznámkou je, že pouhou deklarací pouze vyhradíme místo v paměti &mdash; nepřiřadíme tím proměnné žádnou hodnotu a to je u ukazatelů obzvláště nebezpečné a může to vést k záludným chybám v programu. Takovému neinicializovanému ukazateli se říká

Pro určení, kam má ukazatel směřovat, použijeme znak `&`, který umístíme před název proměnné.

    int * pointer = & pointee;
    [*] ---> (1)

Stejně jako proměnné bysme měli přiřadit hodnotu, tak ukazateli bysme měli přiřadit adresu proměnné.

Stejne jako při deklaraci jiného datového typu musíme určit na jaký typ může ukazovat, adresu jakého typu může uchovávat.

    int* ptr;
    int *ptr;
    int * ptr;

Všechny zápisy jsou povolené, avšak **doporučit lze druhý nebo třetí zápis**. Podívejme se totiž, jak situace vypadá při vícenásobné deklaraci.

    int* ptr, i;

Zde je `ptr` opravdu ukazatel, ale `i` je obyčejná proměnná typu `int`. Lepší je tedy přisunout znak více nebo úplně těsně ke jménu ukazatele.

    int *ptr, i;
        ^     ^___ proměnná typu `int`
        |_________ ukazatel na typ `int`

## Operátor adresy `&` a dereference `*`
---

### Inicializace ukazatele pomocí adresního (referenčního) operátoru `&`

Ukazatel bychom  měli vždy inicializovat [poznámka]. Neinicializovaný ukazatel (*wild pointer*) je zdrojem mnoha potíží! K inicializaci ukazatele slouží *referenční* též nazývaný *adresní* operátor (*reference/adress-of operator*). Pomocí něho získáme adresu proměnné, kterou inicializujeme náš ukazatel.

    int *ptr; // tady to není OK!

    int i = 42;
    ptr = &i;

nebo rovnou

    int i;
    int *ptr = &i;

    i = 42;
    *p = 43;



### Dereferenční operátor `*`

Hned na začátku jsme si vysvětlili, že rozeznáváme *pointer* a *pointee*. Pokud máme vždy jasno, co je v našem kódu pointer a pointee, nemůže nás mást, že znak * se v souvislosti s ukazateli používá dvěma různými způsoby: a to pro deklaraci nového ukazatele, tak získání hodnoty z adresy, kam ukazatel směřuje

Vytvoříme-li nový ukazatel, který ukazuje na místo, kde je uložena nějaká proměnná, pak musí  existivat způsob, jakým získat hodnotu proměnné, jen pomocí ukazatele. Pro tento účel se opět použije * av3ak v jin9m kontextu:

    int pointee = 1;
    int *pointer = &pointee;






&, *

### Inicializace ukazatele na `NULL`

Pokud mu nechceme přiřadit adresu ihned (pomocí adresního operátoru), alespoň ho inicializujeme na hodnotu `NULL`. I to mů že vést k potížím, při snaze získat hodnotu (dereference) ukazatele inicializovaného na NULL, alespoň však můžeme použít test `if (ptr == NULL)` aj. Ukazateli inicializovanému na hodnotu `NULL` se říká *null pointer* a důležité místo v datových strukturách jako je spojový seznam aj.

    int *p = 0;

nebo můžeme použít definované makro `NULL`. Toto makro bývá nejčastěji definované v jednom z těchto  hlavičkových souborů `stdio.h`, `stdlib.h`, `stddef.h` (v C++: `cstdio`, `cstdlib`, `cstddef`).

    int *p = NULL;

**Pozor:** Ukazatel na `NULL` nemůžeme dereferencovat, stejně jako neinicializovaný ukazatel:

    int i = &p;  // CHYBA!

Avšak narozdíl od neinicializovaného ukazatele můžeme alespoň testovat na hodnotu `NULL`:

    if (p != NULL) {
        int i = &p;
    }

### Inicializace ukazatele na `void`

Pokud v čase kompilace nevíme na jaký typ bude náš ukazatel ukazovat, můžeme definovat tzv. ukazatel na typ `void`. Pak je možné takový ukazatel inicializovat na libovolný typ. Je zřejmé, že zde vyvstávají problémy s typovou kontrolou. Nicméně přesně takto se postupuje, pokud chceme vytvořit něco jako generickou datovou strukturu.

    void * p;

    int i = 1;
    double d = 1.2;
    char c = 'a';

    p = &i;
    p = &d;
    p = &a;


## Ukazatel a struktura (unie)
---

### Ukazatel na strukturu

`(*p).item` vs `p->item`

    struct cube {
        double a;
        double b;
        double c;
    } mycube;

    struct cube *cube_ptr = mycube;

    mycube->a = 1.0;
    mycube->b = 2.0;
    mycube->c = 3.0;

    double volume = mycube->a * mycube->b * mycube->c;

### Struktura s ukazatelem na strukturu

    struct node {
        double value;
        struct node *prev;
        struct node *next;
    }


## Ukazatel a pole
---

Rozdíl mezi **ukazatelem na pole** a **ukazatelem na prvek pole** je důležité znát.

Formula for computing the address of ptr + i where ptr has type T *. then the formula for the address is:

addr( ptr + i ) = addr( ptr ) + [ sizeof( T ) * i ]

For for type of int on 32bit platform, addr(ptr+i) = addr(ptr)+4*i;

### Ukazatel na prvek pole

Mějme pole se třemi prvky typu `int`:

    int arr[] = {1, 2, 3};

Potom ukazatal na typ `int` můžeme deklarovat stejně těmito dvěma způsoby:

    int(*p);  // (1)
    int *p;   // (2) závorky kolem ukazatele nejsou nutné

Oba následující příklady jsou stejné a nastavují ukazatel **na první prvek** pole.<a name="uk"></a>

    p = &arr[0];  // reference na první prvek pole (jeho adresa)
    p = arr;      // taktéž reference na první prvek pole


    p1 = arr + 3 ; // p1 == & arr[ 3 ]
p2 = p1 - 2 ; // p1 == & arr[ 1


### Průchod polem pomocí ukazatele

#### Jednorozměrné pole

Ještě jednou vše v jednom zápise a hned si ukážeme, jak můžeme *traverzovat* polem pomocí ukazatele a operátoru inkrementace `++` a dekrementace `--`.

    int arr[] = {1, 2, 3};
    int *p = arr;

Průchod polem od začátku ke konci:

    printf("%d", *p);  // -> 1
    p++;

    printf("%d", *p);  // -> 2
    p++;

    printf("%d", *p);  // -> 3

Průchod polem od konce k začátku:

    printf("%d", *p);  // -> 3
    p--;

    printf("%d", *p);  // -> 2
    p--;

    printf("%d", *p);  // -> 1


**Pomocí cyklu `for`:**

Není tajemstvím, že překročit mez pole pomocí ukazatele je častou chybou!
Místo postupné inkrementace, zvláště při průchodu velkým polem, můžeme použít cyklus.

    for (int i = 0; i < 3; i++)
    {
        printf("%d", *p);
        p++;
    }

nebo

    for (int i = 0; i < 3; i++, p++)
    {
        printf("%d", *p);
    }

Pokud neznáme předem velikost pole ani jeho typ, lze počet prvků spočítat pomocí operátoru `sizeof` a použít ho jako mezní honotu v cyklu. Počet prvků pole dostaneme, pokud celkovou velikost pole dělíme velikostí prvního prvku (velikost je v *Byte*).

    const int SIZE = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < SIZE; i++, p++)
    {
        printf("%d", *p);
    }

#### Dvourozměrné pole


## Ukazatel na objekt
---


## Ukazatel na ukazatel
---

## Ukazatel na funkci
---

Stejně jako máme ukazatel na jakýkoliv typ (int, double pole atd.), můžeme ho deklarovat jako ukazatel na funkci.


Mějme funkci pro součet dvou čísel:

    int Add(int x, int y)
    {
        return x + y;
    }

Ukazatel na takovouto funkci deklarujeme takto:

    int (*funcPtr)(int, int);
    ^    ^         ^    ^
    |    |         |    |
    |    |         +----+-- typy argumentů předávané funkce
    |    +----------------- ukazatel na funkci
    +---------------------- typ návratové hodnoty funkce

Nyní můžeme našemu ukazateli předat referenci na funkci, která splňuje jeho deklaraci a ukážeme si, že obě následující varianty jsou možné (podobně jako u ukazatele na prvek pole). [^](#uk)

    funcPtr = &Add;
    // nebo
    funcPtr = Add;

Uděláme to ještě jednou spolu s předchozí deklarací.

    int (*funcPtr)(int, int) = &Add;
    // nebo
    int (*funcPtr)(int, int) = Add;

**Pozor:** Všimněme si, že **vynecháváme závorky** za názvem funkce. To by znamenalo, že chceme ukládat návratovou hodnotu funkce, a to nechceme!


 Nyní můžeme tento ukazatel používat stejně jako funkci.

    int result = *(funcPtr)(1, 2);  // -> 3

### Kde se používají?

+ Pokud chceme vztvořit pole ukazatelů na funkce.

        void f1() { printf("f01\n"); }
        void f2() { printf("f01\n"); }
        void f3() { printf("f01\n"); }

        void(*func[])() = { f1, f2, f3 };

        // nebo

        typedef void(*funcPtr)();
        funcPtr func[] = { f1, f2, f3 };

        // funkce voláme jako

        func[0]();  // -> f01
        func[1]();  // -> f02
        func[2]();  // -> f03


+ Pokud chceme předat funkci jako parametr jiné funkci (např. tzv. *callback*).

## Ukazatelová (adresní) aritmetika
---

S ukazateli můžeme počítat podobně jako s celočícelnými proměnnými jsem však omezeni na **sčítání**, **odčítání**, **porovnání** a sepciální případy sčítání a odčítání, kterými jsou **inkrementace** a **dekrementace**.


### Sčítání a odčítání


Aritmetiku můžeme aplikovat jak na samotné ukazatele tak na hodnoty, na které ukazují. Nechť `p` je ukazatel a `i` je proměnná.

    int i = 42;
    int *p = &i;

Pak všechny následující zápisy mění hodnotu na kterou ukazuje `p`.

    *p = *p + 1;  // i je 43
    (*p)++;       // i je 44

    *p = *p - 1;  // i je 43
    (*p)--;       // i je 42

    *p = *p - 2;  // i je 40

    ++*p;         // i je 41
    --*p;         // i je 40

    *p = *p + 2;  // i je 42

V tomto případě je jedno jestli použíjeme *pre*/*post*-inkrementaci respektive dekrementaci. Všimněme si ale, že při postinkrementaci či postdekrementaci musíme použít uzávorkování `(*p)++` a `(*p)--`. Důvod je ten, že vyhodnocení takového výrazu probíhá zprava.

Přičtení nebo odečtení celočíselné hodnoty k ukazateli znamená vlastně posun v paměti o *příslušný* počet bytů. O kolik bytů dopředu nebo vzad se pohybujeme určuje to, kolik zabírí v paměti datový typ, na který ukazatel ukazuje.

Mějme pole a ukazatel jemuž přiřadíme adresu druhého prvku pole (prvek s indexem 1):

    int arr[] = {1, 2, 3};
    int *ptr = &arr[1];

Pak můžeme procházet pamětí (pole) pomocí přičítání nebo odčítání hodnoty k ukazateli. Tato hodnota je rovna počtu bytů datového typu, na který ukazatel ukazuje. Např. pro typ `int` je na většině počítačů vyhrazeno 4 byte. Zápis ptr + 1, znamená posun v paměti o 4 byty dopředu a zápis ptr - 1 znamená posun o stejný počet bytů zpět.

    printf( "%d", *(ptr - 1));
    printf( "%d", *(ptr) );
    printf( "%d", *(ptr + 1));

**Pozor**: U zápisu *(ptr) lze závorky vynechat, nikoliv dalších výrazů, tedy uzávorkování je zde nutné `*(ptr + 1)`!

Stejný zápis s opravdovou změnou hodnoty ukazatele:

    ptr = ptr - 1;
    printf( "%d", *ptr); // => 1

    ptr = ptr + 1;
    printf( "%d", *ptr); // => 2

    ptr = ptr + 1;
    printf( "%d", *ptr); // => 3


Zápis `ptr = ptr + 1;` můžeme v tomto případě zapsat úsporněji:

    ptr += 1; ptr -= 1;

    // nebo
    ptr++;
    ++ptr;
    ptr--;
    --ptr;

Tot se vlastně děje na pozadí, pokud napíšeme např `ptr = ptr + N`

        (ptr + (N * sizeof(*ptr)));

### Další příklady

    int length(char *s)
    {
       char *str = s;
       while(*str++);
       return str - s;
    }


    while(*n++ != '\0'){
        len++;
    }

### Porovnávání ukazatelů

## Přetypování ukazatele
---

## Ukazatel a modifikátor `const`
---

### Ukazatel na pojmenovanou konstantu

Pokud má ukazatel ukazovat na pojmenovanou konstantu, musíme modifikátor `const` uvést už při deklaraci. Stejně jako u definice konstantní proměnné můžeme použít oba možné zápisy.

    const int *p = &N;
    int const *q;

    [int const] [*p] = [&N;]
    |           |      +----> přiřazená hodnota (adresní operátor)
    |           +-----------> deklarace ukazatele
    +-----------------------> typ proměnné, na kterou se ukazuje

### Konstantní ukazatel na proměnnou

Pokud požadujeme, aby ukazatel ukazoval na stále stejné místo v paměti (stejnou proměnnou) můžeme i jemu přiřadit modifikátor `const`. Ten **musí následovat vždy za znakem `*`** a hlavně musíme ukazateli přiřadit referenci (`&` operátor reference), stejně jako konstantní proměnné přiřazujem hodnotu.

    int q = 10

    int *const p = &q;

### Konstantní ukazatel na pojmenovanou konstantu`.

Tou mohou být např. adresy proměnných `N` a `M`. Jak vidíme, to na co ukazatel ukazuje, se dá zapsat opět dvěma platnými způsoby.

    const int *const p = &N;
    int const *const q = &M;

Protože můžeme tvořit ukazatele na ukazatele a ještě přidávat různě modifikátor `const`, řekneme si o pravidle RTL.

### RTL (Right-to-Left) nebo též spirálové pravidlo pro ukazatele

Vše čteme zprava doleva, či po spirále, jak uvádí odkaz níže.


**Příklad 1**

         +-------->
         | +-->   |
         | |  |   |
         | |  |   |
    char * var[10];
    ^    ^    |   |
    |    |    |   |
    |    <----+   |
    |             |
    <-------------+

+ **Co je `var`?**<br>
  Vyrazíme od `var` nahoru a doprava (po směru hodin), pak dolu a narazíme na `[10]`.<br>
  Vidíme, že `var` je pole&hellip;

+ **Pole jakých prvků?**
  Pokračujeme dolu, jakoby po spirále (stále po směru hodin) a narazíme na `*`.<br>
  Jde o pole ukazatelů&hellip;

+ **Ukazatelů na co?**
  Pokračujeme po spirále, narazíme na `;`, pokračujeme dále a před námi je `char`.<br>
  Jde o pole ukazatelů na datový typ `char`.

Další příklady zde: [http://www.c-faq.com/decl/spiral.anderson.html](http://www.c-faq.com/decl/spiral.anderson.html)


### Ukázky

    char **p1;              // ukazatel na ukazatel na typ `char`
    const char **p2;        // ukazatel na ukazatel na konstantní typ `char`
    char *const *p3;        // ukazatel na konstantní ukazatel na typ `char`
    const char *const *p4   // ukazatel na konstantní ukazatel na konstantí typ `char`


## Reference (pouze C++)
---

[http://www.eternallyconfuzzled.com/tuts/languages/jsw_tut_pointers.aspx#ptrtype](http://www.eternallyconfuzzled.com/tuts/languages/jsw_tut_pointers.aspx#ptrtype)

## Pointers to members (pouze C++)
---

## Ukazatel na objekt (pouze C++)
---

Velmi využívaný je ukazatel na objekt.

    T obj = new T();

    T * objPtr = &obj;

Stejně jako máme ukazatel na jakýkoliv typ (int, double pole atd.), můžeme ho deklarovat jako ukazatel na objekt




---

Stejně jako máme ukazatel na jakýkoliv typ (int, double atd.), můžeme ho deklarovat jako ukazatel na pole prvků.

    int arr = {1, 2, 3};

    int (*p)[3] = &arr;


**Pozor:** Kulaté závorky jsou důležité, jinak by šlo o jiný případ ukazatele[doplnit odkaz]! Stejně tak velikost uvedená v hranatých závorkách!

Pokud neznáme velikost pole předem může být zadána jako konstanta (`SIZE`) nebo jako výraz, nebo dosadíme známý výraz pr výpočet velikosti neznámého pole:

    int (*p)[SIZE] = &arr;

nebo

    int (*p)[sizeof(arr) / sizeof (arr[0])] = &arr;

**Pozor:** Argument `SIZE` opravdu musí být typu `const int`, alespoň MVC++ kompilátor to vyžaduje.


## Vztah ukazatele a reference
---

[http://www.codeproject.com/Articles/4894/Pointer-to-Pointer-and-Reference-to-Pointer](http://www.codeproject.com/Articles/4894/Pointer-to-Pointer-and-Reference-to-Pointer)

+ **Proč předávat parametr funkce jako ukazatel?**
+ **Proč definovat návratovou hodnotu funkce jako ukazatel?**

ukazatele můžeme uložit do pole

dvojrozměrné pole jsou pole ukazatelů na pole.

    int a[10][20]; // deklarace dvojrozměrného pole 10 x 20

    int * b[10];   // deklarace pole pro deset ukazatelů na typ `int`

    int n
    int *p

    int* i, j
    vs
    int *i, j

    char **argv

    int array[4][3];

    int (*p)[3];  // *ukazatel na pole* pro tři prvky typu `int`
    int *p[3];    // *pole pro ukazatele* na typ `int`

    int **p1;     // p1 je ukazatelem  na ukazatel  na typ `int`
    int *&p2;     // p1 je referencí   na ukazatel  na typ `int`

    int &*p3;     //  ERROR: Pointer    to a reference is illegal.
    int &&p4;     //  ERROR: Reference  to a reference is illega

    hvězdička nedpředchází křížek


+ Referenci nemůžeme přiřadit NULL.
+ Referenci nelze změnit hodnotu.


    double x = 10;
    double y = 10;


    double *p1 = &x;
    double *p3 = &y;

    // int *p2 = new int;  // ukazuje na nepojmenovaný int

Reference

    double &r1 = x;
    double &r2 = y;


### Předání parametru pomocí ukazatele a reference


    void swap_with_ptr(int *x, int *y)
    {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }


    void swap_with_ref(int &x, int &y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }


    swap_with_ptr(&x, &y);
    swap_with_ref(x, y);


Pokud se koukneme na volání obecné funkce `swap(x, y);`, nemůžeme si být jisti, jestli dosazujeme za parametry hodnoty (*call-by-value*) nebo předáváme reference, bez toho abysme se podívali definici funkce.

### Reference na ukazatel


    func_A(int *&arg)
    {

    }

    func_B(int *arg)
    {

    }

### pass-by-value

### pass-by-reference



### Reference na ukazatel


### Ukazatel na ukazatel



Pokud předáváme ukazatel hodnotu, vytvoří se jeho kopie uvnitř funkce. Samotný ukazatel je neměnný!

    #include <iostream>

    int global_i = 0;

    void fun(int *ptr)
    {
        ptr = &global_i;
    }

    int main()
    {
        int local_i = 1;
        int *ptr = &local_i;

        std::cout << *ptr << endl; // 2

        fun(ptr);

        std::cout << *ptr << endl;  // 2

        return 0;
    }




<!--
================================================================================
================================================================================
================================================================================
================================================================================
================================================================================
-->

# Správa paměti v C
---

## Dynamická alokace paměti
--

### Zásobník

### Halda (*heap*)

Všecchny následující funkce najdem v hlavičkovém souboru `<stdlib.h>`

### `malloc()`

Funkce `malloc()` alokuje paměť specifikované velikosti (v bytech) a vrací ukazatel na záčátek tohoto bloku paměti.

    void *malloc(size_t size);

**Příklad**

    char *ptr = malloc(5);

                  -----------
    [ptr]-------->| | | | | |
                  -----------
                   0 1 2 3 4

V předchozím příkladě jsme alokovali blok paměti o velikost 5 byte a vytvořili ukazatel na `char` ukazující na začátek paměti (adresu první buňky). Protože v případě C je na všech platformách vyhrazen pro typ `char` 1 byte, můžeme jednoduše psát `malloc(5)`.

                  -----------
    [ptr]-------->|a|b|c|d|e|
                  -----------
                   0 1 2 3 4


### Type casting

    *ptr = (int *) malloc( sizeof(int) );



### Vždy testujeme jestli byla paměť opravdu přidělena

    if (ptr == NULL)
    {
        printf("ERROR");
        return -1;
    }

Namísto `printf` je lepší použít `fprintf`:

    fprintf(stderr, "Failed to allocate memory for chars.");

### `calloc()`

Funkce `calloc()` alokuje paměť specifikované velikosti v bytech a naství je na hodnotu 0.


### Rozdíl mezi `malloc()` a `calloc()`

Funkce `malloc` pouze alokuje potřebné množství paměti, zatímco `calloc` inicializuje hodnoty proměnných na 0.


## Příklady
---

Vytvoření pole neumožňuje za běhu programu změnit jeho velikost.

    int array[10];

Vytvoříme ukazatel na typ `int`, který ukazuje na začátek bloku paměti o velikosti 10 * velikost typu `int` (obvykle 4 byty, tedy 10*4=40 byte)

    int *array_ptr1 = malloc(10 * sizeof(int));

Vytvoříme ukazatel na typ `int`, který ukazuje na začátek bloku paměti o velikosti 10 * velikost typu `int` a inicializuje je nahosnotu 0;

    int *array_ptr2 = calloc(10, sizeof(int));

### Ověření příkladů

    for (array_ptr1 != NULL; array_ptr1++) {
        printf("%d", )
    }

### `realoc()`

Funkce `realloc()` zvětší nebo zmenší velikost alokované paměťi.

### `free()`

Funkce `free()` uvolní alokovanou paměť.

# Správa paměti v C++
---

### `new` a `new[]`

### `delete` a `delete[]`


## Odkazy
Odkaz: http://www.stroustrup.com/bs_faq2.html#constplacement


## Chytré ukazatele (**Smart Pointers**)
---

A smart pointer is an object that acts, looks and feels like a normal pointer but offers more functionality. In C++, smart pointers are implemented as template classes that encapsulate a pointer and override standard pointer operators. They have a number of advantages over regular pointers. They are guaranteed to be initialized as either null pointers or pointers to a heap object. Indirection through a null pointer is checked. No delete is ever necessary. Objects are automatically freed when the last pointer to them has gone away. One significant problem with these smart pointers is that unlike regular pointers, they don't respect inheritance. Smart pointers are unattractive for polymorphic code. Given below is an example for the implementation of smart pointers.

    template <class X>
    class smart_pointer
    {
              public:
                   smart_pointer();                          // makes a null pointer
                   smart_pointer(const X& x)            // makes pointer to copy of x

                   X& operator *( );
                   const X& operator*( ) const;
                   X* operator->() const;

                   smart_pointer(const smart_pointer <X> &);
                   const smart_pointer <X> & operator =(const smart_pointer<X>&);
                   ~smart_pointer();
              private:
                   //...
    };

    smart_pointer <employee> p= employee("Harris",1333);
    cout<<*p;
    p->raise_salary(0.5);

## Proč?

    MyObject *obj_ptr = new MyObject();
    obj_ptr->DoSomething();
    delete obj_ptr;

Co když se vyskytne výjimka při volání `DoSomething()`? Pak se neuvolní pamět!

Řešení:


### **unique pointer**

`std::unique_ptr` v hlavičkovém soubrou `<memory>`

### **scoped pointer**

`boost::scoped_ptr`

### **shared pointer**

`std::shared_ptr`
`boost::shared_ptr`


### **weak pointer**

`std::weak_ptr`
`boost::weak_ptr`

### **intrusive pointer**


## Odkazy

+ [http://stackoverflow.com/a/106614/2490538](http://stackoverflow.com/a/106614/2490538)
+ [http://www.boost.org/doc/libs/1_55_0/libs/smart_ptr/smart_ptr.htm](http://www.boost.org/doc/libs/1_55_0/libs/smart_ptr/smart_ptr.htm)


# RAII (*Resource Acquisition Is Initialization*)

---
