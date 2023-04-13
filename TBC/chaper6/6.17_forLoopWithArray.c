//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main()
{
	int my_arr[SIZE];

	// prepare for array date
	for (int i = 0; i < SIZE; ++i) {
		my_arr[i] = i * i;
	}

	for (int i = 0; i < SIZE; ++i) {
		printf("%d ", my_arr[i]);
	}


	/*
	int sum = 0;
	int numbers[SIZE];

	printf("Enter %d number : ", SIZE);
	for (int i = 0; i < SIZE; ++i) {
		scanf("%d", &numbers[i]);
	}

	for (int i = 0; i < SIZE; ++i) {
		sum += numbers[i];
	}

	// for문을 두 개로 나눈 이유는 나중에 데이터가 많이지면 이것이 더 효율적일 수도 있다.
	// c++나 하드웨어 병렬처리 할 때 직관적인 상식과 다른 컴퓨터 기법들을 배우게 될 때 이해 될 것이다.

	printf("Sum = %d", sum);
	*/

	return 0;
}