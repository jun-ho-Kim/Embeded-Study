// TBCPP_Center.sln.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 큰 프로그램을 만들 때 함수를 잘 사용하는 것이 중요하다.
// 함수를 정확하게 이해하기 위해서 매개변수와 인자에 대해 정확하게 짚고 넘어가자.

#include <iostream>
using namespace std;

int foo(int x, int y);

int foo(int x, int y) // x와 y는 foo함수의 파라미터
{
    return x + y;
}
//매개변수는 함수가 어떤 기능을 하는지 조절해준다.
//swap에서 이야기하는 매개변수와 비슷한 의미를 가지고 있다.
// 함수가 끝남과 동시에 OS에 메모리가 반납된다. 지역변수이다.
// 

int main()
{
    int x = 1, y = 2;

    foo(6, 7); // 6, 7 : arguments(actual parameter)
    foo(x, y+1);

    return 0;
}
