#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define LEN 20

struct names {
	char given[LEN];
	char family[LEN];
};

struct friend {
	struct names full_name;
	char mobile[LEN];
};

int main()
{
	struct friend my_friends[2] = {
		{{"Ariana", "Grande"}, "1234-1234"},
		{{"Taylor", "Swift"}, "6550-8888"}
	};

	struct friend* girl_frined; // frined 구조체를 가르키는 포인터 변수

	girl_frined = &my_friends[0];

	printf("%zd\n", sizeof(struct friend));	// 60
	printf("%lld %s\n", (long long)girl_frined, girl_frined->full_name.given); // 255838909856 Ariana
	// -> : indirect member access operator

	girl_frined++;

	printf("%lld %s\n", (long long)girl_frined, (*girl_frined).full_name.given); // 255838909916 Taylor
	// . has higher precedence than *

	return 0;
}