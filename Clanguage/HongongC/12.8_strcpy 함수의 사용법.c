#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[80] = "strawberry";
	char str2[80] = "apple";
	char *ps1 = "banana";
	char *ps2 = str2;

	printf("���� ���ڿ� : %s\n", str1);
	strcpy(str1, str2);
	printf("�ٲ� ���ڿ�: %s\n", str1);

	strcpy(str1, ps1);
	printf("�ٲ� ���ڿ�: %s\n", str1);

	strcpy(str1, ps2);
	printf("�ٲ� ���ڿ�: %s\n", str1);

	strcpy(str1, "banana");
	printf("�ٲ� ���ڿ�: %s\n", str1);

	// strcpy �Լ��� ���� ���� ���� �迭���� ù ��° �μ��� �ְ� ������ ���ڿ��� �� ��° �μ��� �ش�.
	// ���ڿ��� �����ϴ� ����� ���ڿ��� ù ��° ���ں��� �� ���ڰ� ���� ������ ���ڸ� �ϳ��� �迭�� �Ű� �����Ѵ�.
	// ���� ������ ���ڿ��� ���� ��ġ�� �� �� �ִٸ� � ���̵� �� ��° �μ��� ����� �� �ִ�.

	// *ù ��° �μ��� char �迭�̳� �迭���� ������ �����͸� ����� �� �ִ�
	// *�� ��° �μ��� ���ڿ��� ���� ��ġ�� �� �� �ִٸ� � ���̵� ����� �� �ִ�.


	return 0;
}