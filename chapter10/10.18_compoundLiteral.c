#include <stdio.h>

#define COLS 4

int sum1d(int arr[], int n);
int sum2d(int arr[][COLS], int row);

int main()
{
	int a = 1;
	3; // Literals are contants that aren`t aren`t symbolic
	3.14f;
	int b[2] = { 3,4 };
	(int[2]) { 3,4 }; // compound literal

	// int c[2] = (int[2]){ 3,4 }; // Error

	int arr1[2] = { 1,2 };
	int arr2[2][COLS] = { {1,2,3,4}, {5,6,7,8} };

	printf("%d\n", sum1d(arr1, 2));
	printf("%d\n", sum2d(arr2, 2));
	printf("\n");

	printf("%d\n", sum1d((int[2]) {1,2}, 2));
	printf("%d\n", sum2d((int[2][COLS]) { {1,2,3,4}, {5,6,7,8} }, 2));
	//배열을 리터럴처럼 함수에 넣을 수 있다.
	//이렇게 코드를 작성하는 것이 좋지는 않지만 하드코딩하는 경우에 유용한 경우가 있다.(변수를 따로 선언하지 않고 사용할 수 있어서 편하다)
	printf("\n");

	int* ptr1;
	int(*ptr2)[COLS];

	ptr1 = (int[2]){ 1,2 };
	ptr2 = (int[2][COLS]){ {1,2,3,4}, {5,6,7,8} };

	printf("%d\n", sum1d(ptr1, 2));
	printf("%d\n", sum2d(ptr2, 2));

	return 0;
}

int sum1d(int arr[], int n)
{
	int tot = 0;
	for (int i = 0; i < n; ++i)
		tot += arr[i];

	return tot;
}

int sum2d(int arr[][COLS], int rows)
{
	int tot = 0;
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < COLS; c++)
			tot += arr[r][c];

	return tot;
}