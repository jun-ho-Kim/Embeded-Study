#include <stdio.h>

int main(void)
{
	int age;
	char name[20];

	printf("���� �Է� : "); // 17
	scanf("%d", &age);
	//getchar();
	printf("�̸� �Է� : ");
	gets(name); // gets���� scanf()���� ���� \n�� \0���� �ٲپ��ش�. // �׷��� getchar()�� ����Ͽ� \n ���ڸ� ������.
	printf("���� : %d, �̸� : %s\n", age, name); // �̸� �Է� : ���� : 17, �̸� :

	return 0;

}