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

//배열은 동일한 메모리를 점유
//포인터 배열: 데이터가 연속적으로 저장(시계열 데이터)

//이중 배열은 이차원 포인터에서 파생됐다.
// C에서는 다중포인터는 다중배열을 가리킨다. 
// Cpp에서는  클래스가 도입되면서 이중포인터(이중배열)을 쓸 필요가 없어졌다. 

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

	//포인터 배열에서는 strcpy가 안된다. 
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
			friend1[y][x] = '■';
		else 
			friend1[y][x] = '□';
	}
	return 0;
}
