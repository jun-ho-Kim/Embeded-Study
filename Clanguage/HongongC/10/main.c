#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	//���� 10.1 
	int ary[3];
	int i;
	
	*(ary + 0) = 10;
	
	*(ary + 1) = *(ary + 0) + 10;
	
	printf("�� ��° �迭 ��ҿ� Ű���� �Է� :");
	scanf("%d", ary + 2);
	
	for(i = 0; i < 3; i++)
	{
		printf("%5d", *(ary + i));
	} 
	*/
	
	/*
	// ���� 10.2 
	int ary[3];
	printf("1 %p\n", ary);
	int *pa = ary;
	printf("2 %p\n", pa);
	int i;
	
	*pa = 10;
	*(pa + 1) = 20;
	pa[2] = pa[0] + pa[1];
	
	for(i=0; i<3; i++)
	{
		printf("%5d", pa[i]);
	}
	
	printf("\n 3 %p", &ary[2]);
	int* pa2 = &ary[2];
	printf("\n 4 %p", pa2);
	*/
	
	/*
	//���� 10.3
	int ary[3] = {10, 20, 30};
	int *pa = ary;
	int i;
	
	printf("�迭�� �� : ");
	for(i=0; i<3;i++)
	{
		printf("%d ", *pa);
		pa++;
	}
	*/
	
	
	//���� 10.4 
	int ary[5] = { 10, 20, 30, 40, 50 };
	int *pa = ary;
	int *pb = pa+3; //40
	
	printf("pa : %u\n", pa);	// 6487536
	printf("pb : %u\n", pb);	// 6487548
	pa++;
	printf("pb - pa : %u\n", pb - pa); // 2
	
	printf("�տ� �ִ� �迭 ����� �� ���: ");
	if(pa < pb) printf("%d\n", *pa); //20
	else printf("%d\n", *pb); 
	
	
	return 0;
}
