#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {

	int a = 10;
	double b = 12.0;
	char c = "C";

	printf("int형 변수의 주소: %p\n", &a);		// int형 변수의 주소: 6487580
	printf("double형 변수의 주소: %p\n", &b);	// double형 변수의 주소: 6487568
	printf("char형 변수의 주소: %p\n", &c);		// char형 변수의 주소: 6487567


	printf("result");
	/*
	static int x[5] = { 100, 200, 300, 400, 500 };
	int i, *px;

	px = x;
	printf("px=x; px = %p\n", px);
	px = &x[0];
	printf("\n\ni px+i *(px=i), px[i] x[i] \n\n");
	for (i = 0; i < 4; i++)
		printf("%d %9d %9d %9d %9d \n\n", i, px + i, *(px + i), px[i], x[i]);

	printf("0 %d\n", *px);
	printf("0p %p\n", *px);
	printf("1d %d\n", *px + 1);
	printf("1 %p\n", *px + 1);
	printf("1d %d\n", *px + 1);
	printf("1 %p\n", *px + 1);
	printf("2 %d\n", *px++);
	printf("2p %p\n", *px++);
	*/
	/*
	printf("1 %d\n", *px++);
	printf("1p %p\n", *px++);
	printf("2 %d\n", (*px)++);
	printf("2p %p\n", (*px)++);
	*/

	return 0;
}