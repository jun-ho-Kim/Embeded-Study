﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int g_int = 123; //defining declaration
static void fun_second(void);

void fun_second(void)
{
	g_int += 10;
	printf("g_inf in fun_second() %d %p\n", g_int, &g_int);

	return 0;
}