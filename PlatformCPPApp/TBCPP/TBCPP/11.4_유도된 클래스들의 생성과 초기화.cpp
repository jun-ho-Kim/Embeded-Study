#include <iostream>
#include <string>

using namespace std;

class Mother
{
public:
	int m_i;
	
	Mother(const int& i_in = 0)
		:m_i(i_in)
	{
		cout << "Mother construction " << endl;
	}
};

class A
{
public:
	A(int a)
	{
		cout << "A: " << a << endl;
	}
	~A()
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		:A(a)
	{
		cout << "B: " << b << endl;
	}
	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C : public B
{
public:
	C(int a, double b, char c)
		:B(a, b)
	{
		cout << "C: " << b << endl;
	}
	~C()
	{
		cout << "Destructor C" << endl;
	}
};

class Child : public Mother
{
public:
	float m_d;

	Child()
		:m_d(1.0f), Mother(1024)
	{
		cout << "Child construction " << endl;
	}
};

int main()
{
	C c(1024, 3.14, 'a');
	// Destructor C
	// Destructor B
	// Destructor A

	// Child는 child 멤버 변수+ mother 멤버변수의 크기
	cout << sizeof(Mother) << endl; // 4
	cout << sizeof(Child) << endl; // 8

	int z = 4;
}