//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    unsigned int i = 0b1111111111111111;
    printf("%u\n", sizeof(unsigned int));
    printf("%u\n", sizeof(i));

    unsigned int j = 0b1111111111111111;
    unsigned int u = UINT_MAX;

    printf("%u\n", j);
    printf("%u\n", u);

    unsigned int u_max = UINT_MAX;
    unsigned int u_min = 0;
    signed int i_max = INT_MAX;
    signed int i_min = INT_MIN;

    printf("max of uint = %u\n", u_max);
    printf("min of uint = %u\n", u_min);
    printf("max of int = %d\n", i_max);
    printf("min of int = %d\n", i_min);

    unsigned int u_max_overflow = UINT_MAX + 1;
    char buffer[33];
    _itoa(u_max_overflow, buffer, 2);

    printf("demical: %u\n", u_max_overflow);
    printf("binary: %s\n", buffer);

    return 0;
}