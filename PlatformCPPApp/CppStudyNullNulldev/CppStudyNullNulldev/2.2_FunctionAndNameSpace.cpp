// CppStudyNullNulldev.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
// �������� ��ȣ��
#include <iostream>

int Add(int a, int b);
double Add(double a, double b);

//template <typename T>
//T Add(T a, T b)
//{
//    return a + b;
//}

void TestFunc(int a, int b = 4) 
{

}

void TestFunc(int nParam)
{

}

int main()
{
    std::cout << Add(3, 4) << std::endl;
    std::cout << Add(3.3, 4.4) << std::endl;
    //Add��� �Լ��� ������ �� �Ű������� �������� �� �� ����.(��ȣ��)
    //�Լ��� ������ ������ � �Լ��� ������� ȣ���ڰ� �����Ѵ�.



    //�Լ� ���ø�
    //  �Լ� �������� ��ſ� �Լ� ���ø��� ����Ѵ�.
    //  C++���� ���ø��� �� ���� �����µ� �Լ��� Ŭ�������� ���ȴ�.
    // ���ø��� �Լ��� Ŭ������ ����.
    //  ���ø��� ���� ���� ���� �����ϴ�.

    //TestFunc(3); // Error: 'TestFunc': �����ε�� �Լ��� ���� ȣ���� ��ȣ�մϴ�.

    // ��ȣ���� �ᱹ ���ܿ� �������� ȯ���� ����� �ȴ�.
    // ��������, ������ + ����Ʈ �Ķ���͸� ����ϸ� ������ ���� �� �ִ�.

    // "int __cdecl Add(int,int)" (? Add@@YAHHH@Z)_main �Լ����� �����Ǵ� Ȯ���� �� ���� �ܺ� ��ȣ	CppStudyNullNulldev	D : \PlatformCpp\PlatformCPPApp\CppStudyNullNulldev\CppStudyNullNulldev\2.2_FunctionAndNameSpace.obj	1
    // ����	LNK2019	"double __cdecl Add(double,double)" (? Add@@YANNN@Z)_main �Լ����� �����Ǵ� Ȯ���� �� ���� �ܺ� ��ȣ	CppStudyNullNulldev	D : \PlatformCpp\PlatformCPPApp\CppStudyNullNulldev\CppStudyNullNulldev\2.2_FunctionAndNameSpace.obj	1

    // C++������ ������ �� �� �Լ����� ? Add@@YAHHH@Z�̳� ? Add@@YANNN@Z�� �ٲ۴�.  �� �̸��� C������ ���� �ߺ��� �ȵȴ�.
    // �̰��� name mangling



    return 0;
}

//int Add(int a, int b)
//{
//    return a + b;
//}
//
//double Add(double a, double b)
//{
//    return a + b;
//}