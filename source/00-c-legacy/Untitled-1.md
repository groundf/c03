=========
Vývoj v C
=========

Pro vývoj budeme používat operační systém Windows a Ubuntu instalovaný pomocí Windows Subsystem for Linux (WSL). Zdrojový kód budeme psát a ladit v editoru Visual Studio Code s příslušnými rozšířeními.


Pro kompilaci budeme používat GCC

Pro kontrolu správnosti práce s pamětí budeme používat Valgrind.

..code:: shell
    apt install valgrind


Kompilace + Linkování
=====================


Sestavení programu
==================


Sestavení knihovny
==================


Použití GDB pro potřeby sledování
=================================

GDB můžeme vyvolat nad binárkou takto:

    gdb

nastavíme break point

    break 12

odstraníme break point

    delete 12


Spustíme
    run


Sledování

    watch


    continue

Quit

    quit


Standardní knihovna
===================

* `<assert.h>`
* `<ctype.h>`
* `<errno.h>`
* `<float.h>`
* `<limits.h>`
* `<locale.h>`
* `<math.h>`, `<tgmath.h>`
* `<setjmp.h>`
* `<signal.h>`
* `<stdarg.h>`
* `<stddef.h>`
* `<stdio.h>`
* `<stdlib.h>`
* `<string.h>`
* `<time.h>`