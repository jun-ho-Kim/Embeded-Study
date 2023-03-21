//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
	int a = 0;
	a++; // a = a + 1 or a += 1;
	printf("%d\n", a);

	++a; // a = a + 1 or a += 1;
	printf("%d\n", a);
	*/
	/*
	double b = 0;
	b++;
	printf("%f\n", b);

	++b;
	printf("%f\n", b);
	*/
	/*
	int count = 0;
	while (count < 10) // ++count or count++
	{
		printf("%d ", ++count);  // ++count or count++
		//printf("%d ", ++count); // 1 2 3 4 5 6 7 8 9 10
		//printf("%d ", count++); // 0 1 2 3 4 5 6 7 8 9
		// ++count은 그 자리에서 count += 1
		// count++은 다음 변수 선언 때 count += 1

		count;
	}
	*/
	/*
	int i = 1, j = 1;
	int i_post, pre_j;

	i_post = i++;
	pre_j = ++j;

	printf("%d %d\n", i, j); // 2, 2
	printf("%d %d\n", i_post, pre_j);// 1, 2
	*/
	/*
	int i = 3;
	int l = 2 * --i; // 연산자 우선순위는 단일 연산자 그 다음 곱셉
	printf("%d %d\n", i, l); // 2, 4

	i = 1;
	l = 2 * i--;
	printf("%d %d\n", i, l); // 0, 2
	*/


	/* very high precedence */
	//int x, y, z;
	//x = 3; y = 4;
	//z = (x + y++) * 5;
	//printf("%d %d %d", x, y, z); // 3, 5, 35 

	/* ++ and -- affect modifiable lvalues */
	/*
	// 증감 연산자는 수정 가능한 lvalue에만 사용이 가능
	int x = 1, y = 1, z;
	z = x * y++;
	// z = (x * y)++; //error: (x * y)는 lvalue가 아니다(메모리에 저장되어 있는 값이 아니다.)
	//z = 3++; //error: 3 또한 lvalue가 아니다. 그래서 에러가 발생한다.
	*/


	/* Bad practices */
	// 너무 복잡하게 사용하는 것은 좋지 않다. 명확할 때만 사용하자.
	//int n = 1;
	//printf("%d %d", n, n * n++); // 이런 경우 시스템마다 결과가 다르게 나타날 수 있다.
	//int x = n / 2 + 5 * (1 + n++); // 코드를 구분하여 나누어 주는 것이 좋다.
	//int y = n++ + n++; // 의도를 파악하기 힘들다.
}