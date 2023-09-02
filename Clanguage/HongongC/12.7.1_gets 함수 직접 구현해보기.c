#include <stdio.h>

void my_gets(char* ps);

int main(void)
{
	int i = 0; 
	char str[20];
	char ch;

	my_gets(str);
	/*
	do
	{
		ch = getchar();
		str[i] = ch;
		i++;
	} while (ch != '\n');

	str[--i] == '\0';
	*/
	printf("%s", str);



	return 0;
}


void my_gets(char* ps)
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		*ps = ch;
		ps++;
	}
	*ps = '\0';
}