#include <iostream>
using namespace std;

// 참조는 const를 편하게 사용할 수 있고 함수의 파라미터로 참조를 사용할 때 아주 편해진다.

void doSomething(const int& x)
{
	cout << x << endl;
}

int main()
{
	/**/
	int x = 5;
	int &ref_x = x;

	const int& ref_2 = ref_x;

	// 함수의 파라미터가 참조면 아래와 같이 가능하다.
	doSomething(x); // 5
	doSomething(1);	// 1
	doSomething(x+3);// 8
	doSomething(3*4);// 12


	return 0;
}