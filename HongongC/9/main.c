#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	/*
	// 9.1
	int a;
	double b;
	char c;
	
	printf("int�� ������ �ּ�: %u\n", &a);		// int�� ������ �ּ�: 6487580
	printf("double�� ������ �ּ�: %u\n", &b);	// double�� ������ �ּ�: 6487568
	printf("char�� ������ �ּ�: %u\n", &c);		// char�� ������ �ּ�: 6487567
	*/
	
	/*
	// 9.2
	int a;
	int *pa;
	
	pa = &a;
	*pa = 10;
	
	printf("�����ͷ� a �� ��� : %d\n", *pa);
	printf("���������� a �� ��� : %d\n", a);
	*/
	
	/*
	//���� 9.3
	int a = 10, b = 15, total;
	double avg;
	int *pa, *pb;
	int *pt = &total;
	double *pg = &avg;
	
	pa = &a;
	pb = &b;
	
	*pt = *pa + *pb;
	*pg = *pt / 2.0;
	printf("�� ������ �� : %d %d\n", *pa, *pb);
	printf("�� ������ �� : %d\n", *pt);
	printf("�� ������ ��� : %.1f\n", *pg);
	
	printf("%u %u", &a, *pa);
	*/
	
	/*
	//���� 9.4
	int a = 10, b = 20;
	const int *pa = &a;
	printf("���� a �� : %d\n", *pa);
	pa = &b;
	printf("���� b �� : %d\n", *pa);
	pa = &a;
	//*pa = 30;
	printf("���� a �� : %d\n", *pa);
	*/
	
	/* 
	// ���� 9.5
	char ch;
	int in;
	double db;
	
	char *pc = &ch;
	int *pi = &in;
	double *pd = &db;
	
	printf("char�� ������ �ּ� : %d\n", &ch);
	
	printf("char�� ������ �ּ� ũ�� : %d\n", sizeof(&ch));
	printf("int�� ������ �ּ� ũ�� : %d\n", sizeof(&in));
	printf("double�� ������ �ּ� ũ�� : %d\n", sizeof(&db));
	
	printf("char * �������� ũ�� : %d\n", sizeof(pc));
	printf("int * �������� ũ�� : %d\n", sizeof(pi));
	printf("double * �������� ũ�� : %d\n", sizeof(pd));
	
	printf("char * �����Ͱ� ����Ű�� ������ ũ�� : %d\n", sizeof(*pc));
	printf("int * �����Ͱ� ����Ű�� ������ ũ�� : %d\n", sizeof(*pi));
	printf("double * �����Ͱ� ����Ű�� ������ ũ�� : %d\n", sizeof(*pd));
	*/
	
	/*
	//���� 9.6 
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
