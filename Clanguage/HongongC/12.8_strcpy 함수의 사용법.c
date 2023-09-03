#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[80] = "strawberry";
	char str2[80] = "apple";
	char *ps1 = "banana";
	char *ps2 = str2;

	printf("최초 문자열 : %s\n", str1);
	strcpy(str1, str2);
	printf("바뀐 문자열: %s\n", str1);

	strcpy(str1, ps1);
	printf("바뀐 문자열: %s\n", str1);

	strcpy(str1, ps2);
	printf("바뀐 문자열: %s\n", str1);

	strcpy(str1, "banana");
	printf("바뀐 문자열: %s\n", str1);

	// strcpy 함수는 복사 받을 곳의 배열명을 첫 번째 인수로 주고 복사할 문자열을 두 번째 인수로 준다.
	// 문자열을 복사하는 방식은 문자열의 첫 번째 문자부터 널 문자가 나올 때까지 문자를 하나씩 배열에 옮겨 저장한다.
	// 따라서 복사할 문자열의 시작 위치를 알 수 있다면 어떤 것이든 두 번째 인수로 사용할 수 있다.

	// *첫 번째 인수는 char 배열이나 배열명을 저장한 포인터만 사용할 수 있다
	// *두 번째 인수는 문자열의 시작 위치를 알 수 있다면 어떤 것이든 사요할 수 있다.


	return 0;
}