#include <stdio.h>
int main(void)
{
	char* dessert = "banana";
	printf("���� �Ľ��� %s�Դϴ�.\n", dessert);	// ���� �Ľ��� banana�Դϴ�.
	printf("banana p is % p\n", dessert);	// banana p is 00007FF6C9DC9C24
	printf("dessert1 p is %p\n", &dessert); // dessert1 p is 000000C0D635FBB8

	dessert = "apple";
	printf("���� �Ľ��� %s�Դϴ�.\n", dessert);	// ���� �Ľ��� apple�Դϴ�.
	printf("apple p is %p\n", dessert);	// apple p is 00007FF6C9DC9C4C

	printf("dessert2 p is %p", &dessert); // dessert2 p is 000000C0D635FBB8
	while (*dessert != '\0')
	{
		putchar(*dessert); 
		dessert++; 
	} // // apple

	char* pa = "apple";
	char* pb = "apple";

	printf("\n%p, %p", pa, pb); // 00007FF7B9CE9C4C, 00007FF7B9CE9C4C
	
	return 0;

	// desssert �����Ϳ� ���� �ְ� �װ��� �ٽ� �����ϸ� ���� ���� �߰��� dessert�� �޸� �ּҴ� ���� �ּҿʹ� �ٸ���.
	// �׷��� �ȴٸ� banana�� ������Ҵ� ������ ��������� �޸� ������ �����ְ� �ȴ�.
}