//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    float won = 0.0f;
    float dollor = 0.0f;

    printf("Input Won\n");
    scanf("%f", &won);

    dollor = won * 0.00089f;

    printf("Dollor = %f\n", dollor);

    return 0;
}
