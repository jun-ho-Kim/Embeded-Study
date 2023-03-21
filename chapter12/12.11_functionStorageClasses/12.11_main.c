#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static int g_int = 123; //defining declaration

void fun();
void fun_second();

int main()
{
	fun();
	fun_second();

	return 0;
}

void fun()
{
	printf("g_inf in main() %d %p\n", g_int, &g_int);
	g_int += 10;
}

void fun_second(void)
{
	g_int += 10;
	printf("g_inf in fun_second() %d %p\n", g_int, &g_int);

	return 0;
}