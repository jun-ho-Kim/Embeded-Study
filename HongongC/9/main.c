#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	/*
	// 9.1
	int a;
	double b;
	char c;
	
	printf("int형 변수의 주소: %u\n", &a);		// int형 변수의 주소: 6487580
	printf("double형 변수의 주소: %u\n", &b);	// double형 변수의 주소: 6487568
	printf("char형 변수의 주소: %u\n", &c);		// char형 변수의 주소: 6487567
	*/
	
	/*
	// 9.2
	int a;
	int *pa;
	
	pa = &a;
	*pa = 10;
	
	printf("포인터로 a 값 출력 : %d\n", *pa);
	printf("변수명으로 a 값 출력 : %d\n", a);
	*/
	
	/*
	//예제 9.3
	int a = 10, b = 15, total;
	double avg;
	int *pa, *pb;
	int *pt = &total;
	double *pg = &avg;
	
	pa = &a;
	pb = &b;
	
	*pt = *pa + *pb;
	*pg = *pt / 2.0;
	printf("두 정수의 값 : %d %d\n", *pa, *pb);
	printf("두 정수의 합 : %d\n", *pt);
	printf("두 정수의 평균 : %.1f\n", *pg);
	
	printf("%u %u", &a, *pa);
	*/
	
	/*
	//예제 9.4
	int a = 10, b = 20;
	const int *pa = &a;
	printf("변수 a 값 : %d\n", *pa);
	pa = &b;
	printf("변수 b 값 : %d\n", *pa);
	pa = &a;
	//*pa = 30;
	printf("변수 a 값 : %d\n", *pa);
	*/
	
	/* 
	// 예제 9.5
	char ch;
	int in;
	double db;
	
	char *pc = &ch;
	int *pi = &in;
	double *pd = &db;
	
	printf("char형 변수의 주소 : %d\n", &ch);
	
	printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
	printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
	printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));
	
	printf("char * 포인터의 크기 : %d\n", sizeof(pc));
	printf("int * 포인터의 크기 : %d\n", sizeof(pi));
	printf("double * 포인터의 크기 : %d\n", sizeof(pd));
	
	printf("char * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
	printf("int * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
	printf("double * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));
	*/
	
	/*
	//예제 9.6 
	int a = 10;
	int *p = &a;
	double *pd;
	
	pd = p;
	printf("%lf\n", pd);
	
	double a = 3.4;
	double *pd = &a;
	int *pi;
	pi = (int *)pd;
	printf("%u\n", pi);
	*/
	
	
	/*
	*/
	
	
	
	
	return 0;
}
