#include <stdio.h>

int main(void)
{
	int age;
	char name[20];

	printf("나이 입력 : "); // 17
	scanf("%d", &age);
	//getchar();
	printf("이름 입력 : ");
	gets(name); // gets에서 scanf()에서 받은 \n을 \0으로 바꾸어준다. // 그래서 getchar()을 사용하여 \n 문자를 버린다.
	printf("나이 : %d, 이름 : %s\n", age, name); // 이름 입력 : 나이 : 17, 이름 :

	return 0;

}