//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* 함수의 프로토타입을 만들 경우
	double average(double *arr, int n);
	double average(double *, int n);
	double average(double arr[], int n);
	double average(double [], int n);
*/

double average(double arr[], int n)
{
	double avg = 0.0;
	printf("%p\n", arr);
	printf("%zd\n", sizeof(arr));

	for (int i = 0; i < n; ++i)
	{
		avg += arr[i];
	}
	avg /= (double)n;

	printf("Avg = %f\n", avg);

	return avg;
}

int main()
{
	double arr1[5] = { 10,13,12,7,8 };
	//double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
	double arr2[3] = { 1.8, -0.2, 6.3 };
	
	printf("Address = %p\n", arr1);
	printf("Size = %zd\n", sizeof(arr1));

	average(arr1, sizeof(arr1) / sizeof(arr1[0]));
	average(arr2, sizeof(arr2) / sizeof(arr2[0]));
	printf("Size = %zd\n", sizeof(arr1));
	return 0;
}