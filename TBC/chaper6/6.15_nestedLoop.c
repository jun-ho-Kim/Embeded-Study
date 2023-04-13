//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 10
#define FIRST_CHAR 'A'
#define LAST_CHAR 'K'

int main()
{
	int r;
	int c;

	for (r = 0; r < 12; ++r) {
	//for (r = NUM_ROWS; r > 0; --r) {
		for(c = FIRST_CHAR + r; c < FIRST_CHAR + 12; ++c) {
		//for (c = FIRST_CHAR - r+ NUM_ROWS; c < FIRST_CHAR + NUM_ROWS; ++c) {
			printf("%c", c);
		}
		printf("\n");
	}

	//for (int r = 0; r <= NUM_ROWS; ++r) {
	//	for (int c = FIRST_CHAR; c <= FIRST_CHAR + r; ++c) {
	//		printf("%c ", c);
	//	}
	//	printf("\n");
	//}

	//for (int i = 0; i < 4; i++) {
	//	for (char j = 'A'; j <= 'K'; j++) {
	//		printf("%c", j);
	//	}
	//		printf("\n");
	//}
	
	return 0;
}