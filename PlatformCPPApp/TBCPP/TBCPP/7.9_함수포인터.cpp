#include <iostream>
#include <array>
#include <functional>
using namespace std;

int func()
{
	return 5;
}

int goo()
{
	return 10;
}

typedef bool(*check_fcn_t) (const int&);
// == using check_fcn_t = bool(*check_fcn_t)(const int&)

void printNumbers(const array<int, 10>& my_array, 
	check_fcn_t check_fcn /* == bool(*check_fcn)(const int&)*/)
{
	for (auto element : my_array)
	{
		if (check_fcn(element) == true) cout << element;
		//if (!print_even && element % 2 == 1) cout << element;
	}
	cout << endl;
}

void printNumbersFunctional(const array<int, 10>& my_array,
	std::function<bool(const int&)> check_fcn)
{
	for (auto element : my_array)
	{
		if (check_fcn(element) == true) cout << element;
		//if (!print_even && element % 2 == 1) cout << element;
	}
	cout << endl;
}

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 != 0) return true;
	else return false;
}

int main()
{
	//함수도 포인터이고 메모리에 들어간다.
	cout << func << endl;	// 00007FF7B16D11FE

	int(*fcnptr)() = func; // 함수의 포인터를 선언하는 방법

	cout << fcnptr() << endl; // 5

	fcnptr = goo;

	cout << fcnptr() << endl; // 10

	// 함수 포인터를 함수 파라미터로 받는 방법

	std::array<int, 10> my_array = { 0,1,2,3,4,5,6,7,8,9 };

	printNumbers(my_array, isEven);
	printNumbers(my_array, isOdd);

	// #include <functional>
	std::function<bool(const int&)> fcnptrFunctional = isEven;
	printNumbersFunctional(my_array, fcnptrFunctional);
	fcnptrFunctional = isOdd;
	printNumbersFunctional(my_array, fcnptrFunctional);

	// 함수를 포인터를 사용하여 파라미터에 넣어줄 수 있다.
	// 함수 포인터를 사용하면 프로그래밍이 훨씬 다재다능해지고 신기한 형태로 구성이 될 수 있으며
	// 복잡하고 많은 기능을 할 수있게 된다.

	// 함수포인터를 이해하면 다형성에 이해할 수 있게 된다.
	int y = 5;
}
