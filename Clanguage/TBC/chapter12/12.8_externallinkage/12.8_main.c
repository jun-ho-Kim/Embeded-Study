#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	Static variable with external linkage
	- File scope, external linkage, static storage duration
	- External stoage class
	- External variable
*/

int g_int;
// int g_int = 7;
double g_arr[1000] = { 0.0 };
// static으로 전역변수로 사용하는 경우에는 초기화를 안 해주어도 컴파일에서 0으로 초기화를 해주지만 값을 초기화 해주는 것이 좋다.

int x = 5;				// ok, const expression
int y = 1 + 2;			// ok, const expression
size_t z = sizeof(int); // ok, sizeof is a constant expression
// int x2 = 2 * x;		// not ok, x is a variable

void fun()
{
	printf("g_inf in main() %d %p\n", g_int, &g_int);
	g_int += 10;
}

int main()
{
	/*
		defining declaration vs referencing declaration
		(referencing declaration: extern을 사용하여 명시)
	*/

	// extern int g_int;		// Optional
	// 전역변수를 함수 내 scope에서 사용할 경우에는 extern으로 가져와 사용할 수 있다.
	// extern을 사용하지 않으면 새로운 지역변수를 생성해 사용한다.
	
	// extern int g_int = 1024;	// Error in block scope

	// int g_int = 123;		// hides global g_int

	printf("g_inf in main() %d %p\n", g_int, &g_int); // g_inf in main() 0 00F5C098
	g_int += 1;
	 
	fun(); // g_inf in main() 1 00F5C098

	fun_sec(); // g_inf in main() 1011 00F5C098
	return 0;
}