//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int number;

	printf("Input a positive Integer : ");
	scanf("%d", &number);

	if (number % 2 == 0)
		printf("Even");
	else //if (number % 2 != 0)
		printf("Odd");

	return 0;
}

int compute_pow(int base, int exp)
{
	int i, result;

	result = 1;

	for (i = 0; i < exp; i++) {
		result *= base;
	}

	return result;
}