/*
class calc를 만듭니다.

특성 : 두 값과 그 결과를 저장하는 변수를 만듭니다.
	int a, b
	char operator + - / *
	double result

계산기능
public:
	showResult()
	add()
	sub()
	div() 단, 아래 수가 0이면 계산을 할 수 없습니다. error를 출력하세요.
		"divide zero is not supported"
	mul()
*/

#include <iostream>
#include <vector>
#include <string>


class calc
{
public:
	calc() : a(0), b(0), op('+'), result(0) { std::cout << "calc::ctor" <<  };
	~calc() { };

	void setValue(int);

private:
	int a;
	int b;
	char op;
	double result;

};

calc::calc()
{
}

calc::~calc()
{
}

/*
//내가 적은 정답
class calc
{
public:
	calc();
	calc(int a, int b)
	{
		_a = a; _b = b;
	}
	int add()
	{
		std::cout << "합은" << _a + _b << "입니다." << std::endl;
		return _a + _b;
	}
	int sub()
	{
		std::cout << "차는" << _a - _b << "입니다." << std::endl;
		return _a - _b;
	}
	int div()
	{	
		if (_b == 0)
		{
			std::cout << "divide zero is not supported" << std::endl;
			return 1;
		}
		else 
		{
			std::cout << "나누기는" << _a / _b << "입니다." << std::endl;
			return _a / _b;
		}
		
	}
	int mul()
	{
		std::cout << "곱은" << _a * _b << "입니다." << std::endl;
		return _a * _b;
	}
	~calc() 
	{
		std::cout << "calc::dtor" << std::endl;
	}
private:
	int _a, _b;

};
*/
int main()
{
	calc calc(2, 0);
	calc.add();
	calc.div();
	calc.mul();
	calc.sub();
}