//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("%10i\n", 1234567); //    1234567
    printf("%-10i\n", 1234567); // 1234567
    printf("%+i %+i\n", 123, -123); // +123 -123 //양수이든 음수이든 숫자 앞에 부호를 붙여준다.
    printf("% i \n% i\n", 123, -123); //  123 \n -123
    printf("%X\n", 17); // 11 // 16진수로 표현
    printf("%#X\n", 17); // OX11 // 16진수 앞에 0x 추가
    printf("%05i\n", 123); // 00123
    printf("%*i\n", 7, 456); //     456 
    //flags에 *가 붙으면 items 자리에 하나를 더 입력할 수 있다. * 자리에 입력된 숫자만큼 출력한다.

    printf("\nPrecision\n");
    printf("%.3d\n", 1024); // 1024 // 최소숫자 3자리
    printf("%.5d\n", 1024); // 01024 // 최소숫자 5자리인데 4자리에 앞에 0이 채워짐
    printf("%.3f\n", 123456.1234567); // 123456.123 // float인 경우 소수점 3자리까지 출력(반올림하여)
    printf("%.3f\n", 123456.1235); // 123456.124
    printf("%10.3f\n", 123.45678); //    123.457 // 10은 전체 자리수, 3은 소수점 자리, 남은 자리에 앞에 빈칸으로 출력
    printf("%010.3f\n", 123.45678); // 000123.457
    printf("%.5s\n", "ABCDEFGHIJKLMN"); // ABCDE // string에 precision을 사용할 경우 글자수를 제한(5자리만 출력)
    printf("%.s\n", "ABCDEFGHIJKLMN"); // 숫자를 넣어주지 않으면 아무 글자도 나오지 않는다.(0으로 인식)

    printf("\nLength\n");
    printf("%hhd %hd %d\n", 257, 257, 257); // 1 257 257
    printf("%d %lld %lld\n", INT_MAX + 1, INT_MAX + 1, 2147483648LL);

    return 0;
}