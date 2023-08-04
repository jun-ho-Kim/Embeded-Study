#include <stdio.h>

int main(void)
{
	int ch;

	while (1)
	{
		ch = getchar();
		printf("ch is EOF %d\n", ch);
		if (ch == EOF)
		{
			break;
		}
		putchar(ch);
	}

	return 0;
}