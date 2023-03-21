//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <inttypes.h>

int main()
{
    int i; 
    int32_t i32; // 32 bit integer 
    int_least8_t i8; // smallest 8 bit 
    int_fast8_t f8; // fastest minimum; 
    intmax_t imax; // biggest signed integers
    uintmax_t uimax; // biggest unsigned integers

    i32 = 1004;

    printf("me32 = %d\n", i32);
    printf("me32 = %" "d" "\n", i32); // "me32 = %, d \n를 3개로 나누어서 사용 가능"
    printf("me32 = %" PRId32 "\n", i32); // print d type 32bit
    return 0;
}