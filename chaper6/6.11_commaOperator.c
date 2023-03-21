//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	//for (int n = 1, nsqr = n * n; n < 10; n++, nsqr = n * n)
	//	printf("%d %dn", n, nsqr); //Note that commas in printf() are not comma operator. but separators

	//int i, j;
	//i = 1;
	//i++, j = i; // comma is a sequence point(왼쪽부터 먼저 실행된다.)

	//int x, y, z;
	//z = x = 1, y = 2; // =는 right to left, comma is left to right
	//printf("x=%d, y=%d, z=%d \n", x, y, z); // x=1, y=2, z=1
	//z = (x = 1), (y = 2);
	//printf("x=%d, y=%d, z=%d \n", x, y, z); // x=1, y=2, z=1
	//z = ((x = 1), (y = 2)); // 콤마 연산자는 가장 오른쪽에 있는 값이 전제 expression의 값이다.
	//printf("x=%d, y=%d, z=%d \n", x, y, z); // x=1, y=2, z=2

	//int my_money = 123,456; // 프로그래밍언어에서는 돈을 셀 때 ,를 해서는 안된다.
	//int my_money = (123, 456);
	//printf("%d\n", my_money); // 456

	return 0;
}