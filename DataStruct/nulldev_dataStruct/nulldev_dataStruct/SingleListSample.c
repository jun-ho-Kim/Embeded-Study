#include <stdio.h>

typedef struct NODE {
	//관리될 데이터
	int nData;

	//데이터 관리를 위한 포인터
	struct NODE* next;
} NODE;

int main()
{
	//NODE node = { 0 };
	NODE list[5] = { 0 };

	// 값 초기화
	list[0].nData = 100;
	list[1].nData = 200;
	list[2].nData = 300;
	list[3].nData = 400;
	list[4].nData = 500;

	// 연결리스트 구조화
	//case 0.
	//list[0].next = &list[1];
	//list[1].next = &list[2];
	//list[2].next = &list[3];
	//list[3].next = &list[4];
	//list[4].next = 0;





	//-----------------------연결 리스트 실험 해보기

	//case 1.
	list[0].next = &list[4];
	list[1].next = 0;
	list[2].next = &list[0]; // list[2].next = &list[0]; // 무한루프
	list[3].next = &list[2];
	list[4].next = &list[1];
	
	
	//list[0].next = 0;
	//list[1].next = &list[3];



	//배열로 index를 출력
	for (int i = 0; i < 5; ++i)
		//	000000F90E58FB30 : 100
		//	000000F90E58FB40 : 200
		//	000000F90E58FB50 : 300
		//	000000F90E58FB60 : 400
		//	000000F90E58FB70 : 500
		printf("%p: %d\n", &list[i], list[i].nData);

	NODE* pTmp = &list[0];
	while (pTmp != NULL)
	{
		//	000000F90E58FB30 : 100
		//	000000F90E58FB40 : 200
		//	000000F90E58FB50 : 300
		//	000000F90E58FB60 : 400
		//	000000F90E58FB70 : 500
		printf("%p: %d\n", pTmp, pTmp->nData);
		// overwrite - pTemp의 값이 연산에 참여한다.
		pTmp = pTmp->next;
	}

	printf("--------------------\n");
	// 노드에 대한 포인터
	// pointer로 chain을 넘어가는 방식



	//case 2.
	list[0].next = &list[4];
	list[1].next = 0;
	list[2].next = &list[0];
	list[3].next = &list[2];
	list[4].next = &list[1];
	NODE* pTmp = &list[3];

	while (pTmp != NULL)
	{
		//00000091E01BFA30: 400
		//00000091E01BFA20 : 300
		//00000091E01BFA00 : 100
		//00000091E01BFA40 : 500
		//00000091E01BFA10 : 200
		printf("%p: %d\n", pTmp, pTmp->nData);
		// overwrite - pTemp의 값이 연산에 참여한다.
		pTmp = pTmp->next;
	}

	//case 3.
	list[0].next = &list[4];
	list[1].next = &list[0];
	list[2].next = &list[0];
	list[3].next = &list[2];
	list[4].next = &list[1];
	NODE* pTmp = &list[0];


	while (pTmp != NULL)
	{
		//00000091E01BFA30: 400
		//00000091E01BFA20 : 300
		//00000091E01BFA00 : 100
		//00000091E01BFA40 : 500
		//00000091E01BFA10 : 200
		// ... 무한루프
		printf("%p: %d\n", pTmp, pTmp->nData);
		// overwrite - pTemp의 값이 연산에 참여한다.
		pTmp = pTmp->next;
	}

	return 0;
}