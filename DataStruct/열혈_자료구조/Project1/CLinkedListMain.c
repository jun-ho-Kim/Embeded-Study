#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	//���� ���� ����Ʈ�� ���� �� �ʱ�ȭ ///
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	//����Ʈ�� 5���� �����͸� ���� ///
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 1);
	LInsertFront(&list, 2);
}

