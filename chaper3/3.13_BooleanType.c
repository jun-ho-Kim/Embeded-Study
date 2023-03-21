//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("%u\n", sizeof(_Bool)); // 1byte

    _Bool b1;
    b1 = 0; // false
    b1 = 1; // true

    printf("%d\n", b1); //1

    bool b2, b3;
    b2 = true;
    b3 = false;

    printf("%d %d\n", b2, b3); // 1 0
    // 변수의 값은 true와 false이지만 실제 값은 1과 0이다.
    return 0;
}