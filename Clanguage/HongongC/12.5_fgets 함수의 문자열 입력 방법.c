#include <stdio.h>

int main(void)
{
	char str[80];

	printf("������ ���Ե� ���ڿ� �Է� :");

	fgets(str, sizeof(str), stdin);	//test
	printf("str size of is %d\n", strlen(str));	// str size of is 5

	str[strlen(str) - 1] = '\0';
	printf("str size2 of is %d\n", strlen(str));	// str size2 of is 4

	//fgets()�� ���� ���� \n\0�� �߰��Ѵ�.
	//gets()�Լ��� \n�� �߰�
	//fgets()�Լ� ���� \n�� �����ְ� ������ str[strlen(str) - 1] = '\0'; �ڵ带 �߰�����.

	return 0;
}