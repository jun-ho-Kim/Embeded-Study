#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[20] = "mango tree"; // �迭 �ʱ�ȭ
	strncpy(str, "apple-pie", 5);
	printf("%s\n", str); // apple tree

	return 0;
}