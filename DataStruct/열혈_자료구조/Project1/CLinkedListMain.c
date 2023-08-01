#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	//원형 연결 리스트의 생성 및 초기화 ///
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	//리스트에 5개의 데이터를 저장 ///
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 1);
	LInsertFront(&list, 2);
}

