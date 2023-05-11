#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool is_isogram(const char phrase[]);


int main()
{
    printf(
        "%d\n",
        // is_isogram("subdermatoglyphic")
        is_isogram("iso--   gram")
    );
    return 0;
}

// WARNNING: This only works for ASCII!
// COMPLEXITY: time = O(n^2) (worst); space = 2 * n

bool is_isogram(const char phrase[])
{
    if (NULL == phrase)
    {
        return false;
    }

    int phrase_len = snprintf(NULL, 0, "%s", phrase);

    if (phrase_len == 0)
    {
        return true;
    }

    char unique[phrase_len];
    unique[0] = tolower(phrase[0]);
    int unique_len = 1;

    for (int i = 1; i < phrase_len; i++)
    {
        for (int j = 0; j < unique_len; j++)
        {
            if ( (phrase[i] == '-') || isspace(phrase[i]))
            {
                continue;
            }

            if ( tolower(phrase[i]) == unique[j] )
            {
                return false;
            }
        }
        unique[unique_len] = tolower(phrase[i]);
        unique_len++;
    }

    return true;
}
