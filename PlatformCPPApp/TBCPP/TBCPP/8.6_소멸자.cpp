#include <iostream>
#include <string>

using namespace std;

// 생성자는 자신이 생성을 하기 보다는 만들어질 때 호출되는 함수를 의미했다.
// 소멸자는 변수가 영역을 벗어나서 사라질 때 호출이 되는 함수이다.

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];
	}
	~IntArray()
	{
		if(m_arr != nullptr) 
			delete[] m_arr;
	}

	int size() { return m_length; }
 };

class Simple
{
private:
	int m_id;
public:
	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}
	// 소멸자는 return 타입이 없다. 
		// ~(tilda)
	~Simple()
	{
		cout << "Destuctor " << m_id << endl;
	}
};

int main()
{
	//Simple s1(0);
	//Simple s2(1);
		// Constructor 0
		// Constructor 1
		// Destuctor 1
		// Destuctor 0

	//Simple* s1 = new Simple(0);
	//Simple s2(1);

	//delete s1;
	//	Constructor 0
	//	Constructor 1
	//	Destuctor 0
	//	Destuctor 1
	// 동적할당을 해제해주지 않는 경우에는 영역에 벗어나면 소멸자가 생성된다.
	// 동적할당으로 클래스가 만들어지면 영역을 벗어나도 메모리가 해제되지 않고 delete를 사용해야 소멸자가 호출된다.
	// ( 소멸자를 프로그래머가 직접 호출하는 것은 권장하지 않는다.)

	// 아래와 같은 로직 시 delete를 사용하지 않으면 memoery leak이 생긴다.
	while (true)
	{
		IntArray my_int_arr(10000);
	
	}
	// 동적할당에서 클래스 사용 시 소멸자 호출 시 동적할당해제 코드를 까먹을까 싶으면 벡터를 사용하자.
	// 벡터는 내부에 소멸자 호출 시 동적할당해제 로직이 들어있다.

	int z = 4;

	return 0;
}