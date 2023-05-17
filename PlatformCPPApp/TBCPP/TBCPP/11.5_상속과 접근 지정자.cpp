#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

//class Derived : public Base
//class Derived : protected Base
class Derived : private Base
{
public:
	Derived()
	{
		m_public = 123;
		Base::m_public;
		Base::m_protected; // m_protected = 1234; // 외부에서는 사용할 수 없지만 자식 클래스 내부에서는 사용가능
		// m_private = 123; // Error
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		Derived::m_protected;
	}

};

int main()
{
	Base base;

	base.m_public = 123;

	Derived derived;
	derived.m_public // == this->m_public, pulibc

	// base.m_protected = 123; // Error

	return 0;
}