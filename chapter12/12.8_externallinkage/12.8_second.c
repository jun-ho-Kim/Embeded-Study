#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int g_int; // extern operator 변수를 다른 파일에서 초기화했으면 다른 곳에서는 초기화 할 수 없다.

void temp()
{
	g_int += 1000;
}

int fun_sec()
{
	temp();

	//extern int g_int;

	printf("g_inf in main() %d %p\n", g_int, &g_int);
	return 0;
}