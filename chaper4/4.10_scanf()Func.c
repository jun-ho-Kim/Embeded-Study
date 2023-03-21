//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    /* multiple inputs with blank seperators */
    //int i;
    //float f;
    //char str[30];
    //scanf("%d %f %s", &i, &f, str);
    //printf("%d %f %s\n", i, f, str);

    ///* character */
    //char c;
    //scanf("%c", &c);
    //printf("%\n", c);

    /* Unsigned as signed */
    //unsigned i;
    //scanf("%i", &i);
    //printf("%i\n", i);
    // -123 음수를 입력하는 경우 scanf에서 signed로 입력을 받고 출력에도 sign로 출력한다.
    // 헷갈리게 코딩을 하는 것은 좋지 않다.

    /* Unsigend as unsigned */
    //unsigned i2;
    //scanf("%u", &i2);
    //printf("%u\n", i2);
    // -1024 발생 시 overflow가 발생

    /* floating point numbers */
    //double d = 0.0;
    //scanf("%lf", &d);
    //printf("%f\n", d);
    //scanf()일 때 d는 %lf 사용. printf()는 double, float 둘 다 %f 사용

    /* Width */
    //char str[30];
    //scanf("%5s", str);
    //printf("%s\n", str);

    /* h modifier */
    //char i;
    //scanf("%hhd", &i); // try large numbers
    //printf("%i\n", i);

    /* integer with charater */
    //int i;
    //scanf("%i", &i); // try '123ab', '123a456'
    //printf("%i\n", i); // 123, 123

    /* j modifier */
    intmax_t i;
    scanf("%ji", &i);
    printf("%ji", i);
    

    return 0;
}