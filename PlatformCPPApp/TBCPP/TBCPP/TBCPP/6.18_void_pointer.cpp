// 모든 데이터 타입의 주소를 저장하는 것이 포인터이다.
// 자료형과 상관없이 포인터를 저장하는 방법?
// void poiner = generic pointer


#include <iostream>

using namespace std;

int main()
{
	int i = 5;
	float f = 3.0;
	char c = 'a';

	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	// void 포인터는 포인터 연산이 불가능하다. 그 이유는 몇 bytes를 더해야하는지 알 수 가 없기 때문이다.
	//cout << ptr + 1 << endl; // Error

	cout << &c << " " << ptr << endl; // a儆儆儆儆

	//cout << *ptr << endl; // 어떤 타입인지 몰라서 dereferencing이 안된다.
	cout << *static_cast<float*>(ptr) << endl; // 3

	// void 포인터를 사용하는 경우 다형성을 사용할 때 부득이하게 사용할 수 있다.
	// c++ 문법에서는 추가된 문법 중에 개선할 수 있는 코드를 작성할 수 있다. 나중에 살펴보자.
	// void 포인터를 살펴보면 포인터의 특성에 대해 이해해볼 수 있다.
	// 많이 쓰지는 않을 것이다.
}