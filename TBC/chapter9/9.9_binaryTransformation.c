//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	10
	10 / 2 = 5, remainder = 0
	5 / 2 = 2, remainder = 1
	2 / 2 = 1, remainder = 0
	1 / 2 = 0, remainder = 1
*/

void print_binary(unsigned long  n);
void print_binary_loop(unsigned long  n);

int main()
{
	unsigned long num = 10;

	print_binary_loop(num);
	printf("\n");
	print_binary(num);


	return 0;
}

void print_binary_loop(unsigned long num)
{

	while (1)
	{
		int quotient = num / 2;
		int remainder = num % 2;

		printf("%d", remainder);
		 
		num = quotient;

		if (num == 0) break;
	}
		//printf("\n");
	

	/*
	* 내가 짠 코드
	int n = num;
	char bi[10];
	int i = 0;
	while (n != 0)
	{
		if (n % 2 != 0)
			bi[i] = 1;
		else
			bi[i] = 0;

		n = n / 2;
		i++;
	}
	// TODO: bi resverse
	printf("binary loop bi %d", bi);
	*/
}

void print_binary(unsigned long num)
{
	int remainder = num % 2;

	num = quotient;

	if (num >= 2) print_binary(num /2);
	printf("%d", remainder);

	/*
	* 내가 짠 코드
	char bi[10];
	int i = 0;
		if (num % 2 != 0)
			bi[i] = 1;
		else
			bi[i] = 0;

		num = num / 2;
		i++;
		if(num > 0)
		print_binary(num);


	printf("binary loop bi %s", bi);
	*/
}