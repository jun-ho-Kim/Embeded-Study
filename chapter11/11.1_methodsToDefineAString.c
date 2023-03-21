#include <stdio.h>

#define MESSAGE "A symbolic string contant"
#define MAXLENGTH 81

int main()
{
	char words[MAXLENGTH] = "A string in an array";
	// 배열로 stringd을 만드는 방법
	// 배열로 만들 경우에는 char 타입의 배열이며, c에서는 char의 크기는 넉넉하게 잡아서 사용
	const char* pt1 = "A pointer to a string.";
	// 문자열에 대한 포인터를 선언


	puts("Puts() add a newline at the end"); // puts() add \n at the end
	// string을 리터럴로써 만드는 방법,
	puts(MESSAGE);
	puts(words);
	puts(pt1);
	words[3] = 'p';// OK
	puts(words);
	// pt1[8] = 'A'; // Error
	// 배열은 읽기/쓰기가 모두 가능한 메모리를 사용한다.
	// 문자열 리터럴은 프로그램의 일부이기 때문에 읽기 전용 메모리에 저장되어 있다.

	char greeting[50] = "Hello, and" " How are" " you" 
		" today!";
	//char greeting[50] = "Hello, and How are you today!";

	puts(greeting);

	printf("\" To be, or not to be\" Halmet said.\n");
	printf("%s, %p, %c\n", "we", "are", *"excellent programmers"); // we, 00C37B48, e

	const char m1[15] = "Love you!";

	for (int i = 0; i < 15; ++i)
		printf("%d ", (int)m1[i]); // Note the null characters
	printf("\n");
	
	const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0' };

	for (int i = 0; i < 15; ++i)
		printf("%d ", (int)m2[i]); // Note the null characters
	printf("\n");

	const char m3[] = "Love you, too!";

	int n = 8;
	char cookies[1] = { 'A', };
	char cakes[2+5] = { 'A', };
	char pies[2 * sizeof(long double) +1] = {'A', };
	// char crumbs[n]; //VLA

	char truth[10] = "Truths is ";

	if (truth == &truth[0]) puts("true!");
	if (*truth == 'T') puts("true!");
	if (*(truth+1) == truth[1]) puts("true!");
	if (truth[1] == 'r') puts("true!");

	return 0;
}