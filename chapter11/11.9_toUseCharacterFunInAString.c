#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_LIMIT 1024

void ToUpper(char*);
int PunctCount(const char*);

int main()
{
	char line[NUM_LIMIT];
	char* new_line = NULL;
	fgets(line, NUM_LIMIT, stdin);
	new_line = strchr(line, '\n');
	if (new_line)
		new_line = '\0';

	ToUpper(line);
	puts(line);

	printf("%d\n", PunctCount(line));
	
	return 0;
}

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
		/*
		* 내가 짠 코드
		if (str[i] > 97 && str[i] < 122)
			*str[i] -= 32;
		i++;
		*/
	}
}

int PunctCount(const char* str)
{
	int i = 0;
	while (*str)
	{
		if (ispunct(*str))
			i++;
		str++;
	}
	//int i = 0;
	//while (str != '\n')
	//{
	//	str++;
	//	++i;

	//}
	return i;
}