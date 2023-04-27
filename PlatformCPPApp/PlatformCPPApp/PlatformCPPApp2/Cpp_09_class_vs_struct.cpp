#include <iostream>
#include <string>
#include <vector>

class student
{
public:
	student()
	{
		_name = "unknown"; _age = 9999;
		std::cout << "student::ctor" << std::endl;
	}
	student(std::string name, int age)
	{
		_name = name; _age = age;
		std::cout << "student::ctor(name, age)" << std::endl;
	}
	~student()
	{
		std::cout << "student::dtor" << std::endl;
	}
public: 
	void setInfo(std::string name, int age)
	{
		_name = name; _age = age;
	}
private:
	std::string _name;
	int _age;
};

struct _stClass
{
	std::string subject; //kor, eng, math
	int score;
};


student::student()
{
}

student::~student()
{
}

int main()
{
	return 0;
}