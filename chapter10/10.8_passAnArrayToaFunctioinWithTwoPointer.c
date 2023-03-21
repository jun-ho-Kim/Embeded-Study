//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 두 개의 포인터로 배열을 함수에게 전달하는 방법
double average(double*, double*);

int main()
{
	double arr1[5] = { 10, 13, 12, 7, 8 };

	//포인터와 배열의 마지막 포인터주소를 전달해준다.
	printf("Avg = %f\n", average(arr1, arr1 + 5));

	return 0;
}

double average(double* start, double* end)
{
	int count = end - start;
	double avg = 0.0;

	while (start < end)
	{
		avg += *start++;
	}
	avg /= (double)count;

	return avg;
}