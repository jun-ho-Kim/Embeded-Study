#include <stdio.h>

int main(void)
{
	char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	gets_s(str, strlen(str)); // apple jam
	printf("입력한 문자열은 %s 입니다.", str); // 입력한 문자열은 apple jam 입니다.

	//scanf() 함수는 Space Bar, Tap, Enter를 입력해도 계속 입력을 기다린다.

	//gets()함수는 문자열의 일부로 입력하고 문자열 입력 없이 Enter만 눌러도 입력이 끝난다.
	//\n 대신에 \0을 저장

	int z = 4;

	return 0;
}