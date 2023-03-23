#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct my_data {
	int a;
	char c;
	float* arr;
};

int main()
{
	struct my_data d1 = { 1234, 'A', NULL };
	d1.arr = (float*)malloc(sizeof(float) * 2);
	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);					// 1234 A 3049693515440
	printf("%f %f\n", d1.arr[0], d1.arr[1]);								// 1.100000 2.200000
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);	// 3049693515440 3049693515444 

	struct my_data d2 = d1; // 포인터 주소로 동적할당으로 값을 복사하는 경우 포인터 주소값도 함께 복사된다.
	//d2.a = d1.a;
	//d2.c = d1.c;
	//d2.arr[0] = d1.arr[0];
	//d2.arr[1] = d1.arr[1];

	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);					// 1234 A 3049693515440
	printf("%f %f\n", d2.arr[0], d2.arr[1]);								// 1.100000 2.200000
	printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);	// 3049693515440 3049693515444 



	return 0;
}