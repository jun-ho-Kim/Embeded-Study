// 특정 경우에 포인터보다 편한 참조 변수에 대해 알아보자.

#include <iostream>
using namespace std;

void doSomething(int& n); //doSomething(const int& n) // 요즘에는 함수에서 값을 바꾸지 못하도록 코딩을 한다. 그럴 경우 매개변수에 const를 붙여준다.
void printElement(int(&arr)[5]);

struct Somthing
{
	int v1;
	float v2;
};

struct Other
{
	Somthing st;
};

int main()
{
	//------------------------------------------------
	int value = 5;

	int* ptr = nullptr;
	ptr = &value;


	//참조변수
	int& ref = value;
	cout << ref << endl;

	ref = 10;

	cout << value << " " << ref << endl; // 10 10

	//참조는 별명처럼 사용이 될 수 있다.
	

	cout << &value << endl; //006FFCAC
	cout << &ref << endl;	//006FFCAC
	cout << ptr << endl;	//006FFCAC
	cout << &ptr << endl;	//006FFCA0

	//reference는 반드시 초기화가 되어야 한다.

	// int &ref = 104; // 참조변수는 리터럴을 받을 수 없다. l-value만 받을 수 있다.
	//------------------------------------------------
	/*
	int x = 5;
	int& ref = x;

	const int y = 8;
	const int& ref = y;
	*/

	//------------------------------------------------
	/*
	int value1 = 5;
	int value2 = 10;

	int& ref1 = value1;

	cout << ref1 << endl;	// 5
	ref1 = value2;

	cout << ref1 << endl;	// 10
	*/

	int n = 5;

	cout << n << endl;	//5
	cout << &n << endl; //006FF9F8


	doSomething(n);

	cout << n << endl; //  void doSomething(int &n)인 경우 10, void doSomething(int n)인 경우 5

	// reference를 사용하면 변수 자체를 넘긴다.
	// 포인터는 변수 자체를 복사를 해야된다.

	//------------------------------------------------
	// 배열을 참조로 받는 것
	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };

	printElement(arr);

	//------------------------------------------------
	// 구조체 사용
	Other ot;
	int& v1 = ot.st.v1;
	v1 = 1;

	//------------------------------------------------
	int value = 5;
	//아래 2개는 기능 상 동일하다.
	int* const ptr = &value;
	int& ref = value;
	*ptr = 10;
	ref = 10;

	return 0;
}

void doSomething(int& n) //doSomething(const int& n) // 요즘에는 함수에서 값을 바꾸지 못하도록 코딩을 한다. 그럴 경우 매개변수에 const를 붙여준다.
{
	n = 10;
	cout << "In DoSometing " << n << endl; // In DoSometing 10
	cout << &n << endl;//006FF9F8
}

void printElement(int(&arr)[5])
{
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}