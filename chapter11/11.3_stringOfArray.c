#include <stdio.h>

int main()
{
	const char* mythings[5] = {
		"Dancing in the rain",
		"Counting apples",
		"Watching movies with friends",
		"Writing ad letters",
		"Studiying the C language"
	};

	const char yourthings[5][40] = {
		"Studying the C++ language",
		"Eating",
		"Watching Netflix",
		"Walking around till dark",
		"Deleting spam emails"
	};

	const char* temp1 = "Dancing in the rain";
	const char* temp2 = "Studying the C++ language";

	printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1);
	// 포인터만 가리키고 있고 같은 곳에 저장되어 있다.
	printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2);
	// stack에 배열로 메모리를 가지고 있기 때문에 주소가 다르다.
	//printf("%u %u\n", (unsigned)yourthings[0], (unsigned)temp2);
	printf("\n");

	printf("%-30s %-30s\n", "My Things:", "Your Things:");
	for (int i = 0; i < 5; i++)
		printf("%-30s %-30s\n", mythings[i], yourthings[i]);

	printf("\nsize of mythings: %zd, sizeof your yourthings: %zd\n", sizeof(mythings), sizeof(yourthings)); // 20(포인터 변수의 크기) 200 in x86

	for (int i = 0; i < 100; i++)
		printF("%c", mythings[0][i]);
	printf("\n");
	printf("\n");

	for (int i = 0; i < 200; i++)
		printF("%d", (int)yourthings[0][i]);
	printf("\n");

	for (int i = 0; i < 200; i++)
		printF("%d", (int)yourthings[0][i]);
	printf("\n");

	// Not a good idea to take advantage of this property

	return 0;
}