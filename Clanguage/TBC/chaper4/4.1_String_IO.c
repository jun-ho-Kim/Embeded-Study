//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    /*
    char fruit_name;
    printf("What is your favorite fruit?\n");
    scanf("%c", &fruit_name); // Banana
    printf("You like %c!\n", fruit_name); // You like B
    //c언어 표준에서는 format specifier를 conversion specifiler를 사용하지만
    //검색할 때는 format specifier로 찾을 수 있다.
    //char는 글자 하나 밖에 담을 수 없기 때문에 한 글자만 출력된다.
    */
    //그래서 우리는 배열을 사용해야한다.
    char fruit_name_arr[40]; // char Type 40개의 메모리 공간을 대표하는 메모리 공간 1가지만 알려준다.
    printf("What is your favorite fruit?\n");
    scanf("%s", fruit_name_arr); // Banana
    // format specifier를 %s로 하고, char 출력에 사용되었던 &를 사용하지 않는다.
    // fruit_name_arr 자체가 40개가 나열되어 있는 메모리 공간 주소이기 때문에 &를 사용하지 않아도됨
    printf("You like %s!\n", fruit_name_arr); // You like B

    return 0;
}