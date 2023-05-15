#include <iostream>

using namespace std;

class Base
{
public:
	virtual void show()
	{
		cout << "This is base class" << endl;
	}
};

class Derived : public Base
{
public:
	void show() {
		cout << "This is a derived class." << endl;
	}
};

int main()
{
	Derived d;
	Base* b = &d; // up-casting .... derived -> base
	Derived* d1 = dynamic_cast<Derived*>(b);// 상속 관계에서 dynamic_cast가 이루어짐
	// static_cast
	//   double d=10.0;
	//   int a = static_cast<int>(d);
	// const_cast
	//   const char* msg = "Hello World";
	//   char* txt = cosnt_cast<char*>(msg);
	// dynamic_cast(상속관계)
	//    Base* b = dynamic_cast<Base*>(&d);
	// reinterpret_Cast
	//    void* p = reinterpret_cast<void*>(&d);
	//    Derived* d1 = reinterpert_cast<Derived*>

	Derived* d1 = dynamic_cast<Derived*>(b); 

	if (d1 != nullptr)
	{
		d1->show(); // This is a derived class.
	
	}

	int z = 4;

	return 0;
}