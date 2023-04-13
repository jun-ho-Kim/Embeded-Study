#include <stdio.h>

int main()
{
	int arr[5] = { 100, 200, 300, 400, 500 };
	int* ptr1, * ptr2, * ptr3;

	ptr1 = arr; // Assignment
	// 배열은 자체가 주소처럼 작동하기 때문에 바로 Assignment할 수 있다.
	// ptr1 = &i // 일반적인 변수라면 addressof(&)로 주소값을 가져와야 한다.
	printf("%p\n", arr);
	printf("%p %d %p\n", ptr1, *ptr1, &ptr1);// &ptr1: 포인터 변수의 주소를 가져온다.(포인터도 변수다)

	ptr2 = &arr[2]; // Address-of operator &
	printf("%p %d %p\n", ptr2, *ptr2, &ptr2);

	ptr3 = ptr1 + 4; // Adding an integer from a pointer
	// 포인터 자료형 크기 * 4 만큼 더해줌
	printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

	// Differencing
	printf("%td\n", ptr3 - ptr1); // Note: t is for pointer difference

	ptr3 = ptr1 - 4; // Substracing an integer from a pointer

	printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

	ptr1++;
	ptr1--;
	--ptr1;
	++ptr1;

	if (ptr1 == ptr3)
		printf("Same\n");
	else
		printf("Difference\n");

	double d = 3.14;
	double* ptr_d = &d;

	if (ptr1 == ptr_d) // warning C4133 '==' incompatible types - from 'double' 
		//타입이 같도록 해주어야
		printf("Same\n");
	else
		printf("Difference\n");

	return 0;
}