//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long loop_factorial(int n);
long recursive_factoral(int n);

int main()
{
	int num = 5;

	printf("%d\n", loop_factorial(num));
	printf("%d\n", recursive_factoral(num));

	return 0;
}

long loop_factorial(int n)
{
	int result = 1;
	for (int i = n; i > 0; --i) {
		result *= i;
	}

	return result;
}

long recursive_factoral(int n)
{
	if (n > 1)
	return  n * recursive_factoral(n - 1);

}