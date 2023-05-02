// 참조에 의한 인수 전달(Call by reference)를 알아보자. 강사가 가장 선호하는 방식이다.
// 오픈 소스 볼 때 도 많이 등장한다.

#include <iostream>
#include <vector>
using namespace std;

// const type &variable 로 입력인 것 처럼 type &varible을 return인 것 처럼 사용하자.
void getSinCos(const double &degrees, double& sin_out, double& cos_out)
{
	// static 변수이기 때문에 딱 한 번만 계산이 된다.
	static const double pi = 3.141592 / 180.0;

	
	const double radians = degrees * pi;
	
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

typedef int* pint;

//void foo(int& x)
//void foo(int*& x) // 포인터를 reference로 받는 방법
//void foo((int*) &x)로 해석을 하면 편하다.
void foo(pint &x)
{
	cout << x << endl;
}

// 값에 의한 호출은 함수 안에서 새롭게 변수를 정의를 하고 복사를 한다.
// 참조에 의한 호출은 변수 자체를 넘기기 때문에 복사가 이루어지지 않는다.

void addOne(int& y) // Reference로 전달하면 y로 reference가 넘어온다.
{
	cout << y << " " << &y << endl;	// 5 0000004D266FFA44

	y = y + 1;
}

//void printElement(int(&arr)[4]) 
void printElement(const vector<int>& arr)
// (&arr)[4]의 개수가 파라미터의 배열과 같아야 한다. 보통은 정적 배열보다 동적 배열을 사용한다.
// 강사는 클래스로 만들어서 전달하여 int(&arr)[4] 처럼 사용하지 않는다.
// std::array나 std::vector를 사용해서 보내면 referece로 보내는 것이 같기 때문에 std::array나 std::vector를 사용
{
}

int main()
{
	int x = 5;

	cout << x << " " << &x << endl;	// 5 0000004D266FFA44
	// x라는 변수 자체가 인자로써 전달이 된다.
	addOne(x);

	cout << x << " " << &x << endl;	// 6 0000004D266FFA44
	
	// 이런 성질을 함수의 출력을 가지고 오는데 사용된다.

	double sin(0.0);
	double cos(0.0);

	// C++은 리턴 값이 하나이기 때문에 참조에 의한 전달에 의하여 함수에 return하는 것처럼 사용한다.
	getSinCos(30.0, sin, cos);

	cout << sin << " " << cos << endl; // 0.5 0.866025


	// 참조에 의한 인수 전달의 단점
	// 값 자체로 전달하면 함수에서 받지는 못한다.
	//	foo(6);
	// void foo(const int& x)

	// 요즘에는 입력으로 들어오는 것은 const로 받는다.
	// 최근에 modern C++에서는 
	//		1. return value openvisaion?, 
	//		2. 여러 개의 return 값을 반환하는 것이 복잡하지 않게 되었다.



	int y = 5;
	//int* ptr = &x;
	pint ptr = &x;

	foo(ptr);

	// array를 파라미터에 전달하는 방법

	//int arr[]{ 1,2,3,4 };

	vector<int> arr{ 1,2,3,4 };

	printElement(arr);

	return 0;
}

// 참조의 의한 인자 전달 방식은 강사가 선호하고 효율성도 높고 덜 골치아프면서 편리하다. 
// 참조의 의한 전달을 사용하는 방식으로 코딩하면 대부분의 경우에 크게 문제 없이 효율적으로 코딩할 수 있다.