#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include "12.18_constants.h" // malloc(), free()

int main()
{
	/*
		Qualified types
		const, volatile, restrict, _Atomic
	*/

	/*
		const
	*/

	// C99 ideompotent
	const const const int n = 6; // const int n = 6;

	typedef const int zip;
	const zip q = 8; // const const int zip

	// const int i; // NOT initialized!
	// i = 12; // Error
	// printf("%d\n", i) //Error

	const int arr[] = { 1, 2, 3 };

	float f1 = 3.14f, f2 = 1.2f;

	const float* pf1 = &f1;
	//*pf1 = 5.0f; // Error
	pf1 = &f2; // Allowd

	float* const pf2 = &f1;

	*pf2 = 6.0f;
	//pf2 = &f2; // Error

	const float* const pf3 = &f1;
	//*pf3 = 7.0f; //Error
	//pf3 = &pf2; //Error

	/*
		Gloabal constants
	*/

	double area_circle = PI * 2.0f * 2.0f;

	/*
		volatile
		- Do not optimized
		- (ex: hardward clock)
		volatile는 컴파일러가 모르는 상황에서 값이 바뀔 수 있다라는 것을 선언해주는 것이다.
		결과적으로 컴파일러에게 volatile가 선언된 변수를 최적화 하지 말라고 선언해주는 것이다.
		하드웨어를 다루거나 로봇이나 임베디드 프로그래밍할 때 많이 사용할 수 있다.
	*/

	volatile int vi = 1;
	volatile int* pvi = &vi;

	// ...
	int it = vi;

	/*
		restrict (__restrict in VS)
		- sole intial means of accessing a data object
		- compiler can`t check this rerestriction
	*/

	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* par = ar;

	int* __restrict restart = (int*)malloc(10 * sizeof(int));
	if (!restart) exit(1);

	ar[0] += 3;
	par[0] += 5;

	restart[0] += 3;
	restart[0] += 5;
	// restart[0] += 8; // Equalivalent

	// __restrict을 사용하면 컴파일러가 최적화를 해준다.

	free(restart);

	return 0;
}