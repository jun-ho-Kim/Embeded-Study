#include <stdio.h>

int main(void)
{
	char str[80] = "apple juice";
	char *ps = "banana";

	puts(str); // apple juice // apple joice 출력하고 줄 바꿈
	fputs(ps, stdout); // banana만 입력
	puts("milks"); // banana에 이어 milk 출력
	// bananamilks

	// puts 함수는 fputs와 달리 문자열을 출력한 후에 자동으로 줄을 바꿔주므로 편리하지만 줄을 바꾸고 싶을 때는 적합하지 ㅇ낳다.
	// fputs를 사용하면 banana에 이어서 바로 milk가 출력된다.

	return 0;
}