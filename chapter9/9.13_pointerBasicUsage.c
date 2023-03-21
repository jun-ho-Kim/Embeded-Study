//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b;

	a = 123;

	int* a_ptr;

	a_ptr = &a;

	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	*a_ptr = 456;
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	//b = a_ptr; // b는 주소를 저장하는 타입이 아니기 때문에 주소를 저장하는 경우 warning이 발생
	b = *a_ptr;

	printf("%d\n", b);

	*a_ptr = 789;
	printf("%d\n", b);
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	// b의 값을 바꿔주어도  a는 영향을 받지 않는다.
	b = 12;

	printf("%d\n", b);
	printf("%d %d %p\n", a, *a_ptr, a_ptr);
	
	// 변수로 값을 대입해주어도 주소값이 변하지 않는다.
	a = 1004;
	printf("%d %d %p %d\n", a, *a_ptr, a_ptr, b);

	return 0;
}