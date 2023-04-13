//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int int_min(int, int);

int main()
{
	int i1, i2;

	while (1)
	{
		printf("Input two intergers : ");

		if (scanf("%d %d", &i1, &i2) != 2) break;

		int lesser = int_min(i1, i2);

		printf("The lesser or %d and %d is %d\n", i1, i2, lesser);
	}

	printf("End.\n");

	return 0;
}

int int_min(int i, int j)
{
	int min;

	if (i < j)
		min = i;
	else
		min = j;
	// return i < j ? i : j;
	return min;
}