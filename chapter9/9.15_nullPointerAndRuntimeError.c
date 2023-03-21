//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
	int* ptr = 1234;
	printf("%p\n", ptr);
	printf("%d\n", *ptr);
	*/
	// 리디렉션을 하는 과정에서 문제가 생긴다.
	// ptr 포인터 주소 변수가 1234라는 주소를 찾기 못해 에러가 발생하여 런타임에러를 발생시킨다.

	int* save_ptr = NULL;
	int b;

	scanf("%d", &b);

	if (b % 2 == 0) 
	{
		save_ptr = &b;
		printf("%p\n", save_ptr);
		printf("%d\n", *save_ptr);
	}
	// 포인터 변수 초기화를 NULL을 넣는 이유는 NULL이 아닌 경우를 확인하여 사용하기 위해서이다.
	return 0;
}