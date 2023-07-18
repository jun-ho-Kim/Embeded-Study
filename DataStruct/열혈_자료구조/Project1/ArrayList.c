#include <stdio.h>
#include "ArrayList.h"

//plist init 초기화
void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
} 

//plist arr 길이를 추가해 새로 추가된 길이에 data 인자 값 추가
void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

//현재 위치(curPosition)에 위치한 데이터를 pData 주소 파라미터에 저장
int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	printf("LFirst plist->arr[0] is %d\n", plist->arr[0]);
	*pdata = plist->arr[0];

	return TRUE;
}

//plist의 다음 위치의 데이터 값을 pdata 주소 파라미터로 저장
int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}


//LRemove - plist의 현재 위치의 데이터 부터 끝까지 삭제
LData LRemove(List* plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}