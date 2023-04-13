//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[10];

	int num = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < num; ++i)
		arr[i] = (i + 1) * 100;

	int* ptr = arr;

	printf("%p %p %p\n", ptr, arr, &arr[0]);

	ptr += 2;

	printf("%p %p %p\n", ptr, arr + 2, &arr[2]);

	// Note: arr += 2 // invalid // 배열의 이름이 포인터처럼 사용될 수 있지만 포인터와 완전히 동일하지 않는다.
	
	// ()를 사용하는 경우 포인터 주소값으로 계산하여 출력한다..
	printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]); // 400 400 400
	
	// Warning
	// ()를 사용하지 않으면 *변수 계산 후 연산을 진행한다.
	printf("%d %d %d\n", *ptr + 1, *arr + 3, arr[3]); // 301 103 400

	for (int i = 0, *ptr = arr; i < num; ++i)
	{
		printf("%d %d\n", *ptr++, arr[i]);
		//printf("%d %d\n", *(ptr+i), arr[i]);
		//printf("%d %d\n", *ptr + i, arr[i]); // *(ptr+i) != *ptr + i
	}

	return 0;
}