#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
		variable scopes (visibility) // visibility; 변수의 가시성
		- block, function, function prototype, file.// variable scopes의 4가지 종류

		// filescope를 갖는 다는 것은 global variable이라도고 하고 linkage와 연관이 있다.
		// global varible은 file sope 내에 어디서든 사용할 수 있다.
	*/

int g_i = 123; // global varible
int g_j;

void func1()
{
	g_i++; // uses g_i
}

void funct2()
{
	g_i += 2; // use g_i

	// local = 456; // Error
}

int main()
{
	int local = 1234;

	func1();
	funct2();

	printf("%d\n", g_i); // 126 // use g_i
	printf("%d\n", g_j); // 0 // Not initialized? // 0으로 초기화하기 위해 BSS Sagment에 저장이 되었다.
	printf("%d\n", local); // 1234

	return 0;
}