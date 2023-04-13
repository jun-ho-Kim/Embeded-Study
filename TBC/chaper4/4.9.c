//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    float n1 = 3.14; // 4byte
    double n2 = 1.234; // 8byte
    int n3 = 1024; //4byte

    printf("%f %f %d\n\n", n1, n2, n3); // 3.140000 1.234000 1024

    //Note the warning in output window
    printf("%d %d %d\n\n", n1, n2, n3); // 4 4 4 // 1610612736 -927712936 1024
    printf("%lld %lld %d\n\n", n1, n2, n3); // 8 8 4 // 부동소수점의 수를 강제로 integer로 변환해서 출력하려고 해서 값이 이상하게 나옴
    // 4614253070451212288 4608236261112822104 1024
    printf("%f %d %d\n\n", n1, n2, n3); // 8 4 4 // 3.140000 -927712936 1024
    printf("%f %lld %d\n\n", n1, n2, n3); // 8 16 4 // 3.140000 4608236261112822104 1024

    return 0;
}