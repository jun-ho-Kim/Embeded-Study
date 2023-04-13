//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[100] = "Hello";
    char str2[] = "Hello"; // 컴파일러에게 자동으로 메모리 공간을 할당
    char str3[100] = "\0";
    char str4[100] = "\n";

    printf("%zu %zu\n", sizeof(str1), strlen(str1)); // 100 5
    printf("%zu %zu\n", sizeof(str2), strlen(str2)); // 6 5
    //strlen() 함수는 null character를 제외하고 길이를 잰다.
    printf("%zu %zu\n", sizeof(str3), strlen(str3)); // 100 0
    printf("%zu %zu\n", sizeof(str4), strlen(str4)); // 100 1
    //빈칸과 null character는 다르다(ASCII CODE가 다르다.)

    /* Extra */ //나중에 pointer 할 때 자세히 살펴볼 것
    char *str5 = (char*)malloc(sizeof(char) * 100);
    str5[0] = 'H'; 
    str5[1] = 'e'; 
    str5[2] = 'l'; 
    str5[3] = 'l'; 
    str5[4] = 'o';
    str5[5] = '\0';
    printf("%zu %zu\n", sizeof(str5), strlen(str5));
    printf("%s\n", str5);
    return 0;
}