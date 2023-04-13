//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
        unsigned int decimal = 4294967295;
        unsigned int binary = 0b11111111111111111111111111111111;
        unsigned int oct = 037777777777;
        unsigned int hex = 0xffffffff;

        printf("%u\n", decimal); // 4294967295
        printf("%u\n", binary); // 4294967295
        printf("%u\n", oct); //  4294967295
        printf("%u\n", hex); //  4294967295

        printf("%o %x %#o %#x %#X", decimal, decimal, decimal, decimal, decimal);
        //37777777777, ffffffff, 037777777777, 0xffffffff, 0XFFFFFFFF
        //Format Specifier가 o이면 8진수(oct), x이면 16진수(hex), 앞에 #이 붙으면 진수 표현

    return 0;
}