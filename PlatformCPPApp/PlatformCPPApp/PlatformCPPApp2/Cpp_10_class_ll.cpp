#include <iostream>
#include <string>
#include <vector>

using namespace std;


// input -> funtcion -> output
// input -> function(variable, struct, class -> logic)
// output
// h: input - varibale
// 선언
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
		// 외부에 있는 것을 가지오 옴... copy
		//int _a, _b;
		_a = a;
		_b = b;
		// 외부에 있는 것을 가리키고 있어야 함 pointer
		int* _pa, _pb;
		// 메모리 저장 공간 이 내용을 차지하고 있어야 함.
		int c = a + b;
	}
	void Input(int* a, int* b)
	{
		// 외부에 있는 것을 가리키고 있어야 함 
		// 메모리 저장 공간 이 내용을 차지하고 있어야 함.
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
	// private에 변수를 설정해주면 class 전체에서 사용할 수 있다.
	double _a = 0;
	double _b = 0;
	double _c = 0;
};

int main()
{

}

