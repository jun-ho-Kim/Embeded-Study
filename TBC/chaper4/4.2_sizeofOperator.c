//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//구조체
struct MyStruct // int i = 4byte + float f = 4byte => 8byte
{
    int i; 
    float f;
};

int main()
{
    /* 1. sizeof basic types*/
    int a = 0;
    unsigned int int_size1 = sizeof a;
    unsigned int int_size2 = sizeof(int);
    unsigned int int_size3 = sizeof(a);

    size_t int_size4 = sizeof(a);
    size_t float_size = sizeof(float);
    //size_t는 window 32bit에서는 4byte, 64bit에서는 8byte를 사용. 이식성을 높이기 위해서 사용
    //최근에 size_t사용이 많아지고 있다.
    printf("Size of int type is %u byte.\n", int_size1); 
    printf("Size of int type is %zu byte.\n", int_size4);
    printf("Size of float type is %zu byte.\n", float_size);
    // %zu: size_t의 type specifer

    /* 2. sizeof arrays*/
    int int_arr[30]; //120byte(4byte * 30)
    int* int_ptr = NULL;
    //주소를 적을 수 있는 종이를 들고 있다.
    int_ptr = (int*)malloc(sizeof(int) * 30);
    //메모리의 공간 중 하나를 받아서 종이에 적는다.
    //120byte 공간을 할당하고 int_ptr에 대표되는 공간의 사이즈가 나온다.

    printf("Size of array = %zu bytes\n", sizeof(int_arr)); // 120byte
    //int_arr는 30개의 저장공간 중 대표되는 하나의 공간을 나타낸다.
    printf("Size of pointer = %zu bytes\n", sizeof(int_ptr)); // 4byte
    //int_arr이는 사용할 때만 대표주소만 바뀐다. 프로그래밍할 때는 주소로 이해하는 것이 좋다. 메모리는 120byte가 할당됨
    //compile할 때 메모리 크기가 결정됨
    // int_ptr는 선언을 하고 runtime일 때 결정됨(동적할당의 개념) 그래서  sizeof(int_ptr)의 메모리크기는 정확히 알 수 없다.

    /* 3. sizeof character array */
    char c = 'a';
    char string[10];
    //c언어에서는 문자열을 저장할 때 마지막에 null character를 저장한다.
    //maximally 9 character + '/0' (null character) // 실제로 9글자 밖에 저장이 안됨

    size_t char_size = sizeof(char);
    size_t str_size = sizeof(string);

    printf("Size of char type is %zu bytes.\n", char_size);
    printf("Size of string type is %zu bytes.\n", str_size);

    /* 4. sizeof structure */ 
    printf("%zu\n", sizeof(struct MyStruct)); // 8byte

    return 0;
}