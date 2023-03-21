//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//void swap(int u, int v) // call by value로 호출하는 경우
void swap(int* u, int* v) // call by pointer로 호출하는 경우
{
	printf("%p %p\n", u, v);

	int temp = *u;
	*u = *v;
	*v = temp;

	//int temp = u;
	//u = v;
	//v = temp;
}

int main()
{
	int a = 123;
	int b = 456;

	printf("%p %p\n", &a, &b);
	// swap 함수를 사용할 때 swap 함수 매개변수를 call by value로 호출하는 경우 main에서 사용되는 변수의 주소값과 달라 값이 swap되지 않는다.
	// 그래서 포인터 주소를 매개변수를 전달해주는 call by pointer로 호출하여 함수의 매개변수를 사용한다.
	//swap(a, b);
	swap(&a, &b);
	printf("%d %d\n", a, b);

	return 0;
}