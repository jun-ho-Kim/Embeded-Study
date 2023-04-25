#include <stdio.h>

int main()
{
	/* pointer Compatibility */
	//int n = 5;
	//double x;
	//x = n;
	//int* p1 = &n;
	//double* pd = &x;
	//pd = p1; // Warning // 형변환 에러(vs에서는 warning)
	//// 포인터를 형변환해서는 사용하지 않는 것이 좋다.

	//int* pt;
	//int(*pa)[3];
	//int ar1[2][3] = { 3, };
	//int ar2[3][2] = { 7, };
	//int** p2; //a pointer to a pointer

	//pt = &ar1[0][0]; // pointer-to-int

	////for (int i = 0; i < 6; ++i)
	////	//printf("%d ", pt[i]);
	////	printf("%d ", *(pt + i));

	//pt = ar1[0]; // pointer-to-int
	////pt = ar1; // Warning (Error)
	//pa = ar1; // Warning (Error) // 호환이 안됨

	//pa = ar1; // pointer-to-int[3]
	//pa = ar2; // Warning or error // pa는 길이가 3, ar는 길이가 2

	//p2 = &pt; // pointer-to-int
	//*p2 = ar2[0]; // pointer-to-int
	////p2 = ar2; //Warning (Error)
	////Notes
	//// - p2: pointer to pointer to int
	//// - ar2: a pointer to array-of-2-ints

	/* Pointer and const */
	//int x = 20;
	//const int y = 23;
	//int* p1 = &x;
	//const int* const p2 = &y;
	//// 포인터 왼쪽에 붙은 const는 값을 변경할 수 없다.
	//// 포인터 오른쪽에 붙은 const는 다른 포인터 변수에 할당이 안된다.

	//const int** pp2 = &p1;
	//// p1 = p2; // Warning (Error) // 포인터 변수 오른쪽에 const를 붙이면 할당이 안된다.

	////*p2 = 123; //Error
	////p2 = p1;

	//int x2 = 30;
	//int* p3 = &x2;
	//*pp2 = p3;
	//pp2 = &p1;

	/* C const and C++ const */

	//const int** pp2;
	//int* p1;
	//const int n = 13;
	//pp2 = &p1;
	//*pp2 = &n;
	//*p1 = 10;
	//printf("%u\n", *(*pp2));
	// 애초에 const로 명시 되었는데 다른 포인트 변수에 할당하는 행위는 해서는 안된다.
	
	//const int y;
	//const int* p2 = &y;
	//int* p1;
	//p1 = p2; // warning (error in cpp)
	// 애초에 const로 명시 되었는데 다른 포인트 변수에 할당하는 행위는 해서는 안된다.
	// C에서는 위 코드가 작동이 되지만 C++에서는 에러가 발생한다.

	return 0;
}