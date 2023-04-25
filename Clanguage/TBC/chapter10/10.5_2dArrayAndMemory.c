//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[2][3] = { {1,2,3}, {4,5,6} };
	//int arr[2][3] = {1,2,3, 4,5,6};
	//int arr[2][3] = {1,2} // insufficient initializer

	printf("%d\n\n", arr[1][1]);

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
			printf("%d ", arr[j][i]);
		// 2차원 배열을 사용할 때는 i를 loop문 안쪽으로 넣는다. 메모리가 저장되어 있는 순서가 행순서로 저장이 되기 때문이다.
	}

	printf("\n");

	//Note: inner loop uses i. why?

	int* ptr = &arr[0][0];
	for (int k = 0; k < 6; k++)
		printf("%d ", ptr[k]);
	printf("\n\n");

	printf("%zd %zd\n", sizeof(arr), sizeof(arr[0])); // 24 12
	//arr[0]의 크기는 첫 번째 행의 크기가 나온다.
	printf("\n");

	/* 3D array */
	//int arr_3d[2][3][4] = {
	//	{
	//		{000, 001, 002, 003},
	//		{010, 011, 012, 013},
	//		{020, 021, 022, 023},
	//								},
	//	{
	//		{100, 101, 102, 103},
	//		{110, 111, 112, 113},
	//		{120, 121, 122, 123},
	//								}
	//};

	//for (int k = 0; k < 2; ++k)
	//{
	//	for (int j = 0; j < 3; ++j)
	//	{
	//		for (int i = 0; i < 4; ++i)
	//			printf("%d ", arr_3d[k][j][i]);
	//		printf("\n");
	//	}
	//	printf("\n");
	//}

	return 0;
}