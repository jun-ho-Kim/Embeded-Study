//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    // c언어에서는 부동소수점 타입에는 flaot, double, long double이 있다.
    printf("%u\n", sizeof(float)); // 4
    printf("%u\n", sizeof(double)); // 8
    printf("%u\n", sizeof(long double)); //16 // 마이크로소프트에서는 long double을 8byte로 할당, gcc에서는 16byte로 할당한다.

    float f = 123.456f; // float는 숫자 뒤에 f로 명시를 해주어야 한다.
    double d = 123.456; // double은 뒤에 아무것도 안 붙여도 된다. 부동소수점에서는 기본이 double이기 때문에. double에 123.456f를 명시해 주어도 경고가 뜨지 않는다. float의 메모리가 double 보다 작기 때문에

    int i = 3;
    float f2 = 3.f;
    double d2 = 3.;

    float f3 = 1.234e10f; // 1.234*10^10
    
    float f4 = 0x1.1p1; // 0.xb.aP1 (e대신에 p사용 - e는 10의 n 승, p는 2의 n승)
    double d4 = 1.0625e10;

    printf("%f %F %e %E\n", f, f, f, f); // 123.456001 123.456001 1.234560e+02 1.234560E+02
    printf("%f %F %e %E\n", d, d, d, d); // 123.456000 123.456000 1.234560e+02 1.234560E+02
    printf("%a %A\n", f4, f4); // %a는 16진수로 출력 // 0x1.1000000000000p+1 0X1.1000000000000P+1
    printf("%a %A\n", d4, d4); // 0x1.3ca6512000000p+33 0X1.3CA6512000000P+33

    return 0;
}