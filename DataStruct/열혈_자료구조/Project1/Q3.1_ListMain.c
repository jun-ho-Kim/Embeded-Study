#include <stdio.h>
#include "ArrayList.h"

int main()
{
	List list;
	int data;
	ListInit(&list);

	// 1. ����Ʈ�� ���� �� �ʱ�ȭ �� ����, ���� 1���� 9���� ����Ʈ�� �����Ѵ�.
	for (int i = 1; i < 10; i++)
		LInsert(&list, i);

	
	//2. ����Ʈ�� ����� ���� ���������� �����Ͽ� �� ���� ����Ͽ� ����Ѵ�.
	int sum = 0;
	LFirst(&list, &data);
	sum += data;
	printf("sum is %d\n", sum);
	while (list.curPosition < list.numOfData-1)
	{
		LNext(&list, &data);
		printf("curPosition is %d\n", list.curPosition);
		printf("numOfData is %d\n", list.numOfData);
		sum += data;
	}
	printf("sum is %d\n", sum);

	//3. ����Ʈ�� ����� ���� �� 2�� ����� 3�� ����� �ش��ϴ� ���� ��� ���� �Ѵ�.
	LFirst(&list, &data);
	while (list.curPosition < list.numOfData - 1)
	{
		LNext(&list, &data);
		if (data % 2 == 0 || data % 3 == 0)
		{
			LRemove(&list);
		}
	}


	//4. ���������� ����Ʈ�� ����� �����͸� ������� ����Ѵ�.
	LFirst(&list, &data);
	printf("4. print %d\n", data);
	while (list.curPosition < list.numOfData - 1)
	{

		LNext(&list, &data);
		printf("4. print %d\n", data);
	}

	int z = 5;
	
}