#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc(), free()

int main()
{
	int n = 10;

	int* ptr = NULL;

	//ptr = (int*)malloc(sizeof(int * n);
	ptr = (int*)calloc(n, sizeof(int)); // contigous allocation
	if (!ptr)
		exit(1);

	for (int i = 0; i < n; ++i)
		printf("%d ", ptr[i]); // 0 0 0 0 0 0 0 0 0 0
	printf("\n");

	/*
		realloc() KNK p. 422
		- doesn`t initialize the bytes added
		- returns NULL if can`t enlarge the memory bloc

	*/
	 
	for (int i = 0; i < n; ++i)
		ptr[i] = i + 1;

	n = 20;
	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int));
	//ptr = (int*)realloc(ptr, n * sizeof(int));

	printf("%p %p\n", ptr, ptr2); // 011E6008 011E6008 // in Debug x84
	// Debug x64로 compile 하는 경우 ptr과 ptr2 주소 값이 다르게 나옴
	// Debug x86로 compile 하는 경우 ptr과 ptr2 주소 값이 같게 나옴

	printf("%d\n", ptr[0]); // 1

	if (!ptr2)
		exit(1);
	else
		ptr = NULL;

	for (int i = 0; i < n; ++i)
		printf("%d ", ptr2[i]); // copies data
		// 1 2 3 4 5 6 7 8 9 10 -842150451 -842150451 -842150451 -842150451 -842150451 -842150451 -842150451 -842150451 -842150451
	printf("\n");

	free(ptr2);

	return 0;
}