//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592f //전처리기(#define)을 사용하여 기호적 상수 명시
#define AI_NAME "FRIDAY"

//기호적 상수를 사용하면 여러 번 반복되는 변수를 사용할 때 편리하다.
int main()
{
    // const float pi = 3.141592f; //변수 앞에 const를 붙여서 symbolic constant를 만드는 방법
    float pi = 3.141592f;

    float radius, area, circum;

    printf("I`m %s.\n", AI_NAME);
    printf("Please, input raduis\n");

    scanf("%f", &radius);

    area = PI * radius * radius; // area = pi*r*r
    circum = 2.0f * PI * radius; // circum = 2.0*pi*r

    printf("Area is %f\n", area);
    printf("Circumference is %f\n", circum);

    return 0;
}