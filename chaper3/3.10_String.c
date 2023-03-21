//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <inttypes.h>

int main()
{
    char c = 'A';
    char d = '*'; // d = 'A'

    printf("%c %hhd\n", c, c);
    printf("%c %hhd\n", d, d);

    char a = '\a'; // 실행 시 소리 남, 아스키코드 7번
    //printf("%c", a);
    //printf("\07");
    printf("\x7");

    float salary;
    printf("$__\b\b\b\b");
    scanf("%f", &salary);

    printf("AB\tCDEF\n");
    printf("ABC\tDEF\n"); // \t는 탭 맞춤

    printf("\\ \'HA+\' \"Hello\" \?\n"); // 특수문자를 사용할 때 앞에 백슬래쉬(\) 사용

    return 0;
}