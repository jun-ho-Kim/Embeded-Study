#include <stdio.h>

int main(void)
{
	char str[80] = "apple juice";
	char *ps = "banana";

	puts(str); // apple juice // apple joice ����ϰ� �� �ٲ�
	fputs(ps, stdout); // banana�� �Է�
	puts("milks"); // banana�� �̾� milk ���
	// bananamilks

	// puts �Լ��� fputs�� �޸� ���ڿ��� ����� �Ŀ� �ڵ����� ���� �ٲ��ֹǷ� �������� ���� �ٲٰ� ���� ���� �������� ������.
	// fputs�� ����ϸ� banana�� �̾ �ٷ� milk�� ��µȴ�.

	return 0;
}