//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* if else */
	int size = 15, cost;

	if (size < 10)
		goto a;
	goto b;

a: cost = 50 * size;
b: cost = 100 * size;

	if (size < 10)
		cost = 50 * size;
	cost = 100 * size;

	/* loop */
	char c;

read: c = getchar();
	putchar(c);
	if (c == '.') goto quit;
	goto read;
quit:

	// 위 goto문 대신 실무에서는 아래와 같이 사용한다.
	while (1)
	{
		c = getchar(c);
		putchar(c);
		if (c == '.') break;
	}

	return 0;
}