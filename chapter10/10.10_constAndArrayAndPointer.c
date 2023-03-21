#include <stdio.h>

int main()
{
	const double arr2[4] = { 1.0, 2.0, 3.0, 4.0 };
	//arr2[0] = 100.0;

	const double* const pd = arr2;
	// *pd = 3.0; // pd[0] = 3.0; arr2[0] = 3.0;
	// pd[2] = 1024.0; // arr2[2] = 1024.0;
	// 포인터에 const가 없으면 할당된 배열이 const라도 값 변경이 가능하다.

	printf("%f %f\n", pd[2], arr2[2]); // 3.000000 3.000000

	//pd++; // allowd
	// 포인터에 const를 지정해주어도 증감연산자는 허용이 된다.
	// 이럴 경우에 자료형 뒤에도 const를 적어주면 증감연산자도 허용이 안된다.

	printf("%f %f", pd[2], arr2[2]); // 4.000000 3.000000

	return 0;
}