#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
	ABCDEF ...
	Current position 0 and read -> A
	Current position 1 and read -> B
	...
*/

int main()
{
	int ch;
	long cur;

	FILE* fp = fopen("test.txt", "r");

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur); // ftell() = 0 

	fseek(fp, 2L, SEEK_SET);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur); // ftell() = 2
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);		// 67 C
	cur = ftell(fp);				// ftell()을 하면 오른쪽으로 한 칸 이동한다.
	printf("ftell() = %ld\n", cur);	// ftell() = 3

	fseek(fp, -2L, SEEK_CUR);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);	// ftell() = 1
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);		// 66 B 

	/* SEEK_END */
	fseek(fp, 0L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);		// -1

	fseek(fp, -1L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);		// 90 Z	

	fseek(fp, -2L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);		// 89 Y

	/* fsetpos(), fgetpos */

	fpos_t pt;
	pt = 10;
	fsetpos(fp, &pt);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);		// 75 K
	fgetpos(fp, &pt);
	printf("%lld\n", pt);			// 11
	return 0;
}