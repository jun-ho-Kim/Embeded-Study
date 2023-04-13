//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int temp;
	temp = true ? 1024 : 7;
	printf("%d\n", temp);

	temp = false ? 1024 : 7;
	printf("%d\n", temp);

	int number;
	scanf("%d", &number);

	bool is_even = (number % 2) == 0 ? true : false;
	// 삼항 연산자의 ?는 우선순위가 낮다. 하지만 보기 편하기 위해 number % 2 ()를 붙여준다.

	//if (number % 2 == 0)
	//	is_even = true;
	//else
	//	is_even = false;

	printf("is_even: %s ", is_even == true ? "Even" : "Odd");

	return 0;
}