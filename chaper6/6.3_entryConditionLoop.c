//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
	while (expression) // expression이 0이면 수행하지 않고, 0이 아닌 값이면 수행한다.
		statement
	*/

	int i;

	//i = 1;
	//while (i < 5) // infinite loop
	//	printf("Hi\n"); // iteration: 계속 반복하는 것을 interation이라고 한다.

	//i = 1;
	//while (--i < 5) // wrong direction
	//	printf("Hi!\n");

	//i = 1; 
	//while (i < 5) // OK
	//{
	//	printf("i before = %d\n", i);
	//	i++;
	//	printf("i after = %d\n", i);
	//}

	//i = 10;
	//while (i++ < 5) // cannot enter
	//{
	//	printf("Hi\n");
	//}

	/* Common mistakes */

	//i = 0;
	//while (i < 3) 
	//	printf("%i\n", i);
	//	i++; //indenting: while문에 block이 없으면 다음 한 줄까지만 while문으로 실행된다.

	//i = 0;
	//while (i++ < 3); //null statement(while 문 뒤에 ;이 있어 다음 구문이 실행되지 않음)
	//printf("%i\n", i);

	//while (scanf("%d", &i) == 1) 
	//	;// null statement
	/* 이런 기능을 수행하는 프로그램을 만들 때는 이런 식으로 암호문처럼 코딩할 필요는 없다.
	암호문을 만드는 것보다 읽기 편리하고 의사를 명확하게 판단하고 의미를 직접적으로 파악할 수 있는 코드를 짜야 한다.
	실전에서는 이런 코드를 작성하는 건 권장하지 않는다.
	*/

	
	return 0;
}