//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibonacci(int number);

int main()
{
	for (int count = 1; count < 13; ++count)
	{
		printf("%d ", fibonacci(count));
	}

	return 0;
}

int fibonacci(int number)
{
	printf("fibonacci with %d\n", number);
	// 메모리가 비효율적으로 사용된다. 그리고 중복되서 계산되는 경우가 많다.

	if (number > 2)
		return fibonacci(number-1) + fibonacci(number - 2);
	else
		return 1;
}