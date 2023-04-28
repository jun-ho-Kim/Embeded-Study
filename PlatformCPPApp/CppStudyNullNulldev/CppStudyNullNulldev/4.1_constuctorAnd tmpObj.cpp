// int a = 10;
// int a(10);	// 여기서 a는 생성(변수, 인스턴스), 10은 초기값(상수)
// int b(a);	// 여기서 a는 원본, b는 사본

//생성자 함수 - caller -> call // 언어 문법에 의해 호출됨. 즉, 때가 되면 '알아서' '자동'으로 호출
//	생성자는 인스턴스가 선언될 때 생성된다.
//소멸자는 delete나 scope를 벗어나는 경우 호출
//* 생성자 종류
//	1. 기본 생성자
//	2. 다중 정의된 생성자(매개변수)
//		2-1. 변환생성자(매개변수가 1개)
//	3. (이름이 없는 임시 객체)복사 생성자 + r-value 참조를 받는 생성자(C++11부터 지원)
//	4. 이동생성자
// 

// 복사생성자 꼭 필요할까?
// Deep Copy와 shallow Copy에 대해서 알아야 한다.
// 	int nData = 5;
//	int* pA = &nData;
//	int* pB = &nData;
// 대상체(nData) 하나에 접근, 참조자가 2개 이상이 경우 앝은 복사
// 대상체가 여러 개인 경우 깊은 복사
//(차키를 2개를 복사한다고 차가 2개가 되는 것이 아님)

//ex)pointer가 2개 대상체가 1개인 경우 앝은 복사
//		pointer가 2개 그걸 가리키는 대상체가 각각 1개씩 총 2개이면 깉은 복사

// 디폴트 복사 생성자는 기본으로 앝은 복사이다. 깊은 복사를 하기 위해서는 디폴트 복사 생성자를 별도로 정의해야한다.

#include <iostream>

class CTest 
{
public:
	CTest() {
		std::cout << "CTest()" << std::endl; 
		m_pData = new int(5);
	}
	//CTest(const CTest &rhs) { 
	//	std::cout << "CTest(const CTest &)" << std::endl; 
	//	this->m_nData = rhs.m_nData; // 멤버 값을 단순 대입으로 복사
	//}
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

	int *m_pData = nullptr;
	//int m_nData = 0;
private:
};


int main()
{
	/*
	int *pA = new int(5);
	int* pB = NULL;

	pB = pA; //Shallow
	pB = new int(*pA); //Deep

	std::cout << *pA << std::endl;
	*/
	/*
	CTest a;
	a.m_nData = 300;
	CTest b(a); // <-- 복사 생성자

	//a.m_nData = 0;
	//std::cout << a.m_nData << std::endl;
	//std::cout << a.m_nData << std::endl;
	//std::cout << b.m_nData << std::endl;
	*/

	CTest a;
	CTest b(a); // <-- 복사 생성자

	std::cout << a.GetData() << std::endl;
	std::cout << b.GetData() << std::endl;
	// 앝은 복사로 하여 delete를 하는 경우 같은 메모리가 2번 지워져서 프로그램이 에러가 발생하게 된다.
	return 0;
}