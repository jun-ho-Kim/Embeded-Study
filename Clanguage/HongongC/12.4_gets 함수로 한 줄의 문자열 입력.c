#include <stdio.h>

int main(void)
{
	char str[80];

	printf("������ ���Ե� ���ڿ� �Է� : ");
	gets_s(str, strlen(str)); // apple jam
	printf("�Է��� ���ڿ��� %s �Դϴ�.", str); // �Է��� ���ڿ��� apple jam �Դϴ�.

	//scanf() �Լ��� Space Bar, Tap, Enter�� �Է��ص� ��� �Է��� ��ٸ���.

	//gets()�Լ��� ���ڿ��� �Ϻη� �Է��ϰ� ���ڿ� �Է� ���� Enter�� ������ �Է��� ������.
	//\n ��ſ� \0�� ����

	int z = 4;

	return 0;
}