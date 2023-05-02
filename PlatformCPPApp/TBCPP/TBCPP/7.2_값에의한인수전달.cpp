#include <iostream>
using namespace std;

void doSomthing(int y)
{
	cout << "In func " << y  <<  " " << &y << endl;
}

int main()
{
	doSomthing(5);	// In func 5 0000000674D0F660

	int x = 6;

	cout << "In main " << x << " " << &x << endl; // In main 6 0000000674D0F684

	// 매개변수로 값이 y로 전달된다. 그리고 y 변수 메모리에 5라는 값이 복사가 되어 초기화가 된다.
	// 6이라는 값만 파라미터에 전닫된다.
	doSomthing(x);	// In func 6 0000000674D0F660
	doSomthing(x+1);// In func 7 0000000674D0F660

	// 값에 의한 전달은 함수 내부 로직이 외부로 영향이 미치지 않는다.

	return 0;
}