#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;

	char c[10] = "apple";
	char d[10] = "pie";

	printf("%d\n", a + b);
	printf("%s\n", c + d); // Error

	return 0;
}