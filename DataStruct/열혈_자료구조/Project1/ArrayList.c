#include <stdio.h>
#include "ArrayList.h"

//plist init �ʱ�ȭ
void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
} 

//plist arr ���̸� �߰��� ���� �߰��� ���̿� data ���� �� �߰�
void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

//���� ��ġ(curPosition)�� ��ġ�� �����͸� pData �ּ� �Ķ���Ϳ� ����
int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	printf("LFirst plist->arr[0] is %d\n", plist->arr[0]);
	*pdata = plist->arr[0];

	return TRUE;
}

//plist�� ���� ��ġ�� ������ ���� pdata �ּ� �Ķ���ͷ� ����
int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}


//LRemove - plist�� ���� ��ġ�� ������ ���� ������ ����
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