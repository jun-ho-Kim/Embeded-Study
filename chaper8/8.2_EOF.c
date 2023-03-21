//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main()
{
	int c;

	// getchar()는 int를 return 한다. 
	// EOF 상수는 -1을 리턴
	// getchar()에서 -1을 리턴하려면 ctrl+Z 를 사용
	// while ((c = getchar()) != EOF) // End Of File1
	// putchar(c);

	while (1)
	{
		c = getchar();
		printf("%d\n", c);
		if (c == EOF)
			break;
	}

	return 0;
}