#include <iostream>
#include <string>

using namespace std;

class Mother
{
public:
	int m_i;

	//Mother()
	//	: m_i(1)
	//{
	//	cout << "Mother construction " << endl;
	//}

	Mother(const int & i_in = 0)
		: m_i(1)
	{
		cout << "Mother construction " << endl;
	}
};
// Child는 Mother에 있는 것을 다 사용할 수 있기 때문에 Mother을 먼저 초기화 한 다음에 Child를 초기화한다.
// 그래서 child에서 m_i를 초기화 를 해줄 수 없다.
class Child : public Mother
{
public:
	double m_d;


	Child()
		: m_d(1.0), Mother(1024) // 자식이 부모의 멤버 변수를 초기화하는 법(부모의 생성자 사용)
		//:m_i(1024) // Error
	{
		cout << "Child construction " << endl;
		//m_i = 10;
		//this->m_i = 10;
		//this->Mother::m_i = 1024;
	}
};


class A
{
public:
	A()
	{
		cout << "A contructor " << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B contructor " << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "C contructor " << endl;
	}
};

int main()
{

	// C contructor 
	//Child c1;
	//Mother construction
	//Child construction

	// 상속이 3단계에 걸쳐 일어나는 경우
	C c;
	// A contructor
	// B contructor
	// C contructor

	int y = 3;

	return 0;
}