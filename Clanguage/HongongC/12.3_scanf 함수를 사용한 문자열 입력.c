#include <stdio.h>

int main(void)
{
	char str[80];

	printf("문자열 입력 :");
	scanf("%s", str); // apple jam
	printf("첫 번째 단어 : %s, p is %p\n", str, &str);	//첫 번째 단어 : apple, p is 0000003D3553F520
	


	scanf("%s", str);
	printf("버퍼에 남아있는 두 번째 단어 : %s, p is %p \n", str, &str); //버퍼에 남아있는 두 번째 단어 : jam, p is 0000003D3553F520

	//scanf 함수는 버퍼를 사용하므로 키보드로 입력한 문자열은 Enter를 누를 때 버퍼에 저장된다.
	//scanf 함수는 버퍼에서 문자열을 가져와 배열에 저장하는데 중간에 공백 문자, 탭 문자, 개행 문자가 있으면 그 이전까지만 저장한다.
	//물론 배열에 저장한 문자열의 끝에는 널 문자를 붙여서 문자열을 완성한다.
	//scanf 함수로 문자열을 입력할 때는 [배열의 크기 -1]까지 입력이 가능


	return 0;
}