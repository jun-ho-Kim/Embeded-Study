//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <iso646.h>

int main()
{
	/*
		Logical operator
		&& : and
		|| : or
		!: not
	*/

	bool test1 = 3 > 2 || 5 > 6; // 3 > 2 or 5 > 6
	bool test2 = 3 > 2 && 5 > 6; // 3 > 2 and 5 > 6
	bool test3 = !(5 > 6); //not(5 > 6)
	// iso646 헤더를 사용하면 and, or, not 연산자를 사용할 수 있게 된다.
	// iso646 헤더에 사용하는 and, or, not를 사용하는 것은  c,c++ 스타일의 코딩이 아니다.

	printf("%d %d %d\n", test1, test2, test3);

	/*
		Precedence
		https://en.cppreference.com/w/c/language/operator_precedence
	*/

	//a > b&& b > c || b > d;
	//((a > b) && (b > c)) || (b > d);
	//위와 같이 복잡하게 논리 연산자를 작성하는 경우 ()를 사용하여 의도를 명확하게 하자.

	/*
		Short-circuit Evaluation // 단회로 계산

		- Logical expressions are evaluated from left to right;
		- && and || are sequence points
	*/

	/*
	int temp = (1 + 2) * (3 + 4); // Before : 21

	printf("Before : %d\n", temp);

	if (temp == 0 && (++temp == 1024)) { 
		// 단회로 계산에 의하여 temp == 0 이 false면 ++temp == 1024 식은 계산하지 않고 다음으로 넘어간다.
		//do nothing
	};

	printf("After : %d\n", temp); // After : 21
	*/

	/*
	int x = 1, y = 2;
	if (x++ > 0 && x + y == 4) // &&와 ||는 sequence point 이기 때문에 x++ 이후 &&를 만드면 x++ 연산이 실행이된다.
	//하지만 논리연산자 식에 증감연산자를 쓰는 것을 피하자. 헷갈리만한 상황은 피하자. 실수할 확률을 줄이자.
		printf("%d %d\n", x, y); // 2, 2
	*/

	/* Ranges */
	/*
	for (int i = 0; i < 100; ++i)
		if (i >= 10 && i <= 20)
			printf("%d", i);

	printf("\n");

	for(int i =0; i < 100; ++i)
		if(10 <= i <= 20) // Note; if(10 <= i) <= 20) -> 이 구문은 문법 에러가 아니라 문맥 에러이다.(0 or 1 <= 20)
			printf("%d ", i);
	*/


	for (char c = -128; c < 127; ++c)
		if (c >= 'a' && c <= 'z')
			printf("%c ", c);

	printf("\n");

	for (char c = 0; c < 127; ++c)
		if (islower(c))
			printf("%c ", c);

	return 0;
}