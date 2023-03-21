//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	unsigned num;
	bool isPrime; //flag, try bool type

	scanf("%u", &num);

	isPrime = true;

	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) {
			isPrime = false;
			if((num / i) == i) 
				printf("%u is divisible by %u\n", num, i);
			else 
				printf("%u is divisible by %u, %u.\n", num, num/i, i);
		}
	}

	if (isPrime)
		printf("%u is a prime number.\n", num);
	else 
		printf("%u is not a prime number.\n", num);

	return 0;
}