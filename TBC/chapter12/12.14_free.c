#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc(), free()

int main()
{
	printf("Dummy Output\n");
	
	{
		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));

		if(!ptr)
		{
			printf("Malloc() failed\n");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < n; ++i)
			ptr[i] = i + 1;
		
		free(ptr);
	}

	printf("Dummy Output\n");
	 
	return 0;
}