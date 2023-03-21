//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char get_choice(void);
int get_integer(void);
char get_first_char(void);
void count(void);

int main()
{
	int user_choice;

	while ((user_choice = get_choice()) != 'q')
	{
		switch (user_choice)
		{
		case 'a':
			printf("Avengers assemble!\n");
			break;
		case 'b':
			putchar('\a');
			break;
		case 'c': 
			count();
			break;
		default:
			printf("Error with %d\n", user_choice);
			exit(1);
			break;
		}
	}


	/*
	* 내가 짠 코드
	char c;
	char num;

	printf("Enter the letter of your choice: \n");
	printf("a. avengers.%9 b.beep.\nc.count %9 q.quit\n");

	while ((c = getchar()) != 'q') 
	{
		printf("Enter the letter of your choice: \n");
		printf("a. avengers.%9 b.beep.\nc.count %9 q.quit\n");
		if (c == 'a')
			printf("Avengers assmble!");
		if (c == 'b')
			printf("\a");
		if (c == 'c') {
			printf("Enter an integer\n");
			c = scanf("%d", &num);
			for (int i = 1; i <= num; ++i) 
			{
				printf("%d\n", i);
			}

		}

	}
	*/

	return 0;
}

char get_choice(void) 
{
	int user_input;

	printf("Enter the letter of your choice: \n");
	printf("a. avengers.\t b.beep.\nc.count \t q.quit\n");

	user_input = get_first_char();

	while ((user_input < 'a' || user_input > 'c') && user_input != 'q') 
	{
		printf("Please try agin.\n");
		user_input = get_first_char();
	}
	return user_input;
}

char get_first_char(void)
{
	int ch;
	ch = getchar();
	while (getchar() != '\n')
		continue;

	return ch;
}
int get_integer(void) {
	int input;
	char c;

	while (scanf("%d", &input) != 1) 
	{
		while ((c = getchar()) != '\n')
			putchar(c);
		printf(" is not an integer.\n Please try again\n");
	}
	
	return input;
	
}

void count(void) 
{
	int num;

	printf("Enter an integer\n");
	num = get_integer();
	for (int i = 1; i <= num; ++i)
	{
		printf("%d\n", i);
	}
}