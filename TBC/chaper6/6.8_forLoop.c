//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	// Indenfinite loop vs Counting loop
	while (1)
	{
		// do something
	}

	/*
		Couning loop
		1. Counter initialization
		2. Counter check
		3. Counter change
	*/
	/*
	int i;
	i = 1;
	while (i++ < 10)
	{
		printf("%d ", i);
		i++;
	}
	*/
	for (int i = 1; i < 10; i++)
		printF("%d ", i);

	return 0;
}