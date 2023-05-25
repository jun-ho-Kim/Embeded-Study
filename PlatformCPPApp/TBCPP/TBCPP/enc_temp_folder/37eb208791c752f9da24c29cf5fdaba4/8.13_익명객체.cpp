#include <iostream>
#include <string>

using namespace std;

// 목차
// 익명구조체


// 객체를 사용할 때 이름이 붙은 변수를 사용하지 않고 바로 사용하는 익명 객체에 대해 살펴보자.

class A
{
public:
	int m_value;
	/*
	//case 1
	A()
	{
		cout << "Constructor" << endl;
	}

	~A()
	{
		cout << "Descturctor" << endl;
	}

	void print()
	{
		cout << "Hello" << endl;
	}
	*/

	//case 2
	A(const int& input)
		:m_value(input)
	{
		cout << "Constructor" << endl;
	}
	void print()
	{
		cout << m_value << endl;
	}

	~A()
	{
		cout << "Descturctor" << endl;
	}
};

class Cents
{
private:
	int m_cents;
public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	/*
	//case 1
	//A a;
	//a.print();

	
	A().print(); // R-value처럼 작동한다.
	// 이렇게 하면 재사용을 할 수 없다.

	A().print(); // 이렇게 생성된 객체들은 각각 다르다

	*/
	/*
	Constructor
	Hello
	Descturctor
	Constructor
	Hello
	Descturctor
	*/

	A a(1);
	a.print();
	A(1).print(); // 생기자 마자 소멸자가 생성되어 사라진다.
	/*
	Constructor
	1
	Constructor
	1
	Descturctor
	Descturctor
	*/

	// 아래 두개의 유사성을 비교해보자.
	cout << add(Cents(6), Cents(8)).getCents() << endl;
	cout << int(6) + int(8) << endl; 

	return 0;
}