#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 5
#define WIDTH 10

char enemy[HEIGHT][WIDTH] =
{
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,0,0,1,0,1},
	{0,0,0,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,1,0,0},
	{1,0,1,1,1,0,0,1,0,0}
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//�迭�� ������ �޸𸮸� ����
//������ �迭: �����Ͱ� ���������� ����(�ð迭 ������)

//���� �迭�� ������ �����Ϳ��� �Ļ��ƴ�.
// C������ ���������ʹ� ���߹迭�� ����Ų��. 
// Cpp������  Ŭ������ ���ԵǸ鼭 ����������(���߹迭)�� �� �ʿ䰡 ��������. 

int main(int argc, char *argv[]) {
	
	/*
	static char days[8][4];
	static char *months[13];
	int i;
	
	strcpy(days[1], "SUN");
	strcpy(days[2], "MON");
	strcpy(days[3], "TUE");
	strcpy(days[4], "WED");
	strcpy(days[5], "THU");
	strcpy(days[6], "FRI");
	strcpy(days[7], "SAT");
	
	months[1] = "January";
	months[2] = "February";
//	months[3] = "MARCH";
//	months[4] = "April";
//	months[5] = "May";
//	months[6] = "jun";
//	months[7] = "july";
//	months[10] = "Octorbor";

	//������ �迭������ strcpy�� �ȵȴ�. 
	strcpy(months[1], "January");
	strcpy(months[2], "February");
	strcpy(months[3], "MARCH");
	strcpy(months[4], "April");
	
	printf("sizeof months 1 sizeof\n", sizeof(months));
	for(i = 1; i<=7; i++)
		printf("%-4s", days[i]);
	printf("\n");
	
	for(i =1; i<=12; i++)
		printf("%-10s", months[i]);
	printf("\n");	
	*/
	
	/*
	char *ps[3], *pps;
	int i;
	
	pps = ps;
	pps[0] = "Break test\n";
	pps[1] = "Lunch\n";
	pps[2] = "Supper\n";
	pps[3] = "Test\n";
	
	for(i = 0; i<3; i++) 
	{
		printf("pps[i] = %d  ", pps[i]);
		//printf(pps[i]); 
	}
	*/
	
	char friend1[HEIGHT][WIDTH];
	int x,y;
	for(y = 0; y< HEIGHT; y++)
		for(x=0; x<WIDTH; x++)
			friend1[y][x] = '_';
		
	printf("Enter coordinates in form x, y (4,2).\n");
	
	printf("Use negative numbers to quit.\n");
	
	while(x>=0)
	{
		for(y = 0; y<HEIGHT; y++)
		{
			for(x=0; x<WIDTH; x++)
				printf("%c", friend1[y][x]);
			printf("\n\n");
		}
		printf("coordinates: ");
		scanf("%d %d", &x, &y);
		if(enemy[y][x] == 1)
			friend1[y][x] = '��';
		else 
			friend1[y][x] = '��';
	}
	return 0;
}
