#include <iostream>

using namespace std;

class Calculator 
{
public:
	// over-loading vs over-riding
	// 생성자 오버로딩
	Calculator() { cout << "calulator::Ctor" << endl; }
	Calculator(int a, int b) { cout << "calulator::Ctor" << endl; }
	Calculator(int a, int b, int c) { cout << "calulator::Ctor" << endl; }
	~Calculator() { cout << "calulator::Dtor" << endl; }

	int add(int x, int y)
	{
		int result = x + y;

		//cout << "int Add result is " << result << endl;

		return result;
	}
	double add(double x, double y)
	{
		double result = x + y;

		//cout << "double Add result is " << result << endl;

		return x + y;
	}
};

// 함수 재정의는 오버라이딩
// 


int main()
{
	Calculator calc;
	int sum1 = calc.add(2, 3);
	double sum2 = calc.add(2.5, 3.5);
	cout << sum1 << "\n"; // 5
	cout << sum2 << "\n"; // 6

	int y = 4;

	return 0;
}