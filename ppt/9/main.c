#include <stdio.h>
#include <stdlib.h>
#define MAN 3
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	//예제 9.1
	int a;
	double b;
	char c;
	
	printf("int") 
	*/
	
	/*
	// txt 파일로 입력 받아서 성적내는 프로그램 
	FILE *fp;
	fp = fopen("c:\\work\\ppt\\9\\test2.txt", "rt");
	
	int nCount;
	fscanf(fp, "%d\n", &nCount);
	char strDesc[255];
	int kor[nCount + 1], eng[nCount + 1], math[nCount + 1], his[nCount + 1], sci[nCount + 1];
	int sum[nCount + 1], avg[nCount + 1], rank[nCount + 1];
	
	char name[nCount+1][10];
	
	
	
	if(fp==NULL || nCount ==0)
	{
		printf("실패 - 종료\n");
		return 1;
	}
	
	printf("nCount is %d\n", nCount);
	for(int i = 0; i<nCount; i++)
	{
		fscanf( fp, "%s %d %d %d %d %d\n", &name[i], &kor[i], &eng[i], &math[i], &his[i], &sci[i]);
		sum[i] = kor[i] + eng[i] + math[i] + his[i] + sci[i];
		avg[i] = sum[i] / 5;
	}
	
	for(int i = 0; i < nCount; i++)
	{
		int idx = 1;
		for(int j = 0; j<nCount; j++)
		{
			
			
			if(sum[i] < sum[j])
				idx++;
		}
		rank[i] = idx;
	}
	
	printf("순번, 이름,\t 국어,\t 영어,\t 수학,\t 국사,\t 과학,\t 총점,\t 평균,\t 등수\n");	
	printf("==============================================================================\n");
	for(int i = 0; i<nCount; i++)
	{
		fscanf( fp, "%s %d %d %d %d %d\n", &name[i], &kor[i], &eng[i], &math[i], &his[i], &sci[i]);
		sum[i] = kor[i] + eng[i] + math[i] + his[i] + sci[i];
		avg[i] = sum[i] / 5;
		printf( "%3d   %s\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t\n",i+1, name[i], kor[i], eng[i], math[i], his[i], sci[i], sum[i], avg[i], rank[i]);
		
	}
	printf("==============================================================================\n");

    //while (fscanf(fp, "%*s %*s %s ", buf) == 1)
    //    printf("%s\n", buf);
	//fprintf(fp, "example.");
	
	fclose(fp);
	printf("완료\n");
	
	
	/*
	//ppt 예제 
	static int x[5] = {100, 200, 300, 400, 500};
	int i, *px;
	
	px = x;
	printf("px=x; px = %p\n", px);
	px = &x[0];
	printf("\n\ni px+i *(px=i), px[i] x[i] \n\n");
	for(i=0; i<4; i++)
		printf("%d %9d %9d %9d %9d \n\n", i,px+i, *(px+i), px[i], x[i]);
	
	printf("0 %d\n", *px);
	printf("0p %p\n", *px);
	printf("0-1 %d\n", px[1]);
	printf("0-1p %p\n", px[1]);	
	printf("1d %d\n", *px+1);
	printf("1 %p\n", *px+1);
	printf("1d %d\n", *px+1);
	printf("1 %p\n", *px+1);
	printf("2 %d\n", *px++);
	printf("2p %p\n", *px++);	
	*/
	/*
	printf("1 %d\n", *px++);
	printf("1p %p\n", *px++);
	printf("2 %d\n", (*px)++);
	printf("2p %p\n", (*px)++);
	*/
	
	
	return 0;
}
