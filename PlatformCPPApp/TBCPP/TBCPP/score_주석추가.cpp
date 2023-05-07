#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	FILE* fp;
	int line = 0;

	char name[6][20];
	int score[6][5];
	int sum[6] = { 0, };
	int avg[6] = { 0, };
	char buffer[1024];
	char* p;


	int subjectSum[5] = { 0, };
	int subjectAvg[5] = { 0, };

	// scoreData.csv 파일 가져오지 못하면 프로그램 종료
	if ((fp = fopen("scoreData.csv", "r+")) == NULL)
	{
		printf("File open error...\n");
		exit(-1);
	}

	// 엑셀 파일 데이터 가져와서 처리하기
	for (int i = 0; i < 6; i++) // 엑셀 파일 i+1 줄 데이터 처리
	{
		fgets(buffer, 1024, fp); // buffer 변수에 파일 변수 넣어줌

		printf("buffer is %s", buffer);

		p = strtok(buffer, ","); // strtok 함수 사용하여 , 로 나눈 1열 데이터 주소

		strcpy(name[i], strtok(NULL, ",")); // 엑셀 이름 데이터를 name[i]에 복사

		for (int j = 0; j < 5; j++)
		{
			score[i][j] = atoi(strtok(NULL, ",")); // strtok 함수 사용하여 , 로 나눈 데이터 score[i][j]에 복사
		}
	}

	// 합계, 평균 구하기
	for (int i = 0; i < 6; i++)
	{
		
		for (int j = 0; j < 5; j++)
		{
			sum[i] += score[i][j];
		}
		avg[i] = sum[i] / 5;
	}
	fclose(fp);

	// 파일 출력 로직
	fp = fopen("result.csv", "w+");

	fprintf(fp, "번호, 이름, 국어, 수학, 영어, 과학, 사회, 총점, 평균 \n");
	for (int i = 1; i < 6; i++)
	{
		fprintf(fp, "%2d, %s, %4d, %4d, %4d, %4d, %4d, %4d, %4d \n",
			i, &name[i], score[i][0], score[i][1], score[i][2], score[i][3], score[i][4], sum[i], avg[i]);
	}
	fclose(fp);
	return 0;
}
