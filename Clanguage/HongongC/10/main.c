#include <stdio.h>
#include <stdlib.h>


//����10.5
//void print_ary(int *pa);

//����10.6
void print_ary(int *pa, int size);

void input_ary(double *pa, int size);
double find_max(double *pa, int size);

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
	/*
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
	*/
	
	/*
	//����10.5
	int ary[5] = {10,20,30,40,50};
	
	printf("arr main address %d\n", ary);	// arr main address 6487552
	
	print_ary(ary);
	*/
	
	/*
	//����10.6
	int ary1[5] = {10,20,30,40,50};
	int ary2[7] = {10,20,30,40,50,60,70};
	
	print_ary(ary1, 5);
	printf("\n");
	print_ary(ary2, 7);
	 */
	 
	//���� 10.7
	double ary[5];
	double max;
	int size=sizeof(ary) / sizeof(ary[0]); 
	 
	input_ary(ary, size);
	max = find_max(ary, size);
	printf("�迭�� �ִ밪 : %.1lf\n", max);
	
	return 0;
}
/*
//����10.5 
void print_ary(int *pa)
{
	printf("pa print_ary address %d\n", &pa);// pa print_ary address 6487520
	int i;
	for(i=0; i<5; i++)
	{
		printf("%d ", pa[i]); // 10 20 30 40 50
	}
}
*/

void print_ary(int *pa, int size)
{
	int i;
	
	for(i = 0; i<size; i++)
	{
		printf("%d ", pa[i]);
	}
}

void input_ary(double *pa, int size)
{
	int i;
	printf("%d���� �Ǽ��� �Է�: ", size);
	for(i=0;i<size;i++)
	{
		scanf("%lf", pa+i);
	}

}
double find_max(double *pa, int size)
{
	double max;
	int i;
	
	max = pa[0];
	for(i=0;i<size;i++)
	{
		if(pa[i]> max) max=pa[i];
	}
	
	return max;
}
