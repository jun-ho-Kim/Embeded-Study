#include <iostream>
#include <string>

class Base
{
public:
	Base()
	{};
	virtual ~Base() {};
	virtual void Show() = 0;
};

class ChildA : public Base
{
public:
	ChildA() {};
	~ChildA() {};
	void Show()
	{
		std::cout << "ChildA" << std::endl;
	}
};


class ChildB : public Base
{
public:
	ChildB() {};
	~ChildB() {};
	void Show()
	{
		std::cout << "ChildB" << std::endl;
	}
};

int main()
{
	ChildA* a = new ChildA;
	ChildB* b = new ChildB;

	Base* pBase;
	pBase = dynamic_cast<Base*>(a);
	pBase->Show();

	pBase = dynamic_cast<Base*>(b);
	pBase->Show();

	delete pBase;

	int z = 3;

	return 0;
}