//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* promotions in assignmets */
	//promotions(승급): 작은 자료형에서 큰 자료형을 대입하는 것(은 문제가 생기지 않는다.)
	short s = 64;
	int i = s;
	float f = 3.14f;
	double d = f;

	/* demotion in assignments */
	d = 1.25;
	f = 1.25;
	//f = 1.123;
	// 1.25는 double이지만 1/2^(-2)이기 때문에 문제가 되지 않지만 1.123은 double일 때와 float일때가 값이 미묘하게 다르다.

	/* ranking of types in operations */
	//아래로 갈 수록 랭킹이 낮아지고 같은 라인이면 랭킹이 같다.
	// long double > double > float
	// unsigned long, long, long long 
	// unsigned long, long
	// unsigned, int
	// short int, unsigned short int
	// signed char, char, unsigned char
	// _Bool
	// Ref; Google 'Integer conversion rank'
	d = f + 1.234; // float + double 인경우 float를 double로 변환하여 계산한다.
	f = f + 1.234;// lvalue의 f가 float 타입이고 float + double은 double이기 때문에 값이 손실이 될 수 있다.	
	// 나중에 수치적으로 정밀한 프로그램을 작성할 경우 이런 경우가 필요하다.

	/* automatic promotion of function arguments */
	// 1. Functions without prototypes // 잘 쓰이지 않음
	// 2. Variadic function // printf()인 경우 인자가 변할 수 있는 경우

	/* casting operators */
	// 위에서는 자동으로 형변환을 해주고 형변환을 할 거라고 의도하고 프로그래밍을 작성하는 경우
	// 프로그래머의 의도를 파악하기 위해서 casting operators를 사용하여 표현을 해주는 것이 더 좋다. 
	//d = (double)3.14f
	//i = 1.6 + 1.7; // 3 //3.3에서 truncation
	//i = (int)1.6 + (int)1.7; // 2 // 1+1

	/* more example */
	char c; // 1byte
	f = i = c = 'A'; //65
	printf("%c %d %f\n", c, i, f);
	c = c + 2; // "C", 67
	i = f + 2 * c; //65.0f + 2 * 67
	printf("%c %d %f\n", c, i, f); // 199
	c = 1106; // demolition, 1106 = 0b1001010010, 0b01010010 = 1106 % 256 = 82 = 'R'
	//overflow in conversion from 'int' to 'char' changes value from '1106' to '82'
	printf("%c\n", c);
	c = 83.99;
	printf("%c\n", c); //"S" (83의 ASCII CODE)
}