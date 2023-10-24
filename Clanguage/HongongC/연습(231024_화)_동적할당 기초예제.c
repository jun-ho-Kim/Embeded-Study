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
    // ���� �Ҵ��� ���� ������ ����ϴ� ���α׷�
    int *pi;
    double *pd;

    pi = (int *)malloc(sizeof(int));
    if(pi==NULL)
    {
        printf("# �޸𸮰� �����մϴ�.\n");
        exit(1);
    }
    pd = (double *) malloc(sizeof(double));

    *pi = 10;
    *pd = 3.4;

    printf("���������� ��� : %d\n", *pi);
    printf("�Ǽ������� ��� : %.1lf\n", *pd);

    free(pi);
    free(pd);
    */

    // ���� �Ҵ� ������ �迭ó�� ���
    int* pi;
    int i, sum = 0;

    pi = (int*)malloc(5 * sizeof(int));
    if (pi == NULL)
    {
        printf("�޸𸮰� �����մϴ�!\n");
        exit(1);
    }

    printf("�ټ� ���� ���̸� �Է��ϼ��� : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &pi[i]);
        sum += pi[i];
    }

    printf("�ټ� ���� ��� ���� : %1lf\n", (sum / 5.0));
    free(pi);

    return 0;
}
