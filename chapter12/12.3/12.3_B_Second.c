#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//extern int el;
// extern int il;

void testLinkage()
{
	printf("DoSomething called\n");
	printf("%d\n", el);
	//printf("%d\n", il);

	el++;
}