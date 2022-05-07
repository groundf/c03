# Správa projektu v C++ 

## CMAKE a externí závislosti

Problém:
Knihovna není instalována na našem systém nebo není dostupná potřebn verze knihovny. Knihovna je však dostupná v Github/Bitbucket atd. repozitáři a má svlastní CmakeLists.txt soubor.

Řešení:
Použijeme funcki [`ExternalProject_Add`](https://cmake.org/cmake/help/v3.5/module/ExternalProject.html).


Jestliže vytváříme aplikaci je dobré stejně separovat část kódu jako knihovnu, která je přilinkováná jak k výslednémů souboru s main funkcí, tak k kropejktu představujícíi testy....
