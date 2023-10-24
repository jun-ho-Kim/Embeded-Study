/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

char* my_strcpy(char* pd, char* ps);

int main()
{
    /*
    //strcpy �Լ��� ����� ���ڿ� ����
    printf("Hello World");

    char str1[80] = "strawberry";
    char str2[80] = "apple";
    char *ps1 = "banana";
    char *ps2 = str2;

    printf("���� ���ڿ� : %s\n", str1); //stawberry
    strcpy(str1, str2);
    printf("�ٲ� ���ڿ� : %s\n", str1);  // apple

    strcpy(str1, ps1);
    printf("�ٲ� ���ڿ� : %s\n", str1); // banana

    strcpy(str1, ps2);
    printf("�ٲ� ���ڿ� : %s\n", str1); // apple
    */

    /*
    //strcmp �Լ��� ����� ���ڿ� ��
    char str1[80] = "peer";
    char str2[80] = "peach";

    printf("������ ���߿� ������ ���� �̸�: "); // peer
    if(strcmp(str1, str2) > 0)
        printf("%s\n", str1);
    else
        printf("%s\n", str2);
    */


    char str[80] = "strawberry";
    printf("�ٲٱ� �� ���ڿ�: %s\n", str);

    my_strcpy(str, "apple");

    printf("�ٲ� �� ���ڿ�: %s\n", str);

    return 0;
}

//strcpy�� ����� ���� �Լ��� ����
char* my_strcpy(char* pd, char* ps)
{
    char* po = pd;

    while (*ps != '\0')
    {
        *pd = *ps;
        pd++;
        ps++;
    }

    *pd = '\0';

    return po;
}
