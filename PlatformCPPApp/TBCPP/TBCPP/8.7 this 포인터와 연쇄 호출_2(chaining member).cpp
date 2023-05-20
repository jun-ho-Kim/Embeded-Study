#include <iostream>
using namespace std;

// this 포인터를 사용하는 용법들이 여러가지 있는제 chaining member funcfion(연쇄 호출)을 살펴보자.

class Calc
{
private:
	int m_value;
public:
	Calc(int init_value)
		: m_value(init_value)
	{}
	/*
	// 1. 일반 방법
	void add(int value) { m_value += value; }
	void sub(int value) { m_value -= value; }
	void mult(int value) { m_value *= value; }
	*/
	

	void print()
	{
		cout << m_value << endl;
	}

	//2. chaining member funcfion(연쇄 호출)
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

};

int main()
{
	/*
	// 1. 일반 방법
	Calc cal(10);
	cal.add(10);
	cal.sub(1);

	cal.mult(2);

	cal.print(); // 38
	*/

	//2. chaining member funcfion(연쇄 호출)
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print(); // 38



	int z = 3;
}