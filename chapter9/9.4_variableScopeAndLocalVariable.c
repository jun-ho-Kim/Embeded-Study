//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int int_max(int i, int j);

//int int_max(int i, int j)
//{
//	//a = 456;
//	int m;
//	m = i > j ? i : j;
//	return m;
//}

int main()
{
	int a;

	a = int_max(1, 2); 

	printf("%d\n", a); // 2
	printf("%p\n", &a); // 0000001F845FFB2C

	{	
		/*
		a = int_max(4, 5);

		printf("%d\n", a); // 5
		printf("%p\n", &a); // 0000001F845FFB2C
		*/

		int a;
		a = int_max(4, 5);
		printf("%d\n", a); // 5
		printf("%p\n", &a); // 0000001F845FFB28
		// int a가 새로운 지역 내에서 선언 되면 int a는 새로운 주소를 참조하고 지역 내에서만 사용된다.
		//상위 scope에 있는 int a는 영향을 받지 않는다.
	}

	printf("%d\n", a); // 5
	printf("%p\n", &a); // 0000001F845FFB2C

	return 0;
}

int int_max(int i, int j)
{
	int max;

	if (i < j)
		max = j;
	else
		max = i;
	// return i < j ? i : j;
	return max;
}