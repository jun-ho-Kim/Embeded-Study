#include <stdio.h>


int main()
{
	int i, size = 0;

	int array[10] = { 3,4,4,5,6,1,2,6 };

	int his[256] = { 0, };

	printf("sizeof is %d\n", sizeof(array));

	size = sizeof(array) / sizeof(array[0]);

	for (i = 0; i < size; i++)
	{
		his[array[i]] ++;
	}

	for (i = 0; i < 256; i++)
	{
		printf("%d is ", i);
		//printf("hist %d is  %d\n", i, his[i]);
		for (int j = 0; j < his[i]; j++)
		{
			printf("=");
		}

		printf("\n");
	}

	
	int z = 1;


	return 0;
}