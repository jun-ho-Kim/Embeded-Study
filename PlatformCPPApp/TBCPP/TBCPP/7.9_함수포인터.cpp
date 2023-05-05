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
	//�Լ��� �������̰� �޸𸮿� ����.
	cout << func << endl;	// 00007FF7B16D11FE

	int(*fcnptr)() = func; // �Լ��� �����͸� �����ϴ� ���

	cout << fcnptr() << endl; // 5

	fcnptr = goo;

	cout << fcnptr() << endl; // 10

	// �Լ� �����͸� �Լ� �Ķ���ͷ� �޴� ���

	std::array<int, 10> my_array = { 0,1,2,3,4,5,6,7,8,9 };

	printNumbers(my_array, isEven);
	printNumbers(my_array, isOdd);

	// #include <functional>
	std::function<bool(const int&)> fcnptrFunctional = isEven;
	printNumbersFunctional(my_array, fcnptrFunctional);
	fcnptrFunctional = isOdd;
	printNumbersFunctional(my_array, fcnptrFunctional);

	// �Լ��� �����͸� ����Ͽ� �Ķ���Ϳ� �־��� �� �ִ�.
	// �Լ� �����͸� ����ϸ� ���α׷����� �ξ� ����ٴ������� �ű��� ���·� ������ �� �� ������
	// �����ϰ� ���� ����� �� ���ְ� �ȴ�.

	// �Լ������͸� �����ϸ� �������� ������ �� �ְ� �ȴ�.
	int y = 5;
}
