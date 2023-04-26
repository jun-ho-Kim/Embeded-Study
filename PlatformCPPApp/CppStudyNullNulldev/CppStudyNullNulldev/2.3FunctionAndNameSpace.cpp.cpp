// CppStudyNullNulldev.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 다형성과 모호성
#include <iostream>

// 인라인 함수 - C 15장, 16장
// release 모드일 때 더하기하는 경우 push를 함

// C언어: [변수이름, 함수이름] 중복이 안됨
// 여러사람이 코드를 짜면 중복될 가능성이 높아진다.
// 이걸 해결하기 위해 등장한 것이 namespace이다. 이걸 소속으로 생각하면 된다.
// 전역변수 개념일 때 소속이 중요해진다.
// useage: namespace
// namespaece: test
// test::a // test는 범위, 소속이다. 

//using을 사용하여 std를 작성을 안해주어도 되지만 나중에 식별자 검색에서 문제가 될 수 있다.


// 식별자 검색순서
// 블록범위, 전역변수

int Add(int a, int b)
{
    return a + b;
}

namespace TEST
{
    void TestFunc(void)
    {
        Add(3, 4);
    }

    int Add(int a, int b)
    {
        return a + b;
    }
}

int main()
{
    int nResult = ::Add(3, 4);
    printf("%d\n", nResult);

    return 0;
}