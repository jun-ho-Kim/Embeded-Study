#include <iostream>
#include <string>
#include <vector>

using namespace std;


// input -> funtcion -> output
// input -> function(variable, struct, class -> logic)
// output
// h: input - varibale
// ����
// output

class Calc
{
public:
	Calc()
		: _a(0.0)
		, _b(0.0)
		, _c(0.0)
	{
		_a = 0.0;
		_b = 0.0;
		_c = 0.0;
		std::cout << "ctor" << std::endl;
	};
	~Calc()
	{
		std::cout << "ctor" << std::endl;
	};
	void Input(int a, int b)
	{
		// �ܺο� �ִ� ���� ������ ��... copy
		//int _a, _b;
		_a = a;
		_b = b;
		// �ܺο� �ִ� ���� ����Ű�� �־�� �� pointer
		int* _pa, _pb;
		// �޸� ���� ���� �� ������ �����ϰ� �־�� ��.
		int c = a + b;
	}
	void Input(int* a, int* b)
	{
		// �ܺο� �ִ� ���� ����Ű�� �־�� �� 
		// �޸� ���� ���� �� ������ �����ϰ� �־�� ��.
		int* _pa = a;
		int* _pb = b;
	}

	double Output()
	{
		return _c;
	}
private:
	void FunctionA()
	{
		_c = _a + _b;

		int aa = _a;
		int bb = _b;
		int _aaaa = _a * 10 + 10;
		int _bbbb = (_aaaa - 10) / 10;

		_c = _a + _b;

	}
	// private�� ������ �������ָ� class ��ü���� ����� �� �ִ�.
	double _a = 0;
	double _b = 0;
	double _c = 0;
};

int main()
{

}

