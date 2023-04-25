#include <iostream>

void show1(const char* pMsg = nullptr)
{
	std::cout << "show1" << pMsg << std::endl;
}

void show2(const char* pMsg = nullptr)
{
	std::cout << "show2" << pMsg << std::endl;
}



//�Լ� ������
//Ÿ���� ���մϴ�.
typedef unsigned __int64 size_t;
typedef void (*pfShow)(const char*); // �Լ� ������ ���� ����
typedef void (*pfnCalc)(int, int);

void Add(int, int);
void Sub(const int, const int);
void Div(const int, const int);
void Mul(const int, const int);

int main()
{
	size_t aa = 10;

	show1("hello");
	show1("c++ world");
	show2("hello");
	show2("c++ world");

	pfShow p = show1;
	p = show2;

	p("pfn::hello");
	p("pfn::c++ hello");
	//p �Լ��� show �Լ��� ���������� ������ �����̴�.

	pfnCalc pCalc = nullptr;

	pCalc = Add;
	pCalc(10, 20); // 10 + 20 = 30 �Դϴ�.;
	
	pCalc = Sub;
	pCalc(10, 20); // 10 - 20 = -10�Դϴ�.;

	pCalc = Div;
	pCalc(10, 20); // 10 / 20 = 0.5�Դϴ�.;

	pCalc = Mul;
	pCalc(10, 20); // 10 * 20 = 200�Դϴ�.;

	return 1;
}

void Add(const int a, const int b)
{
	std::cout << a << "+" << b << "=" << a + b << "�Դϴ�." << std::endl;
}
void Sub(const int a, const int b)
{
	std::cout << a << "-" << b << "=" << a - b << "�Դϴ�." << std::endl;
}
void Div(const int a, const int b)
{
	std::cout << a << "/" << b << "=" << a / b << "�Դϴ�." << std::endl;
}
void Mul(const int a, const int b)
{
	std::cout << a << "*" << b << "=" << a * b << "�Դϴ�." << std::endl;
}