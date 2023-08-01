#include <stdio.h>
#include <string.h>
#include <malloc.h>

//todo �� �� �غ���

typedef struct NODE {
	char szData[64];
	struct NODE* next;
} NODE;

// �����͸� �ϳ� �δ� ���
NODE* g_head = {0};

int IsEmpty()
{
	if (g_head->next == NULL)
		return 1;

	return 0;
}

void PrintList(void)
{
	NODE* pHead = g_head;
	while (pHead != NULL)
	{
		printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
		pHead = pHead->next;
	}

	putchar('\n');
}

int InsertAtNode(char* pszData)
{
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	memset(pNode, 0, sizeof(NODE));

	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);

	if (IsEmpty())
		g_head = pNode;
	else {
		// Node�� ���� �߰��ϴ� ��� ������ �ִ� Node�ڸ��� �߰��ϴ� ����
		// (���� ������ �ִ� Node �ڿ� �߰��� ���� ������ ������ �ִ� Node �ڸ��� �߰��ϴ� ���� ���ϴ�.)
		// ������ Overwrite�� �Ǹ� �����Ͱ� ���ǵȴ�.
		// �׷��� pHead ������ ���߿� ������Ʈ ���ش�.

		pNode->next = g_head->next;
		g_head->next = pNode;
	}

	return 1;
}

InsertAtTail(char* pszData)
{
	//������ ��带 ã�´�.
	NODE* pTmp = &g_head;
	while (pTmp->next != 0)
		pTmp = pTmp->next;

	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	memset(pNode, 0, sizeof(NODE));
	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);

	pTmp->next = pNode;

}

void ReleaseList(void)
{
	NODE* pTmp = g_head;
	while (pTmp != NULL)
	{
		NODE* pDelete = pTmp;
		pTmp = pTmp->next;

		printf("Delete: [%p] %s\n", pDelete, pDelete->szData);

		free(pDelete);
	}
}

// 
int FindData(char* pszData)
{
	NODE* pTmp = g_head->next;
	NODE* pPrev = &g_head;

	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szData, pszData) == 0)
			return 1;
		pTmp = pTmp->next;
		pPrev = pPrev->next;
	}
	return 0;
}

int DeleteData(char* pszData)
{
	NODE* pCur = g_head->next;
	NODE* pPrev = NULL;
	while (pCur != NULL)
	{
		if (strcmp(pCur->szData, pszData) == 0)
		{
			// ����
			printf("DeleteData(): %s\n", pCur->szData);
			if (pPrev != NULL)
				//todo: �Ʒ� �ڵ� bp �� �׽�Ʈ�غ���("TEST03")
				pPrev->next = pCur->next;
			else
				g_head = pCur->next;

			free(pCur);
			return 1;
		}
		pCur = pCur->next;
		pPrev = pPrev->next;
	}
}



int main()
{
	//List �׽�Ʈ�� ���� �ڵ�
	InsertAtNode("TEST01");
	PrintList(); // [000001E05F6E58A0] TEST01, next[0000000000000000]
	InsertAtNode("TEST02");
	PrintList();
	//[000001E05F6E33E0] TEST02, next[000001E05F6E58A0]
	//[000001E05F6E58A0] TEST01, next[0000000000000000]
	InsertAtNode("TEST03");
	PrintList();
	//[000001E05F6EFE40] TEST03, next[000001E05F6E33E0]
	//[000001E05F6E33E0] TEST02, next[000001E05F6E58A0]
	//[000001E05F6E58A0] TEST01, next[0000000000000000]

	//Delete: [00000232ACA1FE40] TEST03
	//Delete: [00000232ACA133E0] TEST02
	//Delete: [00000232ACA158A0] TEST01

	if (FindData("TEST01") == 1)
		printf("FindData(): TEST01 found\n"); //FindData(): TEST01 found
	if (FindData("TEST02") == 1)
		printf("FindData(): TEST02 found\n"); //FindData() : TEST02 found
	if (FindData("TEST03") == 1)
		printf("FindData(): TEST03 found\n"); //FindData() : TEST03found

	//todo: DeleteData - ���� ����� ���� �׽�Ʈ�غ��� ������غ���
	DeleteData("TEST03");
	 
	//NODE ����
	ReleaseList();

	return 0;
}