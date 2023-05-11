#include <stdio.h>
#include <math.h>	// pow
#include <stdlib.h> // strlen()
#include <string.h> // exit()

// TODO: to_decimal 함수 만들기(이진수를 십진수로 바꾸는 함수)
unsigned char to_decimal(const char bi[]);

int main()
{
	printf("Binary (string) to Decimal conversion\n");

	printf("%d\n", to_decimal("00000110"));

	// Note: ^(caret) means power in math.
	// Hint: (int)pow(2, 3) == 8

	printf("%d\n", to_decimal("10010100"));

	return 0;
}
