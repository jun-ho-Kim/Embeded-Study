#include <stdio.h>
#include <stdlib.h>

void print_month(int* mp);

void input_ary(double* pa, int size);
double find_max(double* pa, int size);


int main()
{
	
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30,31 };

	print_month(month);
	

	/*
	* // 예제 10.7
	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]);

	input_ary(ary, size);
	max = find_max(ary, size);
	printf("배열의 최대값 : %.1lf\n", max);
	*/
	int z = 4;

	return 0;
}

void print_month(int* mp)
{
	int i;
	for (i = 0; i < 12;i++)
	{
		printf("%5d", *(mp + i)); 
		if ((i+1) % 5 == 0)
			printf("\n");
	}
}

// 예제 10.7
void input_ary(double* pa, int size)
{
	int i;
	printf("%d개의 실수값 입력 : ", size);
	for (i = 0; i < size; i++)
	{
		scanf("%lf", pa + i);
	}
}
// 예제 10.7
double find_max(double* pa, int size)
{
	double max = pa[0];
	int i;
	for (i = 0; i < size; i++)
	{
		if (*pa > max)
			max = *(pa);
		pa++;
	}

	return max;
}