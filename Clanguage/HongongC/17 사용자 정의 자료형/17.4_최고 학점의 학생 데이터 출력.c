#include <stdio.h>

struct student
{
	int id;
	char name[20];
	double grade;
};

int main(void)
{
	struct student s1 = { 315, "ȫ�浿", 2.4 },
		s2 = { 316, "�̼���", 3.7 },
		s3 = { 317, "�������", 4.4 };

	struct student max;

	max = s1;
	printf("max pointer : %p\n", &max);	// max pointer : 008FFCF4
	printf("s1 pointer : %p\n", &s1);	//  s1 pointer : 008FFD6C


	if (s2.grade > max.grade) max = s2;
	if (s3.grade > max.grade) max = s3;

	printf("�й� : %d\n", max.id);
	printf("�̸� : %s\n", max.name);
	printf("���� : %.1lf\n", max.grade);

	int z = 0;

	return 0;
}