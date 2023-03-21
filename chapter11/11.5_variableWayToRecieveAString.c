#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TEST "A string from #define."

void custom_put(const char* str); // Only two lines
int custom_put2(const char* str); // Add \n, return # of charaters

int main()
{
	/*
		puts(): add \n at the end
	*/

	//char str[60] = "String array initialized";
	//const char* ptr = "A pointer initialized";

	//puts("String without\\n"); //String without\n
	//puts("END"); // END
	//puts(TEST); // A string from #define.
	//puts(TEST + 5); // ing from #define.
	//puts(&str[3]); // ing array initialized 
	////puts(str[3]); // Error
	//puts(ptr +3); // ointer initialized

	/*
		string without \0
	*/

	//char str[] = { 'H', 'I', '!'}; // No \0 at then end.
	//puts(str); // VS warns you! // HI!儆儆絹???
	// 위와 같이 str 변수를 만들면 \0가 없다. 그래서 \0을 찾을 때까지 읽어온다.
	// 문자열을 초기화 할 때는 null character가 있어야 한다.

	/*
		puts() and fputs()
	*/

	// char line[100];
	//while (gets(line))
	//puts(line);

	//char line[100];
	//while (fgets(line, 100, stdin))
	//	fputs(line, stdout);

	/*
		printf()
	*/
	//char str[] = "Just do it, do it";
	//printf("%s\n", str);
	//puts(str);

	//char input[100] = "";
	//int ret = scanf("%10s", input); // Input : "Just do it, do it!\n" (Note %10s)
	//printf("%s\n", input); // Output : "Just" // scanf에 띄어쓰기 단위로 입력을 받는다.
	//ret = scanf("10%s", input); //Reads remaining buffer
	//printf("%s\n", input); //Output: "do"
	// scanf()의 장점은 여려개의 자료형이 있을 경우 입력받기 편하다.

	/*
		Custom function
	*/

	custom_put("Just ");
	custom_put2("Do it!");
	
	printf("%d\n", custom_put2("12345"));
	return 0;
}

void custom_put(const char* str)
{
	// 강의 정답 코드
	while (*str != '\0') // while(str)
		putchar(*str++);
	/* 
	* // 내가 짠 코드
	int i = 0;
	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
	*/
}

int custom_put2(const char* str)
{
	int i = 0;
	while (*str != '\0') {
		putchar(*str++);
		i++;
	}
	putchar("\n");

	return i;
	
}