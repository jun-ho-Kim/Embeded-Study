/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

char* my_strcpy(char* pd, char* ps);

int main(void)
{
    /*
    // 동적 할당한 저장 공간을 사용하는 프로그램
    int *pi;
    double *pd;

    pi = (int *)malloc(sizeof(int));
    if(pi==NULL)
    {
        printf("# 메모리가 부족합니다.\n");
        exit(1);
    }
    pd = (double *) malloc(sizeof(double));

    *pi = 10;
    *pd = 3.4;

    printf("정수형으로 사용 : %d\n", *pi);
    printf("실수형으로 사용 : %.1lf\n", *pd);

    free(pi);
    free(pd);
    */

    // 동적 할당 영역을 배열처럼 사용
    int* pi;
    int i, sum = 0;

    pi = (int*)malloc(5 * sizeof(int));
    if (pi == NULL)
    {
        printf("메모리가 부족합니다!\n");
        exit(1);
    }

    printf("다섯 명의 나이를 입력하세요 : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &pi[i]);
        sum += pi[i];
    }

    printf("다섯 명의 평균 나이 : %1lf\n", (sum / 5.0));
    free(pi);

    return 0;
}
