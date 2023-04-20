#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(int *, int *);

int main(int argc, char *argv[]) {
	
	int a = 10, b = 20;
	swap(&a, &b);
	
	printf("main %d\n", a);
	printf("main %p\n", &a);
	
	printf("a= %d, b=%d", a, b);
	
	
	/*
	// 예제 8.1 
	int ary[5];
	
	ary[0] = 10;
	ary[1] = 20;
	ary[2] = ary[0] + ary[1];
	scanf("%d", &ary[3]);
	
	printf("%d\n", ary[2]);
	printf("%d\n", ary[3]);	
	printf("%d\n", ary[4]);
	*/
	
	/*
	// 예제 8.2 
	int score[5];
	int i;
	float avg;
	int total = 0;
	
	for(i=0; i<5; i++)
	{
		scanf("%d", &score[i]);
	}
	
	for(i=0;i<5; i++)
	{
		total += score[i];
	}
	
	avg = total / 5.0;
	
	for(i=0; i<5; i++)
	{
		printf("%5d ", score[i]);
	}
	
	printf("평균 : %.1lf\n", avg);
	*/
	/*
	int score[MAX];
	int i;
	int total = 0;
	double avg;
	int count;
	
	count = sizeof(score) / sizeof(score[0]);
	
	for(i=0;i<count; i++)
	{
		scanf("%d", &score[i]);
	}
		for(i=0;i<5; i++)
	{
		total += score[i];
	}
	
	avg = total / 5.0;
	
	for(i=0; i<5; i++)
	{
		printf("%5d ", score[i]);
	}
	
	printf("평균 : %.1lf\n", avg);
	*/
	
	/*
	// 예제 8. 
	char str1[80] = "cat";
	char str2[80];
	
	// str1 = "tiget" // Error
	strcpy(str1, "tiger");
	strcpy(str2, str1);
	printf("%s %s\n", str1, str2);
	*/
	
	/*
	//예제8.7 
	char str[5];
	str[1] = 'O' ;
	str[1] = 'K' ;
	printf("%s\n", str);
	*/
	
	/*
	//9.1
	int a;
	double b;
	char c;
	
	printf("int형 변수의 주소 : %u\n", &a);
	printf("double형 변수의 주소 : %u\n", &b);
	printf("char형 변수의 주소 : %u\n", &c);
	*/
	/*
	int a;
	int *pa; //a = pa;
	*/
	
	/*
	*/
	return 0;
}

void swap(int *a, int *b)
{
	printf("a %d\n", a);
	printf("a %p\n", a);
	printf("b %d\n", b);
	printf("b %p\n", b);
	
	int temp;
	temp = a;
	a = b;
	b = temp;
	
	printf("after a %d\n", a);
	printf("after a %p\n", a);
	printf("after a %d\n", *a);
}
