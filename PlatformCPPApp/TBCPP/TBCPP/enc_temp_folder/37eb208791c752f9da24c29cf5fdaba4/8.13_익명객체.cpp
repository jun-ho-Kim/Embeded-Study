#include <iostream>
#include <string>

using namespace std;

// ����
// �͸���ü


// ��ü�� ����� �� �̸��� ���� ������ ������� �ʰ� �ٷ� ����ϴ� �͸� ��ü�� ���� ���캸��.

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

	
	A().print(); // R-valueó�� �۵��Ѵ�.
	// �̷��� �ϸ� ������ �� �� ����.

	A().print(); // �̷��� ������ ��ü���� ���� �ٸ���

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
	A(1).print(); // ������ ���� �Ҹ��ڰ� �����Ǿ� �������.
	/*
	Constructor
	1
	Constructor
	1
	Descturctor
	Descturctor
	*/

	// �Ʒ� �ΰ��� ���缺�� ���غ���.
	cout << add(Cents(6), Cents(8)).getCents() << endl;
	cout << int(6) + int(8) << endl; 

	return 0;
}