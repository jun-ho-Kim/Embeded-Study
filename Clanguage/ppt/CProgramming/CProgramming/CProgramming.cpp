#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT 10
#define DEPT 6

int main()
{
    FILE* fp;
    int i = 0;
    int student, dept;
    int score[STUDENT][10] = {0, };
    char name[STUDENT][20];
    int stdNum[STUDENT] = { 0, };
    char data[2048];
    char* p;
    char header[DEPT + 5][10];
    int rank[STUDENT] = { 0, };

    int sum[STUDENT] = { 0, };
    int avg[STUDENT] = { 0, };

    if ((fp = fopen("sungjuk.csv", "r+")) == NULL)
    {
        printf("File open error...\n");
        exit(-1);
    }

    // 엑셀 헤더 부분 입력
    fgets(data, 2048, fp);
    p = strtok(data, ",");
    strcpy(header[0], p);
    for (int i = 1; i < (DEPT + 5); i++)
    {
        p = strtok(NULL, ",");
        strcpy(header[i], p);
    }

    // 엑셀 점수부분 입력
    while (i < STUDENT)
    {
        fgets(data, 2048, fp);
        
        p = strtok(data, ",");
        stdNum[i] = atoi(p);
        strcpy(name[i], strtok(NULL, ","));
        for (int j = 0; j < DEPT; j++)
        {
            score[i][j] = atoi(strtok(NULL, ","));
        }
        fseek(fp, 0, SEEK_CUR);
        i++;
    }
    // 합계, 평균, 석차
    for (int i = 0; i < STUDENT; i++)
    {

        for (int j = 0; j < DEPT; j++)
        {
            sum[i] += score[i][j];
        }
        avg[i] = sum[i] / 5;
    }

    for (int i = 0; i < STUDENT; i++)
    {
        int idx = 1;
        for (int j = 0; j < STUDENT; j++)
        {


            if (sum[i] < sum[j])
                idx++;
        }
        rank[i] = idx;
    }

    fclose(fp);


    // 파일 출력
    fp = fopen("Trans.csv", "w+");
    for (int i = 0; i < (DEPT + 5); i++)
    {
        if(i == (DEPT + 5 -1))
            fprintf(fp, "%s", header[i]);
        else
            fprintf(fp, "%s,", header[i]);

    }

    for (int i = 0; i < STUDENT; i++)
    {
        fprintf(fp, "%2d,", stdNum[i]);
        fprintf(fp, "%s,", name[i]);    
        for (int j = 0; j < DEPT; j++)
        {
            fprintf(fp, "%4d,", score[i][j]);
        }
        fprintf(fp, "%4d,", sum[i]);
        fprintf(fp, "%4d,", avg[i]);
        fprintf(fp, "%4d,", rank[i]);
        fprintf(fp, "\n");
    }

    fclose(fp);
}

