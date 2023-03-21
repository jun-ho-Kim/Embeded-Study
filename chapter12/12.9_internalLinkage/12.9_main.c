#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static int g_int = 123; //defining declaration

void fun();
void fun_second();
void fun_third();

int main()
{
	fun();			// g_inf in main() 123 0096A000
	fun_second();	// g_inf in fun_second() 133 0096A004
	fun_third();	// g_inf in fun_third() 143 0096A004

	return 0;
}

void fun()
{
	printf("g_inf in main() %d %p\n", g_int, &g_int);
	g_int += 10;
}