#include <iostream>
//제03장 클래스 - 첫 번째
//- C 언어 : 절차지향언어->C++ : 객체지향언어
//ㄴ Class = 구조체 + 함수와 비슷


//////////////////////////////////////
//제작자 코드
class USERDATA // typedef struct USERDATA
{
public:
    int nAge;
    char szName[32];
    //void(*Print) (struct USERDATA*);
    void Print(USERDATA* pUser)
    {
        //printf("%d, %s\n", pUser->nAge, pUser->szName); // C-Style
        printf("%d, %s\n", nAge, szName); //C++-Style
    }

    void Print2()
    {
        //printf("%d, %s\n", pUser->nAge, pUser->szName); // C-Style
        printf("%d, %s\n", nAge, szName); //C++-Style
    }

};




//////////////////////////////////////
//사용자 코드
int main()
{
    USERDATA a = { 20, "HONG" };
    //1
    //printf("%d %s\n", a.nAge, a.szName);
    //2
    //PrintUserData(&a);
    //3
    a.Print(&a);
    //4
    //a.Print();
    //a.Print2();
    return 0;
}

// 의존성-관계
// 자료구조 <- 사용코드(함수) // 자료구조가 변경되면 코드도 변경되는 관계를 의존성, 의존관계라고 한다.
// C에서는 자료구조와 사용코드의 의존성이 없다.

// C++에서는 구조체가 없다.


// 식별자 검색순서

// 구조체 -> 클래스 넘어가는 강의 부분 다시 보고 실습해보기