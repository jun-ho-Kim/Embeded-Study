#include <stdio.h>
struct profile
{
	int age;
	double height;
};

struct student
{
	struct profile pf;
	int id;
	double grade;
};

int main(void)
{
	struct student juno;

	juno.pf.age = 28;
	juno.pf.height = 164.5;
	juno.id = 315;
	juno.grade = 4.0;

	printf("나이 : %d\n", juno.pf.age);
	printf("키 : %.1lf\n", juno.pf.height);
	printf("학번 : %d\n", juno.id);
	printf("학점 : %lf\n", juno.grade);

	int z = 0;

	return 0;
}