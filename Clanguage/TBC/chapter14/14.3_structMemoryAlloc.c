#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 구조체 안에서 멤버를 선언한 후 구조체 변수가 선언이 되어야 메모리가 할당이 된다.
// 구조체 선언만으로는 메모리 할당 X

int main()
{
	/*
		Well aligned structure
	*/

	struct Aligned
	{
		int a;
		float b;
		double c;
	};

	/*
	0 1 2 3 4 5 6 7| 8 9 10 11 12 13 14 15|
	|int a |float b| double c			  |
	4 + 4 + 8 = 16
	*/

	struct Aligned a1, a2;

	printf("struct Aligned a1\n"); // struct Aligned a1
	printf("Sizeof %zd\n", sizeof(struct Aligned)); // Sizeof 16
	printf("%lld\n", (long long)&a1);	// 129573581960
	printf("%lld\n", (long long)&a1.a);	// 129573581960
	printf("%lld\n", (long long)&a1.b);	// 129573581964
	printf("%lld\n", (long long)&a1.c);	// 129573581968

	printf("struct Aligned a2\n");	// struct Aligned a2
	printf("Sizeof %zd\n", sizeof(a2)); // Sizeof 16
	printf("%lld\n", (long long)&a2);	// 129573582008
	printf("%lld\n", (long long)&a2.a);	// 129573582008
	printf("%lld\n", (long long)&a2.b);	// 129573582012
	printf("%lld\n", (long long)&a2.c);	// 129573582016s

	/*
		padding (struct member alignment)
		- 1 word: 4 bytes in x86, 8bytes in x64
		// 효율성읖 높이기 위해서 1 word(4 byte) 단위로 주고 받는다.(in x64는 8 byte 단위)
	*/

	struct Padded1
	{
		char a;
		float b;
		double c;
	};

	/* Without padding
	0 1 2 3 4 5 6 7| 8 9 10 11 12 13 14 15|16
	|a|float b| double c		 | ?  ?  ?
	1 + 4 + 8 = 13
	*/

	/* With padding
	0 1 2 3 4 5 6 7| 8 9 10 11 12 13 14 15|
	|char a|float b|double c			  |
	4(char?) + 4 + 8 = 16
	*/
	struct Padded1 p1;

	printf("struct Aligned p1\n");		// struct Aligned p1
	printf("Sizeof %zd\n", sizeof(p1));	// Sizeof 16
	printf("%lld\n", (long long)&p1);	// 129573582056 // 컴파일러가 char 메모리 공간에 padding을 추가하였다.
	printf("%lld\n", (long long)&p1.a);	// 129573582056
	printf("%lld\n", (long long)&p1.b);	// 129573582060
	printf("%lld\n", (long long)&p1.c);	// 129573582064


	struct Padded2
	{
		float b;
		double c;
		char a;
	};

	struct Padded2 p2;

	printf("struct Aligned p2\n");		// struct Aligned p2
	printf("Sizeof %zd\n", sizeof(p2));	// Sizeof 24
	printf("%lld\n", (long long)&p2);	// 129573582104
	printf("%lld\n", (long long)&p2.a);	// 129573582120
	printf("%lld\n", (long long)&p2.b);	// 129573582104
	printf("%lld\n", (long long)&p2.c); // 129573582112


	struct Padded3
	{
		char a;
		double b;
		double c;
	};

	struct Padded3 p3;

	printf("struct Aligned p3\n");		// struct Aligned p3
	printf("Sizeof %zd\n", sizeof(p3));	// Sizeof 24
	printf("%lld\n", (long long)&p3);	// 129573582152
	printf("%lld\n", (long long)&p3.a);	// 129573582152
	printf("%lld\n", (long long)&p3.b);	// 129573582160
	printf("%lld\n", (long long)&p3.c);	// 129573582168

	struct Person
	{
		char name[41];
		int age;
		float height;
	};

	struct Person mommy;

	printf("\nstruct Person\n"); // struct Person
	printf("%lld\n", (long long)&mommy.name[0]);	// 129573582200
	printf("%lld\n", (long long)&mommy.age);		// 129573582244
	printf("%lld\n", (long long)&mommy.height);		// 129573582248
	printf("Sizeof %zd\n", sizeof(mommy));	// Sizeof 52

	struct Person f[4];

	printf("Sizeof a structure array %zd\n", sizeof(f));	// Sizeof a structure array 208

	return 0;
}