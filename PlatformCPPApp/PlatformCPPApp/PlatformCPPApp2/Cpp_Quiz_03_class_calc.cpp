/*
class calc�� ����ϴ�.

Ư�� : �� ���� �� ����� �����ϴ� ������ ����ϴ�.
	int a, b
	char operator + - / *
	double result

�����
public:
	showResult()
	add()
	sub()
	div() ��, �Ʒ� ���� 0�̸� ����� �� �� �����ϴ�. error�� ����ϼ���.
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
//���� ���� ����
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
		std::cout << "����" << _a + _b << "�Դϴ�." << std::endl;
		return _a + _b;
	}
	int sub()
	{
		std::cout << "����" << _a - _b << "�Դϴ�." << std::endl;
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
			std::cout << "�������" << _a / _b << "�Դϴ�." << std::endl;
			return _a / _b;
		}
		
	}
	int mul()
	{
		std::cout << "����" << _a * _b << "�Դϴ�." << std::endl;
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