#include <stdio.h>
#include "ArrayList_practice.h"



void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData > LIST_LEN)
	{
		printf("�� �̻� ������ �� �����ϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	plist->numOfData++;
}

int LFirst(List* plist, LData*  pData)
{
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	printf("LFisrt plist->arr[0] is %d\n", plist->arr[0]);
	*pData = plist->arr[0];
}

//TODO: LNext���� LRemove���� �� ���� �ڵ� �ĺ���

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= plist->numOfData - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];

	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;

	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}

	plist->numOfData--;
	plist->curPosition--;
}

int LCount(List * plist)
{
	return plist->numOfData;
}
