#include <stdio.h>
int main(void)
{
	char* dessert = "banana";
	printf("오늘 후식은 %s입니다.\n", dessert);	// 오늘 후식은 banana입니다.
	printf("banana p is % p\n", dessert);	// banana p is 00007FF6C9DC9C24
	printf("dessert1 p is %p\n", &dessert); // dessert1 p is 000000C0D635FBB8

	dessert = "apple";
	printf("내일 후식은 %s입니다.\n", dessert);	// 내일 후식은 apple입니다.
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

	// desssert 포인터에 값을 넣고 그것을 다시 수정하면 새로 값을 추가한 dessert의 메모리 주소는 이전 주소와는 다르다.
	// 그렇게 된다면 banana를 적어놓았던 변수는 사라졌지만 메모리 값에는 남아있게 된다.
}