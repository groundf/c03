#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool is_isogram(const char phrase[]);


// Possible errors.
// Bus error
// Segmenation fault

int main()
{
    printf("%d\n", is_isogram("thumbscrew-jappingly"));

    return 0;
}


bool is_isogram(const char phrase[])
{
    if (NULL == phrase)
    {
        return false;
    }

    unsigned mask[26] = {0};
    unsigned index;

    for (char c = *phrase; (c != '\0'); c = *++phrase)
    {
        if ((c == '-') || isspace(c)) {
            continue;
        };

        index = (int)tolower(c) - (int)'a';

        if (mask[index])
        {
            return false;
        }

        mask[index] ^= 1;
    }

    return true;
}
