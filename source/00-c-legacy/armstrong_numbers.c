
//
// RELEASE:  gcc <input>.c -o <output> -lm
// DEBUG  :  gcc -g <input>.c -o <output> -lm
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


bool is_armstrong_number(int candidate)
{
    int len = snprintf(NULL, 0, "%d", candidate);
    char* str = malloc(len + 1);

    snprintf(str, len + 1, "%d", candidate);

    int sum = 0;
    int num = 0;

    char dig[2];

    for (int i = 0; i < len; i++)
    {
        dig[0] = str[i]; dig[1] = '\0';
        num = atoi(dig);
        sum += pow(num, len);
    }

    bool result = (sum == candidate);

    free(str);

    return result;
}

// Tests
int main()
{
    printf(
        "%d %d %d %d %d \n",
        is_armstrong_number(9),
        is_armstrong_number(10),
        is_armstrong_number(153),
        is_armstrong_number(19474),
        is_armstrong_number(9926315)
    );

    return 0;
}