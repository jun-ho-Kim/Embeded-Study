#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);

int main()
{
	/*
		strlen(): returns length of the string
	*/

	// TODO: use debugger

	//char msg[] = "Just, ""do it!";
	//puts(msg); // Just, do it!
	//printf("Length %d\n", strlen(msg)); // Length 12
	//fit_str(msg, 4);
	//puts(msg); // Just
	//printf("Length %d\n", strlen(msg)); // Length 4 

	/*
		strcat() and strcat() : string concatenation
		concat: 문자열을 합쳐줌
	*/

	//char str1[100] = "First string";
	//char str2[] = "Second string";

	//strcat(str1, ", ");
	//strcat(str1, str2); 
	// First string, Second string 
	//strncat(str1, str2, 2); // First stringSe 
	//puts(str1);

	// TODO: implement my_strcat() function!

	/*
		strcmp() and strncmp() : compare strings (not characters)
	*/
	//두 문자열이 같으면 0을 리턴, 두 문자열이 다르면 앞 글자가 ASCII CODE가 작으면 -1, 크면 1
	//printf("%d\n", strcmp("A", "A")); // 0
	//printf("%d\n", strcmp("A", "B")); // -1
	//printf("%d\n", strcmp("B", "A")); // 1
	//printf("%d\n", strcmp("Hello", "Hello")); // 0
	//printf("%d\n", strcmp("Banana", "Bananas")); // -1
	//printf("%d\n", strcmp("Bananas", "Banana")); // 1
	//printf("%d\n", strncmp("Bananas", "Banana", 6)); // 0
	// TODO: implement strcmp!

	/*
		strcpy() and strncpy()
	*/

	//char dest[100] = ""; // make sure memoery is enough
	//char source[] = "Start programming!";
	//dest = source; //Error // 컴파일에서 에러가 발생. 값을 변경하려면 dest[i] = '' 이런 식으로 변경해야
	//dest = "Start something"; //Error
	//strcpy(dest, source); 
	//strcpy(dest, source, 5); // '\0 is NOT added'
	// strcpy 같은 경우에는 메모리 복사를 하는 경우가 생기기 때문에 \0을 추가해주지 않는다.
	//puts(dest); // Start programming!
	
	//strcpy(dest, source + 6);
	//strcpy(dest + 6, "coding!");
	//puts(dest); // progracoding!

	/*
		sprintf()
	*/

	//char str[100] = "";
	//int i = 123;
	//double d = 3.14;
	//sprintf(str, "%0.5d.png %f", i, d);
	//puts(str); // 00123.png 3.140000
	// 메모리 주소에 나열된 값들을 순서대로 출력해준다.

	/*
		There are more functions...
	*/

	printf("%s\n", strchr("Hello, World", 'W')); // World //strchr() 함수는 _Val에 입력된 값을 찾아서 그 값의 포인터를 리턴한다.
	
	printf("%s\n", strpbrk("Hello, World", "ABCDE")); // (null) // strpbrk() 함수는 *_Control에 나열된 값들을 찾아서 그 값의 포인터를 리턴해준다.
	printf("%s\n", strpbrk("Hello, World", "abced")); // ello, World

	printf("%s\n", strrchr("Hello, World", "Hello, World", 'l')); //ld //_Ch의 입력된 값의 뒷부분 을 리턴

	printf("%s\n", strstr("Hello, World", "wor")); // (null) // strstr()은 문자열끼리 비교해준다.
	printf("%s\n", strstr("Hello, World", "Wor")); // World 

	return 0;
}

void fit_str(char* str, unsigned int size)
{
	if (strlen(str) > size)
		str[size] = '\0';
}