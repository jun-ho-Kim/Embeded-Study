/*
class calc 를 만듭니다.

특성 : 두 값과 연산자 기호 마지막으로 그 결과를 저장하는 변수를 만듭니다.
	 int a, b
	 char operator '+','-','/','*'
	 double result
계산기능/
public:
  add() a+b=c입니다.
  sub() a-b=c입니다.
  div() a/b=c입니다.
		단, 아래수가 0이면 계산을 할 수 없습니다. error를 출력하세요.
		"divide zero is not supported"
  mul() a*b=c입니다.
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