#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

char* custom_string_input(char* st, int n);

int main()
{
	/* Creating Space */

	//char* name = ""; // Error at RUN-TIME // char을 입력으로 받기 위해서는 배열을 사용해야 한다.
	////char name[128];
	//int result = scanf("%s", name);
	// scanf의 name 앞에 &가 안 붙는 이유는 배열 자체가 포인터와 비슷하게 작동하기 때문이다.

	/*
		scanf() vs gets()
		scanf() reads one word
		gets() reads one line and removes \n and \0
	*/

	//char words[STRLEN] = ""; // Warning without initialization
	//gets(words); // gets receves pointer. No idea when string end // 배열이 가지고 있는 첫 주소를 넣어준다. 즉 gets함수는 메모리 크기는 잘 모른다.
	//gets_s(words, sizeof(words)); // C11에서는 gets_s함수에 포인터 변수 주소와 크기를 함께 넣어줄 수 있다.
	//int result = scanf("%s", words);
	//printf("START\n");
	//printf("%s\n", words); // no \n at the end
	//puts(words); // puts() adds \n at end
	//puts("END.");

	// TODO: try char words[5];

	/* fgets() and fputs() */

	//char words[STRLEN] = "";
	//fgets(words, STRLEN, stdin); // does NOT remove \n

	// TODO: replace '\n' with '\0'
	//int i = 0;
	//while (words[i] != '\n' && words[i] != '\0')
	//	i++;
	//if (words[i] == '\n')
	//	words[i] = '\0';

	//fputs(words, stdout);
	//fputs("END", stdout);

	/* Small array */

	//char small_array[5];
	//puts("Enter long strings:");
	//printf("%p\n", small_array); // 00AFF6F8
	//printf("%p\n", fgets(small_array, 5, stdin)); // 00AFF6F8
	//fgets(small_array, 5, stdin); // 1234567890
	//fputs(small_array, stdout); // 1234

	/* Repeat short reading */ // 짧은 배열로도 반복문을 사용하여 buffer에 저장하다가 함께 출력하는 코드
	//char small_array[5];
	//puts("Enter long strings: ");
	//while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
	//	fputs(small_array, stdout);
		//puts(small_array); // What if we use puts()

	//char str1[6], str2[6];
	//int count = scanf("%5s %5s", str1, str2);
	//int count = scanf("%6s %6s", str1, str2); // run-time error
	//int count = scanf_s("%5s %5s", str1, 6, str2, 6);
	//printf("%s|%s \n", str1, str2);

	/* An example of custom input function */
	char word[11];
	puts(custom_string_input(word, 11));


	return 0;
}

char* custom_string_input(char* st, int n)
{
	char* ret_ptr;
	int i = 0;

	ret_ptr = fgets(st, n, stdin);
	if (ret_ptr)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n') // clear buffer
				continue;
	}

	return ret_ptr;
}