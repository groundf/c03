#include <stdio.h>

#include <limits.h> // INTEGRAL TYPES MACROS/CONSTANTS

#include <float.h> // FLOATING POINT TYPES MACROS/CONSTANTS

#include <stdint.h> // FIXED BITS INTEGRAL TYPES MACROS/CONSTANTS


int main() {

    printf("The minimina and maximum values on this machine:\n");
    printf("-----\n");

    //# Integral types

    printf("The number of bits in a byte = %d\n", CHAR_BIT);

    // char
    printf("Minimum value of CHAR = %d\n", CHAR_MIN);
    printf("Maximum value of CHAR = %d\n", CHAR_MAX);
    printf("Minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("Maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
    printf("Maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

    // short
    printf("Minimum value of SHORT INT = %d\n", SHRT_MIN);
    printf("Maximum value of SHORT INT = %d\n", SHRT_MAX);
    printf("Maximum value of UNSIGNED SHORT INT = %d\n", SHRT_MAX);

    // int
    printf("Minimum value of INT = %d\n", INT_MIN);
    printf("Maximum value of INT = %d\n", INT_MAX);
    printf("Maximum value of UNSIGNED INT = %d\n", UINT_MAX);

    // long
    printf("Minimum value of LONG INT = %ld\n", LONG_MIN);
    printf("Maximum value of LONG INT = %ld\n", LONG_MAX);
    printf("Maximum value of UNSIGNED LONG INT = %ld\n", ULONG_MAX);

    // long long
    printf("Minimum value of LONG LONG INT = %lld\n", LLONG_MIN);
    printf("Maximum value of LONG LONG INT = %lld\n", LLONG_MAX);
    printf("Maximum value of UNSIGNED LONG LONG INT = %llu\n", ULLONG_MAX);

    //# Floating point types
    printf("---\n");

    printf("Minimum value of FLOAT (FLT_MIN) = %f\n", FLT_MIN);
    printf("Maximum value of FLOAR (FLT_MAX) = %f\n", FLT_MAX);

    printf("---\n");

    printf("FLT_ROUNDS = %d\n", FLT_ROUNDS);
    printf("FLT_RADIX = %d\n", FLT_RADIX);

    //# Fixed size integral types

    // Minimum width int types uint[N]_t where N = {8, 16, 32, 64}.
    // uint8_t, uint16_t, uint32_t, uint64_t

    // fastest minimum width int types
    // int_fast8_t
}