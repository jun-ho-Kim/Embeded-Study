//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    /*
    int hour, minutes, seconds = 0;

    while (seconds >= 0) 
    {
        printf("Input second : ");
        scanf("%d", &seconds);
        
        if (seconds >= 0) {
        minutes = seconds / 60;
        seconds %= 60;

        hour = minutes / 60;
        minutes %= 60;

        //hour = second / (60 * 60);
        //minutes = second / (60) % 60;
        //second = second % 60;

        printf("hour: %d, minutes: %d, seconds: %d\n", hour, minutes, seconds);
        }
    }
    */
    int div, mod;
    //나머지 연산자는 앞에 숫자가 양수이면 나머지도 양수, 음수이면 나머지도 음수로 나온다.
    div = 11 / 5;
    mod = 11 % 5;
    printf("div = %d, mod = %d\n", div, mod); // div = 2, mod = 1

    div = 11 / -5;
    mod = 11 % -5;
    printf("div = %d, mod = %d\n", div, mod); // div = -2, mod = 1

    div = -11 / -5;
    mod = -11 % -5;
    printf("div = %d, mod = %d\n", div, mod); // div = 2, mod = -1

    div = -11 / 5;
    mod = -11 % 5;
    printf("div = %d, mod = %d\n", div, mod); // div = -2, mod = -1

    return 0;
}