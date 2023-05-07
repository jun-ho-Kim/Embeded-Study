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
	//int count = scanf("%5s %5s", str1, str2); // 5글자씩 받음
	//int count = scanf("%6s %6s", str1, str2); // run-time error // null charater를 제외하고 5글자를 입력 받아야함
	//int count = scanf_s("%5s %5s", str1, 6, str2, 6); // 문제 없이 사용 가능
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

/*
- scanf로 string 배열을 입력 받을 때 인자에 &를 안 붙여도 됨
- 입력을 받기 위해서 입력 받은 데이터를 저장할 공간을 미리 확보를 하고 그 공간에 입력을 받아야만 올바르게 입력 받고 사용할 수 있다.

scanf에서는 한 단어만 읽을 수 밖에 없는데 gets는 한 줄을 한 번에 읽을 수 있다.
ㄴ gets는 enter를 입력받는 순간 buffer에 있는 내용을 gets라는 함수가 읽어들이는데 \n를 제거하고 \0을 추가해준다.

gets - 포인터 이름을 인자로 넣어준다.
gets - 시작 지점만 알고 끝 지점을 알지 못한다.

gets 할당해준 문자열 크기보다 입력해준 크기가 크면 런타임 에러 발생
ㄴ 이 문제를 해결하기 위해 fgets fputs함수를 사용해보자.

fgets 함수는 \n 를 제거해주지 않는다.
파일 입출력해에서는 좋은 성질이다. 하지면 표준 입출력해서는 불편할 수 있다.
- fputs도 \n을 추가해주지 않는다.

- fgets함수는 지정된 크기보다 크게 지정해도 런타임에러가 발생하지 않고 지정된 크기만큼 입력값을 받아서 출력한다.
ㄴ 정상적으로 입력받았으면 입력받은 포인터를 반환해주고 문제가 생기는 경우(EOF을 만난 경우 - Null Character를 리턴 받는다.)


*/