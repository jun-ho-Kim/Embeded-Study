// CppStudyNullNulldev.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.

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
