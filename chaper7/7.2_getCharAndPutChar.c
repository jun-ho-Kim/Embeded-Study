//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
		1. Introduce getchar(), putchar()
		2. Use while loop to process character sequences
		3. Filter a specific charater
		4. Convert number to asterisks(*)
		5. Lower character to Upper characters
	*/

	char ch;

	/* 
	// 1. Introduce getchar(), putchar()
	ch = getchar();
	putchar(ch);
	*/

	// 2 ~ 5
	//while (ch != '\n') {
	// 2. Use while loop to process character sequences
	while((ch = getchar()) !=  '\n') {

		// 3 ~ 5
		if (ch == 'F')
			ch = 'X';

		if (ch >= 65 && ch <= 90)
			ch += 32;
		else if (ch >= 97 && ch <= 122)
			ch -= 32;
		else if (ch >= 48 && ch <= 57)
			ch = '*';

		putchar(ch); //etchar()에서 입력을 받으면 while문을 돌면서 buffer라는 공간에 저장한다.
		//ch = getchar();
	}
	putchar(ch);

	return 0;
}