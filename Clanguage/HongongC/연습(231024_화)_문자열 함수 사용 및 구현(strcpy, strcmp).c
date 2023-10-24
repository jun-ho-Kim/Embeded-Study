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
    //strcpy 함수를 사용한 문자열 복사
    printf("Hello World");

    char str1[80] = "strawberry";
    char str2[80] = "apple";
    char *ps1 = "banana";
    char *ps2 = str2;

    printf("최초 문자열 : %s\n", str1); //stawberry
    strcpy(str1, str2);
    printf("바뀐 문자열 : %s\n", str1);  // apple

    strcpy(str1, ps1);
    printf("바뀐 문자열 : %s\n", str1); // banana

    strcpy(str1, ps2);
    printf("바뀐 문자열 : %s\n", str1); // apple
    */

    /*
    //strcmp 함수를 사용한 문자열 비교
    char str1[80] = "peer";
    char str2[80] = "peach";

    printf("사전에 나중에 나오는 과일 이름: "); // peer
    if(strcmp(str1, str2) > 0)
        printf("%s\n", str1);
    else
        printf("%s\n", str2);
    */


    char str[80] = "strawberry";
    printf("바꾸기 전 문자열: %s\n", str);

    my_strcpy(str, "apple");

    printf("바꾼 후 문자열: %s\n", str);

    return 0;
}

//strcpy와 기능이 같은 함수의 구현
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
