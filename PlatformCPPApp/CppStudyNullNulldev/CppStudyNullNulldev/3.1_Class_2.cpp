// Class = 구조체 + 함수 + (접근제어 + 상속)
//			(멤버 - data, function)

//객체의 외부에서 내부로 들어가려고 하는 것을 접근이라고 한다.
//접근을 왜 통제해야할까?
//아이폰의 CPU나 RAM에 접근할 수 있으면 자주 고장이 날 것이다.
//C의 구조체는 접근통제가 X // 자료로 임의로 접근 // 자유도가 높다.


// C++의 객체지향은 Class의 생성자아 소멸자를 지원한다.
//	특수: 1. 호출 시점이 특이. 2. 반환 형식 X
//	[int Test(char *)] -> Callee라고 한다.

// 자동으로 호출됨 -> 문법에 따라.

#include <iostream>
using namespace std;

class CTest
{
public:
	CTest()
		//: m_nData(0) // C++11 이전 변수 선언 방법//실행 전에 초기하
	{
		std::cout << "CTest()" << endl;
		m_nData = 0;// 함수가 call 될 때 실행
	}
	//int m_nData; // C++11 이전 변수 선언 방법

	~CTest()
		//: m_nData(0) // C++11 이전 변수 선언 방법//실행 전에 초기하
	{
		std::cout << "~CTest()" << endl;
		m_nData = 0;// 함수가 call 될 때 실행
	}

	int m_nData = 0; //C++ 11 스타일

};
int main()
{
	CTest* pTest = (CTest*)malloc(sizeof(CTest));
	free(pTest);
	// 동적할당을 사용하면 생성자와 소멸자가 호출되지 않는다.
	// pTest가 가리키는 것은 CTest가 들어갈 수 있는 메모리이며 CTest는 아니다.

	CTest* pNewTest = new CTest;
	delete pNewTest;
	// 클래스를 선언하므로 인스턴스를 호출하기 때문에 생성자와 소멸자를 호출한다.

	/*
	std::cout << "Begin of main()" << endl;
	CTest a; // CTest를 전역변수에 실행하면 main()보다 CTest가 먼저 실행된다.
	std::cout << "End of main()" << endl;
	*/
} // 지역변수의 소멸시점

// C언어에서 main() 함수가 시작점이다.
// C++에서는 main() 보다는 특정 class의 생성자가 먼저 호출이 될 수 있다.


//변한생성자 - 나중에 살펴볼 것. 중요
//명시적 디폴트 생성자 C++ // 문법적을 편리함
//	

// 