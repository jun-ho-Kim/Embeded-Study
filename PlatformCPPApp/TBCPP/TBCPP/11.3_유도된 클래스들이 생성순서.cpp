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
// Child�� Mother�� �ִ� ���� �� ����� �� �ֱ� ������ Mother�� ���� �ʱ�ȭ �� ������ Child�� �ʱ�ȭ�Ѵ�.
// �׷��� child���� m_i�� �ʱ�ȭ �� ���� �� ����.
class Child : public Mother
{
public:
	double m_d;


	Child()
		: m_d(1.0), Mother(1024) // �ڽ��� �θ��� ��� ������ �ʱ�ȭ�ϴ� ��(�θ��� ������ ���)
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

	// ����� 3�ܰ迡 ���� �Ͼ�� ���
	C c;
	// A contructor
	// B contructor
	// C contructor

	int y = 3;

	return 0;
}