//this 는 개념적으로 개별 인스턴스에 각각에 대한 메모리의 주소이다.
// 비유적으로는 휴대폰의 시리얼번호이다.
//

#include <iostream>

class CTest
{
public:
	CTest()
		//: m_nData(0) // C++11 이전 변수 선언 방법//실행 전에 초기하
	{
		std::cout << "CTest()" << std::endl;
		m_nData = 0;// 함수가 call 될 때 실행
	}
	//int m_nData; // C++11 이전 변수 선언 방법

	~CTest()
		//: m_nData(0) // C++11 이전 변수 선언 방법//실행 전에 초기하
	{
		std::cout << "~CTest()" << std::endl;
		m_nData = 0;// 함수가 call 될 때 실행
	}

	void PrintData()
	{
		int local = 5;
		std::cout << this << std::endl;
		std::cout << m_nData << std::endl;
		std::cout << this->m_nData << std::endl;
	}

	int m_nData = 0; //C++ 11 스타일

};

int main()
{
	CTest a;
	std::cout << &a << std::endl; // 00BCFB28
	a.PrintData();
	// 0019FD9C
	// 0019FD9C
	// 0

	CTest b;
	std::cout << &b << std::endl; // 00BCFB1C
	b.PrintData();
	// 같은 CTest 클래스이지만 a와 b의 주소는 다르다.
	// a.printData()는 a.printData(&a)와 같다. 매개변수의 &a는 숨겨져있다.(hidden)

	// this 포인터의 값은 자동으로 결정된다. 
	// this pointer는 r-value이다. 수정할 수 없다.

	// const 함수는 this와 같이 수정할 수 없다.
	// static 정적멤버 -> [전역변수 전역함수] 소속만 class이다.
	//	정적변수를 사용하면 멀티쓰레딩에 문제가 발생할 가능성이 높다.
	//	멀티쓰레딩에 관련하여 동시성이 발생하는가에 문제에 대해서 고민해보아야 한다.
	//	해결방법:	정적 변수를 쓰레드마다 저장되는 stack 메모리(local) (TLS)를 적용시켜서 문제를 해결
	//	하지만 요즘 core의 개수를 늘려 병렬성(동시성)으로 작동시키기 때문에 static은 사용하지 않는 것이 좋다.
}