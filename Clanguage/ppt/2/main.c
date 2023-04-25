#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);
	
	printf("*%1.2d*\n", PAGES);
	
	char op;
	int p1 = 0, p2 = 0, p3 = 1; //초기화 //C언어 초기화
	float pf = 0.0;
	
	printf("Input caculation data?\n");
	scanf("%d %c %d", &p1, &op, &p2);
	
	switch(op)
	{
		case '+': { p3 = p1 + p2; break; } 
		case '-': { p3 = p1 - p2; break; }
		case '*': {	p3 = p1 * p2; break; }
		case '/': { pf = (float)p1 / p2; printf("입력하신 데이터는 %d %c %d %f입니다.\n", p1, op, p2, pf);  break;}
		//캐스트 연산자
		case '%': { p3 = p1 % p2; break; }
		case '^': { 
			//int i;
			for(int i = 0; i<p2; i++)
			{
				p3*=p1;
			}	  
		}
		default: printf("지원되지 않는 연산자입니다.\n");
	}
	
	if(op != '/') printf("입력하신 데이터는 %d %c %d %d입니다.\n", p1, op, p2, p3); 
	
	printf("p3 is %d\n", p3);
	
	/*
	printf("%p1\n", p1);
	printf("%p2\n", op);
	printf("%p2\n", p2);
	*/
	return 0;
}
