//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char c;
	while ((c = getchar()) != '.')
	{
		printf("You love ");

		switch (c)
		{
		case 'a':
		case 'A':
			printf("apple");
			break;
		case 'b':
		case 'B':
			printf("baseball");
			break;
		case 'c':
		case 'C':
			printf("cake");
			break;
		default:
			printf("nothing");
		}

		printf("\n");

		//첫 글자를 제외하면 나머지 입력은 continue 하겠다는 로직(첫 글자를 제외하고는 다 패스)
		while (getchar() != '\n')
			continue;
	}
}