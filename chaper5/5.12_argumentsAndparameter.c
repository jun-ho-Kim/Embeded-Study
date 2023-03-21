//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void draw(int n);

int main()
{
	int i = 5;
	char c = '#';
	float f = 7.1f;

	draw(i); // i는 arguments
	draw((int)c);
	draw((int)f);

	return 0;
}



void draw(int n) {
	//n은 parmeter
	while (n-- > 0)
		printf("*");
	printf("\n");
}

/* 내가 작성한 코드
void draw(int n)
{
	char star[100];
	int count = 0;
	while (count < n) 
	{
		star[count] = 42;
		++count;
	}
	printf("%s", star);
	printf("\n");
}
*/