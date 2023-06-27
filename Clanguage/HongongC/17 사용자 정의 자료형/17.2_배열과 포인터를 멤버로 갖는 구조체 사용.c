#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile
{
	char name[20];
	int age;
	double height;
	char* intro;
};

int main(void)
{
	struct profile juno;

	strcpy(juno.name, "김준호");
	juno.age = 28;
	juno.height = 180.4;

	juno.intro = (char*)malloc(80);
	printf("자기소개 :");
	gets(juno.intro);

	printf("이름 : %s\n", juno.name);
	printf("나이 : %d\n", juno.age);
	printf("키 : %.1lf\n", juno.height);
	printf("자기소개 : %s\n", juno.intro);
	free(juno.intro);

	int z = 4;
	
	return 0;
}