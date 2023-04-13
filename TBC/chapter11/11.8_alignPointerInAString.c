#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void swap(int* xp, int* yp);
void printStringArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main()
{
	char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange"};
	int n = sizeof(arr) / sizeof(arr[0]);

	printStringArray(arr, n);

	selectionSort(arr, n);

	printStringArray(arr, n);
	
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
			if (strcmp(arr[min_idx], arr[j]) == 1)
				min_idx = j;
		}
		swap(&arr[i], &arr[min_idx]);
		//int tmp;
		//tmp = arr[i];
		//arr[i] = arr[min_idx];
		//arr[min_idx] = tmp;
	}
}

void swap(int** xp, int** yp)
{
	//printf("*xp %d\n", *xp);
	//printf("xp %d\n", xp);
	//printf("&xp %d\n", &xp);
	//printf("**xp %d\n", **xp);
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;

void printStringArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%s ", arr[i]);
}