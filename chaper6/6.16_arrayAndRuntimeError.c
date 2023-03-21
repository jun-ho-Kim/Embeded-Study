//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_DAYS 365

int main()
{
	/*
	char my_char[] = "Hello, World!";

	int daily_temperature[NUM_DAYS];
	double stock_price_history[NUM_DAYS];

	printf("%zd\n", sizeof(stock_price_history)); // 2920 // 8byte * 365
	printf("%zd\n", sizeof(double) * NUM_DAYS); // 2920 // 8byte * 365
	printf("%zd\n", sizeof(stock_price_history[0])); // 8 // 8byte
	*/

	int my_numbers[5];
	/*

	my_numbers[0] = 1;
	my_numbers[1] = 3;
	my_numbers[2] = 4;
	my_numbers[3] = 2;
	my_numbers[4] = 1024;

	scanf("%d", my_numbers);
	//== scanf("%d", &my_numbers[0]);

	printf("%d\n", my_numbers[0]);
	printf("%d\n", my_numbers[1]);
	printf("%d\n", my_numbers[2]);
	printf("%d\n", my_numbers[3]);
	printf("%d\n", my_numbers[4]);
	*/

	/* Runtime Error */
	//my_numbers[4] = 123; // out of bound // 컴파일할 때 에러를 잡아주지 않는다. 실행할 때 런타임에러가 발생한다.

	//my_numbers = 7; // compile  error

	//printf("%d\n", my_numbers[6]); // out of bound

	return 0;
}