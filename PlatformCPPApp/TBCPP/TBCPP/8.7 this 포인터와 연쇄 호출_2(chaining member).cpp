#include <iostream>
using namespace std;

// this �����͸� ����ϴ� ������� �������� �ִ��� chaining member funcfion(���� ȣ��)�� ���캸��.

class Calc
{
private:
	int m_value;
public:
	Calc(int init_value)
		: m_value(init_value)
	{}
	/*
	// 1. �Ϲ� ���
	void add(int value) { m_value += value; }
	void sub(int value) { m_value -= value; }
	void mult(int value) { m_value *= value; }
	*/
	

	void print()
	{
		cout << m_value << endl;
	}

	//2. chaining member funcfion(���� ȣ��)
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

};

int main()
{
	/*
	// 1. �Ϲ� ���
	Calc cal(10);
	cal.add(10);
	cal.sub(1);

	cal.mult(2);

	cal.print(); // 38
	*/

	//2. chaining member funcfion(���� ȣ��)
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print(); // 38



	int z = 3;
}