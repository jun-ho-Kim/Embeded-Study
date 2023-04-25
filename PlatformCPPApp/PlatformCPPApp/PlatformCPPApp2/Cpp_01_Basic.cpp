// PlatformCPPApp2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>

int main()
{
    // C와 C++
    // 절차적 프로그래밍 vs 객체지향 프로그래밍

    
    int a = 10; // 정수
    // 자료형 int ... 변수 a  operator = ... value 10;
    // int type ... 4bytes ...  create 
    // nickname ... variables ... allocated
    // a ... = value r-value 10
    std::cout << "a = " << a << std::endl;
    int sizeofA = sizeof(a);
    std::cout << "size of a =" << sizeofA << "bytes" << std::endl;

    unsigned char b = 255;
    std::cout << "b = " << b << std::endl;
    int sizeofB = sizeof(b);
    std::cout << "size of b =" << sizeofB << "bytes" << std::endl;
   
    //char : -128 ~ 127
    //unsigned char: 0 ~ 255

    int k(10);
    std::cout << "k =" << k << std::endl;
    // 변수 값 할당시 operator = 을 생략하고
    // 초기화와 대입이 동시에 이루어진다.
    
    // 변수 ... 변하는 수
    // 상수 ... 항상 같은 수
    // 상수 ... constant
    
    const int c = 10;
    //c = 20; // Error

    // 순수가상함수...virtual function() = 0; // compile error
    // 선언을 해주고 생성을 해주어야 컴파일에러가 발생하지 않는다.

    // 가상함수... virtaul function() ; // compiler ok
    // cpp 표준이 올라갈수록 소프트웨어 품질이 더 까다로워진다.(최신 표준을 쓰는 것이 좋다)

    // 변수가 생성되는 과정을 말하는 것

    // input... function... output
    // 선언 .... 초기화 ...... 대입
    //

    // cast
    // static, dynamic, const, reinterpret 4개의 casting이 존재
    

   

    

   

}