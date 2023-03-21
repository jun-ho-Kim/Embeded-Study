//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12 // symbolic constant를 macro로써 선언을 하였다.

int main()
{
	/* Basic usage */
	int high[MONTHS] = { 2 ,5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	for (int i = 0; i < MONTHS; ++i)
		printf("%d ", high[i]);
	printf("\n");

	float avg = 0.0f;
	for (int i = 0; i < MONTHS; ++i)
		avg += high[i];
	printf("Average = %f\n", avg / (float)MONTHS);

	high[0] = 1;
	high[1] = 2;
	//high = { 1 ,2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // Not Working
	//high[12] = { 1 ,2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // Not Working

	/* Address */
	printf("%p %p %d\n", high, &high[0], high[0]); // high 변수의 주소 출력 값은 &high[0]이다.
	for (int i = 0; i < MONTHS; ++i)
		printf("%lld\n", (long long)&high[i]);
		// 포인트 자료형의 크기만큼 주소값이 늘어난다.
	printf("\n");

	/* Compiler doesn`t check whether indices are valid */
	// high[12] = 4; // Error
	// high[-1] = 123; // Error
	// 런타임에러 발생(c에서는 배열 크기의 초과된 값을 할당할 때 따로 에러처리 안하고 런타임에러로 반환해준다.)
	// 따로 에러를 발생해주지 않는 이유는 배열 값 초과 에러를 발생시키려면 효율성이 떨어지기 때문에 프로그래머가 주의하여 프로그램을 작성해야한다.
	
	/* const and array */
	//const int temp = 0;
	//temp = 4;
	//const int low[12] = { -7, -5, 1, 7, 13, 18, 22, 16, 9, 2, -5 };
	//low[0] = 123;

	/* When array is not initialized */
	int not_init[4]; // TODO: try static
	for (int i = 0; i < 4; ++i)
		printf("%d\n", not_init); // 초기화 하지 않는 경우 값이 쓰레기 값으로 지정

	/* Partially initailized */
	int insuff[4] = { 2,4 };
	for (int i = 0; i < 4; ++i)
		printf("%d\n", insuff[i]); // 값이 일부 값만 초기화한 경우 할당되지 않았으면 0으로 할당

	/* Overlly initialized */
	//int over[2] = { 2,4,8,16 }; // 컴파일에러 발생

	/* Omitting size */
	//const int power_of_twos[] = { 1,2,4,8,16,32,64 };
	//printf("%d\n", sizeof(power_of_twos));
	//printf("%d\n", sizeof(int));
	//printf("%d\n", sizeof(power_of_twos[0]));

	//for (int i = 0; i < sizeof power_of_twos / sizeof(power_of_twos[0]); ++i)
	//	printf("%d ", power_of_twos[i]);
	
	/* Specifying Array sizes */
	//int arr1[MONTHS]; // Sybolic integer constant
	//double arr2[123]; // Literal integer constant
	//float arr3[3 * 4 + 1];
	//float arr4[sizeof(int) + 1];
	//float arr5[-10]; // No
	//float arr6[0]; // No
	//float arr7[1.5]; // No
	//float arr8[(int)1.5]; // Yes

	//int n = 8;
	//float arr9[n]; // Variable-Length Array is optional from C11

	return 0;
}