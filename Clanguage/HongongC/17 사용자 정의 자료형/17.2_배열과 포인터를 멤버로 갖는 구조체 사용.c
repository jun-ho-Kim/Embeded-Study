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

	strcpy(juno.name, "����ȣ");
	juno.age = 28;
	juno.height = 180.4;

	juno.intro = (char*)malloc(80);
	printf("�ڱ�Ұ� :");
	gets(juno.intro);

	printf("�̸� : %s\n", juno.name);
	printf("���� : %d\n", juno.age);
	printf("Ű : %.1lf\n", juno.height);
	printf("�ڱ�Ұ� : %s\n", juno.intro);
	free(juno.intro);

	int z = 4;
	
	return 0;
}