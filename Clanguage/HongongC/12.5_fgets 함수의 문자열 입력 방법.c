#include <stdio.h>

int main(void)
{
	char str[80];

	printf("공백이 포함된 문자열 입력 :");

	fgets(str, sizeof(str), stdin);	//test
	printf("str size of is %d\n", strlen(str));	// str size of is 5

	str[strlen(str) - 1] = '\0';
	printf("str size2 of is %d\n", strlen(str));	// str size2 of is 4

	//fgets()는 문자 끝에 \n\0을 추가한다.
	//gets()함수는 \n만 추가
	//fgets()함수 끝에 \n을 없애주고 싶으면 str[strlen(str) - 1] = '\0'; 코드를 추가하자.

	return 0;
}