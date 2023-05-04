// 매개변수가 여러 개 있을 매번 모든 매개변수의 값을 넣어주는 것은 번거로울 수 있다.
// 매개변수의 기본값을 설정하여 매개변수를 설정해는 것을 생략하는 방법을 살펴보자.
#include <iostream>
using namespace std;

//void printf(int x = 1024); 
// 헤더에도 기본값을 설정해주면 헤더함수나 바디함수 둘 중에 하나만 기본 값을 설정해준다.
// 보통은 헤더에 기본값을 설정해준다.
void printf(int x = 1024)
{
	cout << x << endl;
}

//void printf(int x = 1024, int y ) {} // Error // 매개변수 값을 초기화 할 때는 뒤에서 부터 해준다.

void print_1(int x) {}
void print_1(int x, int y =20) {}

int main()
{
	printf(10);	// 10
	printf();	// 1024

	// print_1(10); //Error // print_1 함수에 x만 값을 넣는 경우 모호성 때문에 에러가 발생

	int y = 4;
}