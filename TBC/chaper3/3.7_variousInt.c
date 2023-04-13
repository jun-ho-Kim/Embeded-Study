//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    char c = 65;
    short s = 32773;
    unsigned int ui = 3000000000U;
    long l = 65537L;
    long long ll = 12345678908642ll;

    printf("char = %hhd, %d, %c\n", c, c, c); // 65, 65 , A
    printf("short = %hhd, %hu, %d\n", s, s, s); // 5, 32773, -32763
    printf("unsigned int = %u, %d \n", ui, ui); // 3,000,000,000, -1,294,967,296
    printf("long = %ld, %hd \n", l, l); //65337, 1
    printf("long long = %lld, %ld \n", ll, ll); //12,345,678,908,642, 1,942,899,938

    return 0;
}