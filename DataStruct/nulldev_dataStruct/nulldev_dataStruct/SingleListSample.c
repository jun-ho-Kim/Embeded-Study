#include <stdio.h>

typedef struct NODE {
	//������ ������
	int nData;

	//������ ������ ���� ������
	struct NODE* next;
} NODE;

int main()
{
	//NODE node = { 0 };
	NODE list[5] = { 0 };

	// �� �ʱ�ȭ
	list[0].nData = 100;
	list[1].nData = 200;
	list[2].nData = 300;
	list[3].nData = 400;
	list[4].nData = 500;

	// ���Ḯ��Ʈ ����ȭ
	//case 0.
	//list[0].next = &list[1];
	//list[1].next = &list[2];
	//list[2].next = &list[3];
	//list[3].next = &list[4];
	//list[4].next = 0;





	//-----------------------���� ����Ʈ ���� �غ���

	//case 1.
	list[0].next = &list[4];
	list[1].next = 0;
	list[2].next = &list[0]; // list[2].next = &list[0]; // ���ѷ���
	list[3].next = &list[2];
	list[4].next = &list[1];
	
	
	//list[0].next = 0;
	//list[1].next = &list[3];



	//�迭�� index�� ���
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
		// overwrite - pTemp�� ���� ���꿡 �����Ѵ�.
		pTmp = pTmp->next;
	}

	printf("--------------------\n");
	// ��忡 ���� ������
	// pointer�� chain�� �Ѿ�� ���



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
		// overwrite - pTemp�� ���� ���꿡 �����Ѵ�.
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
		// ... ���ѷ���
		printf("%p: %d\n", pTmp, pTmp->nData);
		// overwrite - pTemp�� ���� ���꿡 �����Ѵ�.
		pTmp = pTmp->next;
	}

	return 0;
}