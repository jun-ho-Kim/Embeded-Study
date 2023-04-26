// CppStudyNullNulldev.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
/*
default 파라미터에 대해 설명(사용 권하지 x)
1. 피호출자 함수 매개변수의 디폴트 값은 반드시 오른쪽 매개변수부터 기술해야한다.
2. 매개변수가 여러 개일 때 왼쪽 첫 번재 매개변수의 디폴트 값을 기술하려면 나머지 오른쪽
'모든' 매개변수에 대한 디폴트 값을 기술해야 한다.
3. 호출자 함수가 피 호출자 함수 매개변수의 살인수를 기술하면
이는 왼쪽부터 짝을 맞추어 적용되며, 짝이 맞지 않는 매개변수는 디폴트 값을 적용한다.
//Google Style Guide에서는 디폴트 파라미터를 사용을 권하지 않는다.
ㄴ 그 이유는 Caller에서 모호성이 발생한다.
(함수의 원형이 짐작이 되지 않는다.)
C++의 모호성은 제거해야한다.
- C++의 큰 특징은 다형성이다.
ㄴ C언어는 함수의 다형성을 지원하지 않는다.
ㄴ 여러 개가 공존X
void TestFunc();
void TestFunc(int);
ㄴ 위와 같이 함수 하나가 여러 형태로 구형되고 존재하는 것이 다형성이 제공된다고 한다.
ㄴ 다형성의 구현형태를 다양하게 가져갈 수 있지만 사용할 때 주의가 필요하다.(다른 함수를 사용했는지)
C에서는 다형성 제공 X

//강의질문
override -> 재정의
overloading -> 다중정의
*/

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
