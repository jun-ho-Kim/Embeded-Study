#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
	Selection Sort Alogrithm
	//https://www.geeksforgeeks.org/selection-sort

	Youtube search "Selection Sort", "CS50"

	64 25 12 22 11 (min_idx = 0)
	   64          (min_idx = 0)
	   25          (min_idx = 1)
	      25       (min_idx = 1)
		  12       (min_idx = 2)
		     12    (min_idx = 2)
			    12 (min_idx = 2)
				11 (min_idx = 4)
	11 25 12 22 64 (swap arr[0] and arr[4])

	11 25 12 22 64 (min_idx = 1)
	      25       (min_idx = 1)
	      12       (min_idx = 2)
			 12    (min_idx = 2)
				12 (min_idx = 2)
	11 12 25 22 64 (swap arr[1] and arr[2])

	11 12 25 22 64 (min_idx = 2)
	...

*/

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main()
{
	int arr[] = { 64,25,12,22,11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, n);

	printArray(arr, n);
	
	return 0;
}

void selectionSort(int arr[], int n)
{
	int min_idx = 0;
	int i = 0;
	for (int i = 0; i < n; ++i)
	{
		min_idx = i;
		for (int j = i+1; j < n; ++j)
		{
			if (arr[min_idx] > arr[j])
				min_idx = j;
		}
		swap(&arr[i], &arr[min_idx]);
		//int tmp;
		//tmp = arr[i];
		//arr[i] = arr[min_idx];
		//arr[min_idx] = tmp;
	}
}

void swap(int* xp, int* yp)
{
	printf("*xp %d\n", *xp);
	printf("xp %d\n", xp);
	printf("&xp %d\n", &xp);
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;

	// 내가 짠 코드
	//int* tmp;
	//tmp = xp;
	//xp = yp;
	//yp = tmp;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%u ", arr[i]);
}