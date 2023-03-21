//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a = 1;
    int int_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]); // 0 1 9
    printf("%i\n", int_arr[12]);

    char c = 'a';
    char str1[10] = "Hello"; //null character
    char str2[10] = { 'H', '\0', 'i' };

    printf("%c\n", c); // a
    printf("%s\n", str1); // Hello
    printf("%s\n", str2); // H
    //printf가 글자를 하나씩 출력하다가 \0(백슬래쉬 + 0)을 만나면 더 이상 출력을 하지 않는다.
    
    printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]); //72 0 105 0 0
    //문자열의 빈 공간을 출력하면 0으로 출력

    //char str3[10] = "Hello, \0World"; // Error:4.3.c:25:22: warning: initializer-string for array of 'char' is too long
    char str3[20] = "Hello, \0World";
    printf("%s\n", str3); //Hello,
    printf("%c\n", str3[10]); // r
    printf("%c\n", str3[11]); // l
    //\0(null charcter)이 있어도 그 뒤에 문자열은 저장이 되고 출력 시에만 null character 앞 부분만 출력

    return 0;
}