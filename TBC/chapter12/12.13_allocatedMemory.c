#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc(), free()


int main()
{
	float x;
	char str[] = "Dancing with a Star";

	int arr[100];

	/*
		malloc() returns a void type pointer
		void * : generic pointer

		free() deallocates the memory
	*/

	double* ptr = NULL;

	ptr = (double*)malloc(30 * sizeof(double)); // 형 변환을 하여 배열처럼 사용할 수 있다. 대부분 배열처럼 사용한다.
	// 남은 메모리 중에 인자 크기만큼 Heap 공간을 배정해준다.
	// 동적할당 받은 변수와 포인터와 동일시 하면 안된다. 동적할당 받은 변수는 주소를 받은 쪽지이다.


	if (ptr == NULL) // 동적 할당이 NULL로 오는 경우 보통 아래와 같이 예외처리한다.
		// 메모리를 너무 큰 공간을 요청해서 할당할 수 없는 경우 동적 할당 에러가 발생한다.
		// 운영체제가 연속된 공간을 줄 수 없는 경우
	{
		puts("Memory allcation failed.");

		/*
			exit(EXIT_FAILURE) is similar to return 1 IN main().
			exit(EXIT_SUCCESS) is similar to return 0 IN main().
		*/

		exit(EXIT_FAILURE);
	}

	printf("Before free %p\n", ptr);	// Before free 0119B430 

	free(ptr); // no action occurs when ptr is NULL
	// 반납을 OS에 해줘서 다른 용도로 메모리를 사용할 수 있게 해주어야 한다.

	printf("After free %p\n", ptr);		// After free 0119B430 
	// 동적 할당 메모리를 반납(free)해도 ptr 변수는 메모리 주소 쪽지이기 때문에 메모리는 반납되어도 쪽지에는 주소가 남아있다.
	
	ptr = NULL; // optional;

	/* Dynamically Allocated Array */

	int n = 5;
	ptr = (double*)malloc(n * sizeof(double));

	if (ptr != NULL)
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%f \n", ptr[i]);
			/*
			-6277438562204192487878988888393020692503707483087375482269988814848.000000
			-6277438562204192487878988888393020692503707483087375482269988814848.000000
			-6277438562204192487878988888393020692503707483087375482269988814848.000000
			-6277438562204192487878988888393020692503707483087375482269988814848.000000
			-6277438562204192487878988888393020692503707483087375482269988814848.000000
			*/
			// 메모리를 할당만 받고 값을 초기화해주지 않았기 때문에 쓰레기 값이 들어있다.
			// 즉 malloc 함수는 0으로 초기화를 해주지 않는다.
		}
		printf("\n");

		for (int i = 0; i < n; ++i)
			*(ptr + i) = (double)i;

		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]); // 0.000000 1.000000 2.000000 3.000000 4.000000
		printf("\n");
	}
		free(ptr);
		ptr = NULL;

		/*
			Comparision to VLA

			VLA
			- not supported by VS compilers.
			- automatic duration, connot be resized
			- limited by stack size (when compiler places VLA in stack segment)
		*/
	
	 
	return 0;
}