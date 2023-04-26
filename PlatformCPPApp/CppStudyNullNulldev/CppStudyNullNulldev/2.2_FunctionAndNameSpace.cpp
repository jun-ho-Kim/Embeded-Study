// CppStudyNullNulldev.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 다형성과 모호성
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
    //Add라는 함수만 보았을 때 매개변수가 무엇인지 알 수 없다.(모호성)
    //함수가 여러개 있으면 어떤 함수를 사용할지 호출자가 결정한다.



    //함수 템플릿
    //  함수 다중정의 대신에 함수 템플릿을 사용한다.
    //  C++에서 템플릿이 두 개가 나오는데 함수와 클래스에서 사용된다.
    // 템플릿은 함수와 클래스를 찍어낸다.
    //  템플릿을 많이 쓰는 것이 유리하다.

    //TestFunc(3); // Error: 'TestFunc': 오버로드된 함수에 대한 호출이 모호합니다.

    // 모호성은 결국 힘겨운 유지보수 환경을 만들게 된다.
    // 다중정의, 재정의 + 디폴트 파라미터를 사용하면 문제가 생길 수 있다.

    // "int __cdecl Add(int,int)" (? Add@@YAHHH@Z)_main 함수에서 참조되는 확인할 수 없는 외부 기호	CppStudyNullNulldev	D : \PlatformCpp\PlatformCPPApp\CppStudyNullNulldev\CppStudyNullNulldev\2.2_FunctionAndNameSpace.obj	1
    // 오류	LNK2019	"double __cdecl Add(double,double)" (? Add@@YANNN@Z)_main 함수에서 참조되는 확인할 수 없는 외부 기호	CppStudyNullNulldev	D : \PlatformCpp\PlatformCPPApp\CppStudyNullNulldev\CppStudyNullNulldev\2.2_FunctionAndNameSpace.obj	1

    // C++에서는 컴파일 할 때 함수명을 ? Add@@YAHHH@Z이나 ? Add@@YANNN@Z로 바꾼다.  이 이름은 C언어에서와 같이 중복이 안된다.
    // 이것을 name mangling



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