// 대입연산자
// 연산자 overloading
// 연산자 +, -. /, *
// c++에서는 연산자를 함수로 바꿀 수 있는데 이를 연산자 함수라고 한다.
//	연산자의 특성을 함수로 대체시켜 overloading한다.

// 단순대입 연산자 =
// l-value r-value
//	l:Locator(변수)(OverWrite)
//	r-value is 변수, 상수(Read)

// 연산자 함수는 기본형식(int, double등)에서는 재정의할 수 없지만 클래스에서는 재정의 할 수 있다.
// 복사 생성자를 만드는 모든 객체는 대입연산자도 재정의를 해야한다.

// Deep copy 이슈가 있어서 복사 생성자를 정의하는 클래스가 있으면 단순대입연산자도 재정의해야한다.
#include <iostream>

class CTest
{
public:
	CTest() {
		std::cout << "CTest()" << std::endl;
		m_pData = new int(5);
	}
	CTest(const CTest &rhs) { 
		// Pointer에 대해 Shallow copy
		//std::cout << "CTest(const CTest &)" << std::endl; 
		//this->m_nData = rhs.m_nData; // 멤버 값을 단순 대입으로 복사

		// Deep Copy
		this->m_pData = new int(*rhs.m_pData);
	}
	~CTest() {
		std::cout << "~CTest()" << std::endl;
		delete m_pData;
	}

	void SetData(int nParam)
	{
		*m_pData = nParam;
	}

	int GetData()
	{
		return *m_pData;
	}

	CTest& operator =(const CTest& rhs)
	{
		*m_pData = *rhs.m_pData; // Deep
		m_pData = rhs.m_pData;  // Shallow
		return *this;
	}

	int* m_pData = nullptr;
	//int m_nData = 0;
private:
};

int main()
{
	CTest a;
	CTest b;

	a.SetData(5);
	b = a;

	std::cout << a.GetData() << std::endl;
	std::cout << b.GetData() << std::endl;
	// 앝은 복사로 하여 delete를 하는 경우 같은 메모리가 2번 지워져서 프로그램이 에러가 발생하게 된다.
	return 0;
}