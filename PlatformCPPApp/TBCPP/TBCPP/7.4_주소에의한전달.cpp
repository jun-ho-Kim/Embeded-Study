#include <iostream>
using namespace std;

void foo(int* ptr)
{
	cout << *ptr << " " << ptr << " " << &ptr << endl; //5 0000006400AFF634

	//void foo(const int* ptr)

	*ptr = 10; // 인자의 const 사용시 값 변경 불가
}

// 포인터를 사용하여 함수의 출력인 것 처럼 하기도 한다.
void getSinCos(const double degrees, double* sin_out, double* cos_out)
{
	*sin_out = 1.0;
	*cos_out = 2.0;
}

//void foo(int* const ptr) 
// 하는 방식은 함수 내에 주소 값을 바꿔도 포인터에 의한 전달도 값에 의한 전달이기 때문에 함수가 끝나면 함수 내 주소변경은 적용되지 않는다.

int main()
{
	int value = 5;

	cout << value << " " << &value << endl;// 5 00000086FA51FBE4

	//foo(value); // Error

	int* ptr = &value;	
	// 포인터 변수도 변수이기 때문에 주소의 값을 값에 의해 전달된다.
	// 즉 주소 값도 복사가 된다.
	cout << &ptr << endl;// 0000006400AFF658

	foo(ptr);	//5 0000006400AFF634 0000006400AFF610
	foo(&value);//5 0000006400AFF634 0000006400AFF610

	//foo(5); // Error // 리터럴이라서 에러 발생

	double degrees = 30;
	double sin, cos;

	getSinCos(degrees, &sin, &cos);

	cout << sin << " " << cos << endl; // 1, 2

	// 실용적인 측면에서 referece로 전달하는게 좋다.
	// 포인터에 의한 전달도 사실상 값에 의한 전달이다.

	int x = 5;
}