//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long get_long(void);

int main()
{
	while (1) {
	printf("Please input a integer between 1 and 100.\n");
	long number = get_long();

	if (number > 1 && number < 100) {
		printf("OK. Thank you.\n");
		break;
	}
	else
		printf("Wrong input. Please try again.\n");
	}

	return 0;
}

long get_long(void)
{
	printf("Please input an interger and press enter.");

	long input;
	char c;

	while (scanf("%ld", &input) != 1)
	{
		printf("Your input - ");

		while ((c = getchar()) != '\n')
			putchar(c); // input left in buffer

		printf(" - is not an interger. Please try again.");
	}

	printf("Your input %ld is an integer. Thank you.\n", input);

	return input;
}