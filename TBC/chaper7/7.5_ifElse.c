//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int number;
	scanf("%d", &number);

	//if (number == 1)
	//	printf("One");
	//else if (number == 2)
	//	printf("Two");
	//else if (number == 3)
	//	printf("Three");

	//if (number == 1)
	//	printf("One");
	//else
	//	if(number ==2)
	//		printf("Two");
	//	else
	//		if(number ==3)
	//			printf("Three");
	// minimum 127 levels of nestings

	if(number > 5)
		if(number < 10)
			printf("Larger than 5 smaller than 10\n");
	else
		printf("Less than or equal to 5\n");
	//if 다음에 else를 사용할 때 들여쓰기를 하든 안 하든 바로 이전 if와 묶인다.
	return 0;
}