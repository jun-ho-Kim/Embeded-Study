// 많은 프로그래머들이 자신의 프로그램을 빠르게 만들고 싶어한다.
// 이때 인라인함수를 사용하여 최적화를 하고자 하는데 이게 효과가 있을지 살펴보자.

// inline 함수를 사용하면 함수가 아닌 것 처럼 작동한다.

#include <iostream>
using namespace std;

inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;

	// 인라인 함수 사용 시 컴파일에서 작동하는 원리
	// 인라인 함수를 사용하게 되도 컴파일러에서 인라인 함수로 변경을 안 할 수도 있다.
	cout << (5 > 6 ? 6 :5) << endl;
	cout << (3>2 ? 2:3) << endl;

	// 인라인 함수를 사용한다고 해서 무조건 빨라지는 것도 아니고 
	// 요즘 컴파일러에서는 인라인 함수를 사용하면 빨라질 것 같으면 컴파일에서 알아서 인라인 함수를 사용한다.

	// 코딩 스킬로 최적화를 하는 것 보다 코딩 구조를 바꾸는 것(객체지향, 데이터 드리븐 등)으로 해보자.
}