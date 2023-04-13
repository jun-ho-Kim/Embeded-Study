#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct my_data {
	int a;
	char c;
	float arr[2];
};

int main()
{
	struct my_data d1 = { 1234, 'A', };

	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);					// 1234 A 320274429296
	printf("%f %f\n", d1.arr[0], d1.arr[1]);								// 1.100000 2.200000
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);	// 320274429296 320274429300 

	struct my_data d2 = d1; // 구조체의 값은 복사는 되지만 포인터 주소는 복사가 안된다.
	//d2.a = d1.a;
	//d2.c = d1.c;
	//d2.arr[0] = d1.arr[0];
	//d2.arr[1] = d1.arr[1];

	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);					// 1234 A 320274429344 
	printf("%f %f\n", d2.arr[0], d2.arr[1]);								// 1.100000 2.200000
	printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);	// 320274429344 320274429348



	return 0;
}