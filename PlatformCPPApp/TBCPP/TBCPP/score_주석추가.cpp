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

	// scoreData.csv ���� �������� ���ϸ� ���α׷� ����
	if ((fp = fopen("scoreData.csv", "r+")) == NULL)
	{
		printf("File open error...\n");
		exit(-1);
	}

	// ���� ���� ������ �����ͼ� ó���ϱ�
	for (int i = 0; i < 6; i++) // ���� ���� i+1 �� ������ ó��
	{
		fgets(buffer, 1024, fp); // buffer ������ ���� ���� �־���

		printf("buffer is %s", buffer);

		p = strtok(buffer, ","); // strtok �Լ� ����Ͽ� , �� ���� 1�� ������ �ּ�

		strcpy(name[i], strtok(NULL, ",")); // ���� �̸� �����͸� name[i]�� ����

		for (int j = 0; j < 5; j++)
		{
			score[i][j] = atoi(strtok(NULL, ",")); // strtok �Լ� ����Ͽ� , �� ���� ������ score[i][j]�� ����
		}
	}

	// �հ�, ��� ���ϱ�
	for (int i = 0; i < 6; i++)
	{
		
		for (int j = 0; j < 5; j++)
		{
			sum[i] += score[i][j];
		}
		avg[i] = sum[i] / 5;
	}
	fclose(fp);

	// ���� ��� ����
	fp = fopen("result.csv", "w+");

	fprintf(fp, "��ȣ, �̸�, ����, ����, ����, ����, ��ȸ, ����, ��� \n");
	for (int i = 1; i < 6; i++)
	{
		fprintf(fp, "%2d, %s, %4d, %4d, %4d, %4d, %4d, %4d, %4d \n",
			i, &name[i], score[i][0], score[i][1], score[i][2], score[i][3], score[i][4], sum[i], avg[i]);
	}
	fclose(fp);
	return 0;
}
