#include <iostream>
using namespace std;

int main()
{
	/*
	//변수 앞에 const를 붙이면 변수 주소를 할당하려는 포인터에도 const를 붙여주어야 한다.
	// 변수에 const가 붙어서 포인터 값 참조는 변경되지 않는다.
	const int value = 5;
	const int* ptr = &value;
	//*ptr = 6; //  Error
	*/

	//------------------------------------------------
	/*
	int value = 5;
	const int* ptr = &value;
	//*ptr = 6; // Error
	value = 6; // 가능
	*/


	//------------------------------------------------
	// 포인터의 참조 값을 바꾸지 못한다. 하지만 ptr의 주소값은 바꿀 수 있다.
	/*
	int value1 = 5;
	const int* ptr = &value1;
	//*ptr = 7; // Error

	int value2 = 6;
	ptr = &value2; // 가능
	*/

	//------------------------------------------------
	/*
	int value = 5;
	int *const ptr = &value;
	*ptr = 10; // 가능
	cout << *ptr << endl;
	int value2 = 8;
	// ptr = &value2; // Error
	*/

	//------------------------------------------------
	// 타입 앞 뒤로 const가 붙으면 참조값 변경과 주소값 변경 둘 다 할 수 없다.
	int value = 5;
	const int *const ptr = &value; 
	//*ptr = 10; // Error
	int value2 = 8;
	// ptr = &value2; // Error

	return 0;
}