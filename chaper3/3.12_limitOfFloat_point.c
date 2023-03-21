//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
    // round-off errors(ex1)
    float a, b;
    a = 1.0E20f + 1.0f;
    b = a - 1.0E20f;
    printf("%f\n", b); // 0.000000
    // 1.0E20 값과 1.0f의 범위가 너무 차이가 크기 때문에 1.0f 사라져 버린다.

    // round off error(ex2)
    float c = 0.0f;
    for (int i = 0; i < 100; i++) {
        c = c + 0.01f;
    };
    printf("%f\n", c); // 0.999999
    // 부동소수점 표현법에서는 0.01을 정확히 표현할 수 없다. 왜냐하면 1/2의 n승으로 소수점을 계산하기 때문에 그 수가 누적되어진다.

    //overflow
    float max = 3.402823466e+38F;
    max = max * 100.0f;
    printf("%f\n", max); // inf
    // 변수가 담을 수 있는 값보다 크기 때문에 inf(infinit) 발생

    // underflow
    float min = 1.401298464e-45F;
    printf("%e\n", min); //1.401298e-45
    min = min / 100.f; // subnormal;
    printf("%e\n", min); //0.000000e+00

    float f = 104.0f;
    printf("%f\n", f); // 104.000000
    f = f / 0.0f;
    printf("%f\n", f); // inf

    float asinfVal = asinf(1.0f);
    printf("%f\n", asinfVal); // 1.570796
    asinfVal = asinf(2.0f);
    printf("%f\n", asinfVal); // -nan(ind)

    return 0;
}