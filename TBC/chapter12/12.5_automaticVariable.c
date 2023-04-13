#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
	/*
		Automatic storage class
		- Automatic storage duration(블록을 벗어나면 메모리를 반납한다.), block scope, no linkage
		- Any variable declared in a block or function header
	*/

void func(int k); // Automatic storage

int main() // Note; main() is a function
{
	auto int a; // keyword auto : a storage-class specifier
	// auto 키워드는 automatic varible 인 것을 명확하게 하기 위해 사용하지만 auto 키워드가 없어도 똑같이 작동한다.
	// C++에서는 auto는 다른 의미로 사용이 된다.
	a = 1024; // 자동 변수들은 초기화를 반드시 해주어야 한다.
	//* BSS Sagement에 있는 전역 변수들은 처음에 한 번만 초기화를 해줘도 되고 컴파일에서 0으로 초기화 해준다.
	// 지역 변수들은 stack에 입출입이 빈번하기 때문에 컴파일에서 초기화를 해주는데 비용이 발생하기 때문에 자동으로 초기화를 해주지 않는다.

	int i = 1;
	int j = 2;

	printf("i %lld\n", (long long)&i); // i 15727412

	{
		int i = 3; // name hiding
		printf("i %lld\n", (long long)&i); // i 15727388

		//int ii = 123;

		// j is visible here
		printf("j = %d\n", j); //j = 2
	}
	// ii is not visible here
	printf("i %lld\n", (long long)&i); //i 15727412
	

	for (int m = 1; m < 2; m++)
		printf("m %lld\n", (long long)&m); // m 15727376

	func(5);

	for (int m = 3; m < 4; m++)
	{
		printf("m %lld\n", (long long)&m); // m 15727364
	}

	return 0;
}

void func(int k)
{
	int i = k * 2;
	// do something with i and k
	// 메모리를 아끼기 위해서 main 함수에서 선언된 지역변수를 함수 내부에서는 사용할 수 없다.
	printf("i %lld\n", (long long)&i); // i 15727132
}