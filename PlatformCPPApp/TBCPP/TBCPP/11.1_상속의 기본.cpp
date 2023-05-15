#include <iostream>

using namespace std;

class Mother
{
private:
	int m_i;

public:
	//Mother(const int& i_in)
	//	:m_i(i_in)
	//{
	//	std::cout << "Mother constructor" << std::endl;
	//} // Error
	// Child Ŭ������ ������ �� �⺻������ Mother class�� ���� �����ȴ�.
	
	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}
};

// Child Ŭ������ Mother Ŭ�������� ���� ���� �� ����� �� �ִ�.
// Mother Ŭ������ ���� ���� Ŭ������ �����ؼ� ���� �� �ִ�.
class Child : public Mother // dervied class(��� ���� Ŭ����)
{
private:
	double m_d;
public:
	// constuctor�� �����ϴ� ������ �޸𸮰� �Ҵ� �� �� initailize�� �ش޶�� �ϴ� ���� �޸𸮰� ���� �Ҵ�ǰ� �ʱ�ȭ�� �ϴ� ���� �ƴϴ�.

	Child(const int& i_in, const double& d_in)
		// : m_i(i_in), m_d(i_in) // Error
		// : Mother(i_in), m_d (d_in) // O
	{
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const int& i_in, const double& d_in)
	{
		// m_i = d_in; // Error(Mother.m_in�� private�� ���) 
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};

class Daughter : public Mother {};

class Son : public Mother {};


int main()
{
	Mother mother;
	mother.setValue(1024);
	cout << mother.getValue() << endl;

	//Child child;
	Child child(1024, 128);
	child.Mother::setValue(1024);
	child.setValue(128);
	cout << child.getValue() << endl;

	int y = 4;

	return 0;
}