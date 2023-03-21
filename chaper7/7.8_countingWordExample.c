//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <iso646.h>
#define STOP '.'

int main()
{
	int c;

	int n_chars = 0;
	int n_lines = 0;
	int n_words = 0;

	bool word_flag = false;
	bool line_flag = false;

	printf("Entier text : \n");

	while ((c = getchar()) != STOP)
	{
		if (!isspace(c))
			n_chars++;

		if (!isspace(c) && !line_flag) {
			n_lines++;
			line_flag = true;
		}

		if (c == '\n')
			line_flag = false;

		if (!isspace(c) && !word_flag) 
		{
			n_words++;
			word_flag = true;
		}

		if (isspace(c))
			word_flag = false;
	}
	
	/* 내가 짠 코드
	* int c;
	* int character_count, word_count = 1, line_count = 1;
	while ((ch = getchar()) != STOP) {
		//putchar(ch);

		if (ch == ' ' || ch == '\n')
		{
			if (ch == '\n')
				++line_count;
			++word_count;
		}
		else
			++character_count;
		
			
	}
	*/
	//putchar(ch);
	printf("\n");
	printf("Characters = %d, Words = %d, Lines = %d", n_chars, n_words, n_lines);

	return 0;
}