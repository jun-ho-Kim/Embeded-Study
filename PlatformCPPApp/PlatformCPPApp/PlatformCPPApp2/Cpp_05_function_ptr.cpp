#include <iostream>

void show1(const char* pMsg = nullptr)
{
	std::cout << "show1" << pMsg << std::endl;
}

void show2(const char* pMsg = nullptr)
{
	std::cout << "show2" << pMsg << std::endl;
}



//함수 포인터
//타입을 정합니다.
typedef unsigned __int64 size_t;
typedef void (*pfShow)(const char*); // 함수 포인터 형식 지정
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
	//p 함수는 show 함수와 동일하지만 포인터 형식이다.

	pfnCalc pCalc = nullptr;

	pCalc = Add;
	pCalc(10, 20); // 10 + 20 = 30 입니다.;
	
	pCalc = Sub;
	pCalc(10, 20); // 10 - 20 = -10입니다.;

	pCalc = Div;
	pCalc(10, 20); // 10 / 20 = 0.5입니다.;

	pCalc = Mul;
	pCalc(10, 20); // 10 * 20 = 200입니다.;

	return 1;
}

void Add(const int a, const int b)
{
	std::cout << a << "+" << b << "=" << a + b << "입니다." << std::endl;
}
void Sub(const int a, const int b)
{
	std::cout << a << "-" << b << "=" << a - b << "입니다." << std::endl;
}
void Div(const int a, const int b)
{
	std::cout << a << "/" << b << "=" << a / b << "입니다." << std::endl;
}
void Mul(const int a, const int b)
{
	std::cout << a << "*" << b << "=" << a * b << "입니다." << std::endl;
}