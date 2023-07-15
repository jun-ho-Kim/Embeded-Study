#include <stdio.h>
#include <string.h>
#include <malloc.h>

//todo �� �� �غ���

typedef struct NODE {
	char szData[64];
	struct NODE* next;
} NODE;

// �����͸� �ϳ� �δ� ���
NODE* g_pHead = NULL;

void PrintList(void)
{
	NODE* pHead = g_pHead;
	while (pHead != NULL)
	{
		printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
		pHead = pHead->next;
	}

	putchar('\n');
}

int InsertNewNode(char* pszData)
{
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	memset(pNode, 0, sizeof(NODE));

	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);

	if (g_pHead == NULL)
		g_pHead = pNode;
	else {
		// Node�� ���� �߰��ϴ� ��� ������ �ִ� Node�ڸ��� �߰��ϴ� ����
		// (���� ������ �ִ� Node �ڿ� �߰��� ���� ������ ������ �ִ� Node �ڸ��� �߰��ϴ� ���� ���ϴ�.)
		// ������ Overwrite�� �Ǹ� �����Ͱ� ���ǵȴ�.
		// �׷��� pHead ������ ���߿� ������Ʈ ���ش�.

		pNode->next = g_pHead;
		g_pHead = pNode;
	}

	return 1;
}

void ReleaseList(void)
{
	NODE* pTmp = g_pHead;
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
	NODE* pTmp = g_pHead;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szData, pszData) == 0)
			return 1;
		pTmp = pTmp->next;
	}
	return 0;
}

int DeleteData(char* pszData)
{
	NODE* pTmp = g_pHead;
	NODE* pPrev = NULL;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szData, pszData) == 0)
		{
			// ����
			printf("DeleteData(): %s\n", pTmp->szData);
			if (pPrev != NULL)
				//todo: �Ʒ� �ڵ� bp �� �׽�Ʈ�غ���("TEST03")
				pPrev->next = pTmp->next;
			else
				g_pHead = pTmp->next;

			free(pTmp);
			return 1;
		}
		pPrev = pTmp;
		pTmp = pTmp->next;
	}
}



int main()
{
	//List �׽�Ʈ�� ���� �ڵ�
	InsertNewNode("TEST01"); 
	PrintList(); // [000001E05F6E58A0] TEST01, next[0000000000000000]
	InsertNewNode("TEST02");
	PrintList();
	//[000001E05F6E33E0] TEST02, next[000001E05F6E58A0]
	//[000001E05F6E58A0] TEST01, next[0000000000000000]
	InsertNewNode("TEST03");
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