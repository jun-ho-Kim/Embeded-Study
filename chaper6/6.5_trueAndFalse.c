//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int tv, fv;
	tv = (1 < 2);
	fv = (1 > 2);

	printf("True is %d\n", tv); // 1
	printf("False is %d\n", fv); // 0

	int i = -5;
	while (i)
		printf("%d is true\n", i++);
	printf("%d is false\n", i);

	return 0;
}