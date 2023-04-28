/*
class calc �� ����ϴ�.

Ư�� : �� ���� ������ ��ȣ ���������� �� ����� �����ϴ� ������ ����ϴ�.
	 int a, b
	 char operator '+','-','/','*'
	 double result
�����/
public:
  add() a+b=c�Դϴ�.
  sub() a-b=c�Դϴ�.
  div() a/b=c�Դϴ�.
		��, �Ʒ����� 0�̸� ����� �� �� �����ϴ�. error�� ����ϼ���.
		"divide zero is not supported"
  mul() a*b=c�Դϴ�.
  */
#include <iostream>

class calc {
private:
	int a;
	int b;
	char op;
	double result;
public:
	calc() : a(0), b(0), op('+'), result(0) { std::cout << "calc::ctor" << std::endl; }
	~calc() { std::cout << "calc::dtor" << std::endl; }
	
	void setValue(int& v1, int& v2) { a = v1, b = v2; }
	void setOperator(char value) { op = value; }

	void add() { result = a + b; std::cout << a << op << b << "=" << result << std::endl; }
	void sub() { result = a - b; std::cout << a << op << b << "=" << result << std::endl; }
	void mul() { result = a * b; std::cout << a << op << b << "=" << result << std::endl; }
	void div() {
		if (b == 0) { std::cout << "divide zero is not supported" << std::endl; }
		else {
			result = static_cast<double>(a) / b;
			std::cout << a << op << b << "=" << result << std::endl;
		}
	}
	double getResult() {
		switch (op) 
		{
			case '+': add(); break;
			case '-': sub(); break;
			case '/': div(); break;
			case '*': mul(); break;
			default:
				std::cout << "invalid operator" << std::endl;
				break;
		}
		//std::cout << a << op << b << "=" << result << std::endl;
		return result;
	}
};

int main()
{

	{
		calc cc;
		int a = 10, b = 20;
		cc.setValue(a, b);
		//cc.setOperator('+');
		//cc.getResult();
		cc.add();

		cc.setOperator('*');
		cc.getResult();

		cc.setOperator('-');
		cc.getResult();

		cc.setOperator('/');
		cc.getResult();

	}
	
}