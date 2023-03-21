#include <stdio.h>
#include <stdlib.h> // malloc

void test_function()
{
	int j;
	printf("Stack high \t%llu\n", (unsigned long long) & j);
}

int main()
{
	/* Array Versus Pointer */
	const char* pt2 = "I am a string!.";
	const char* pt3 = "I am a string!.";
	const char* pt4 = "I am a string!!!!!!!."; // <- different
	const char ar1[] = "I am a string!.";
	const char ar2[] = "I am a string!.";
	const char ar3[] = "I am a string!!."; // <- different

	printf("rodata low \t%llu %llu %llu %llu\n",
		(unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4,
		(unsigned long long)"I am a string!.");
	// 컴파일러에서 리터럴이 동일할 때 한 번만 저장한다. 그래서 포인터에 리터럴로 저장하면 수정이 안되다.

	printf("stack hi \t%llu %llu %llu\n",
		(unsigned long long)ar1, (unsigned long long)ar2, (unsigned long long)ar3);
	// 배열 자체가 메모리를 각각 가지고 있기 때문에 같은 값이라도 주소가 다르다.

	/* Memory address check */

	/* Local variables */

	printf("Stack high \t%llu %llu %llu\n",
		(unsigned long long) & pt2, (unsigned long long) & pt3, (unsigned long long) & pt4);

	int i;
	printf("Stack high \t%llu\n", (unsigned long long) &i);

	/* Local variable in a function */
	test_function();

	/* Dynamic allocation */ // 나중에 동적할당 할 때 할 내용인데 Heap이 어디에 저장되는지 확인해보자.
	char* p5 = (char*)malloc(sizeof(char) * 100);
	printf("Heap middle \t%llu\n", (unsigned long long)p5);

	char* p6 = (char*)malloc(sizeof(char) * 100);
	printf("Heap middle \t%llu\n", (unsigned long long)p6);

	/* Array Versus Pointer (continued) */

	// ar++; // Error
	pt2++; // OK
	puts(pt2); // Check the first character

	/* Array and Pointer Differences */
	char heart[] = "I love kelly";
	const char* head = "I love Helly";

	for (int i = 0; i < 6; i++)
		putchar(heart[i]);
	putchar('\n');

	for (int i = 0; i < 6; i++)
		putchar(head[i]);
	putchar('\n');

	while (*(head) != '\0')
		putchar(*(head++));

	head = heart; // 이는 컴파일러에서 허용하고 있다.
	//heart = head; //Error

	heart[7] = "H";
	*(heart + 7) = 'K';

	putchar('\n');

	char* word = "Google"; //Note: const char * word = "Google"; is recommended
	//word[2] = 'o'; // Run-time error!
	puts(word);

	const char *str1 = "When all the lights are low, ...";
	const char* copy;

	copy = str1;

	printf("%s %p %p\n", str1, str1, &str1); // When all the lights are low, ... 00908610 00EFF61C
	printf("%s %p %p\n", copy, copy, &copy); // When all the lights are low, ... 00908610 00EFF610
	// str1과 copy는 TEXT Segment이므로 값이 같이 나온다

	putchar('\n');

	return 0;
}