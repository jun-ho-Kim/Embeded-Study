#include <iostream>
#include <stdio.h>
#define PAGES 732

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);
	
	
	/*
	int i;
	float x, y;
	x=0.;
	y=0.;
	
	for(i=0; i<10000;i++)
	{
		x=x+100000.;
		y+=100000.;
	}
	
	printf("%.6e\n", x/10000.);
	printf("%.15e\n", y/10000.);
	while(getchar());
	*/
	
	/*
	int res;
	char ch;
	
	while(1)
	{
		res = scanf("%c", &ch);
		if(res == -1) break;
		printf("%d ", ch);
	}
	
	
	*/
	return 0;
}
