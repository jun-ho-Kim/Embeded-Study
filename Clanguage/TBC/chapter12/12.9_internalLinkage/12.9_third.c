﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int g_int;

void fun_third()
{
	g_int += 10;
	printf("g_inf in fun_third() %d %p\n", g_int, &g_int);
}