# course-c

__The modern C99+ language course.__

## Programovací jazyk C

- 1972, Denis Ritchie, Brian Kernighan
- ANSI C, C89, C99, C11, ...

## Kompilace

    gcc file_name.c --std=c11 -o output_name (default a.exe)

 ## Komentáře

- víceřádkový (multi-line) `/<star> comment <star>/` původně jen ten
- jendořádkový (one-line) `// comment` dodaný dalšími verzemi

```c
// This is a one-line comment.

/* This
   is a multiline
   comment.
*/
```

## Primitivní datové typy

- `unsigned`, `char`, `short`, `int`, `long`, `float`, `double`

- Hlavičkový soubor `<limits.h>` definuje makra pro minimální a maximální hodnoty daných primitivních typů.

| Macro      | Value | Description
|------------|-------|------------
| CHAR_BIT   |
| INT_MAX    |       |
| INT_MIN    |       |
| UINT_MIN   |       |
| UINT_MAX   |       |
| SHRT_MIN   |       |
| SHRT_MAX   |       |
| USHRT_MAX  |       |
| LONG_MIN   |       |
| LONG_MAX   |       |
| ULONG_MAX  |       |
| LLONG_MIN  |       | C99, C++11
| LLONG_MAX  |       | C99, C++11
| ULLONG_MAX |       | C99, C++11

- Pokud potřebujem primitvní typ s přesně daným početm bitů, musíme vyýžít typy definované v hlavičkovém souboru `int

## Struktura: složený datový typ

- Klíčové slovo `struct`.
- Definice vlastního typu pomocí struct.
- Výchozí hodnoty neinicializovaných atributů.
- Inicilaizace atributů pomocí názvu.
- `struct S {...}` vs `typedef struct S {} S`;
- `struct`
  - no memory allocation

## Primitivní datové typy


## Přehled standardní knihovny

- `<assert.h>`
- `<ctype.h>`
- `<errno.h>`
- `<float.h>`
- `<limits.h>`
- `<locale.h>`
- `<math.h>`
- `<setjmp.h>`
- `<signal.h>`
- `<stdarg.h>`
- `<stddef.h>`
- `<stdio.h>`
- `<stdlib.h>`
- `<string.h>`
- `<time.h>`
- `<stdint.h>`


## Poznámky


- Jaký je rozdím mezi `void function();` a `void function(void);` v C repektive C++?.
- C++ není zcela kompatibilní s C.
- C++ zdědilo hodně problematických z C kvůli kompatibilitě s C.
- Struktura v C je POD (plain old data).


## References

- Modern C and What We Can Learn From It, https://www.youtube.com/watch?v=QpAhX-gsHMs
- https://docs.microsoft.com/en-us/cpp/c-language/static-assert-c?view=msvc-170