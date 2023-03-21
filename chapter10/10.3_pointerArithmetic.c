//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long long* ptr = 0; // try double*, long long, char*, void*
	// void 타입을 사용하면 unkown 사이즈를 사용
	// void 포인터를 사용할 때는 하드웨어나 고효율 컴퓨팅을 할 때 void 포인터를 사용한다.
	printf("%p %lld\n", ptr, (long long)ptr);

	ptr += 2; // 포인터에 어떤 숫자를 더하는 것은 주소 값에 더하는 의미보다는 자료형의 크기에 맞추어서 주소값을 더해준다.

	printf("%p %lld\n", ptr, (long long)ptr);

	//ptr = -ptr;// Not working
	//ptr = +ptr;// Not working

	/* Subtraction */
	double arr[10];
	double* ptr1 = &arr[3], * ptr2 = &arr[8];

	//int* ptr3 = ptr2 + ptr1; // Not Working // 포인터의 주소를 더하는 것은 의미가 없다.
	int i = ptr2 - ptr1; //포인터의 빼기는 배열 안에서 index차이가 얼마인가를 계산해준다.

	printf("%lld %lld %d\n", (long long)ptr1, (long long)ptr2, i);

	return 0;
}