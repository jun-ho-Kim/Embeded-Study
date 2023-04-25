// CppStudyNullNulldev.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>

//void TestFunc(int = 10, int); // Error
void TestFunc(int, int = 10);

//Caller
int main()
{

    TestFunc(3);

    //

    return 0;

}

//Callee
void TestFunc(int a, int b)
{
    printf("a: %d, b: %d\n", a, b);
}
