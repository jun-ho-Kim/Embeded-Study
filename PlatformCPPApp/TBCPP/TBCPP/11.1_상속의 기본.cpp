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
	// Child 클래스가 생성될 때 기본적으로 Mother class도 같이 생성된다.
	
	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}
};

// Child 클래스는 Mother 클래스에서 받은 것을 다 사용할 수 있다.
// Mother 클래스로 부터 많은 클래스를 유도해서 받을 수 있다.
class Child : public Mother // dervied class(상속 받은 클래스)
{
private:
	double m_d;
public:
	// constuctor가 존재하는 이유는 메모리가 할당 될 때 initailize를 해달라고 하는 거지 메모리가 먼저 할당되고 초기화를 하는 것이 아니다.

	Child(const int& i_in, const double& d_in)
		// : m_i(i_in), m_d(i_in) // Error
		// : Mother(i_in), m_d (d_in) // O
	{
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const int& i_in, const double& d_in)
	{
		// m_i = d_in; // Error(Mother.m_in이 private인 경우) 
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