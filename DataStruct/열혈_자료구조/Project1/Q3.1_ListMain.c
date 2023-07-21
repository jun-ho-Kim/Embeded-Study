#include <stdio.h>
#include "ArrayList.h"

int main()
{
	List list;
	int data;
	ListInit(&list);

	// 1. 리스트를 생성 및 초기화 한 다음, 정수 1부터 9까지 리스트에 저장한다.
	for (int i = 1; i < 10; i++)
		LInsert(&list, i);

	
	//2. 리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산하여 출력한다.
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

	//3. 리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값을 모두 삭제 한다.
	LFirst(&list, &data);
	while (list.curPosition < list.numOfData - 1)
	{
		LNext(&list, &data);
		if (data % 2 == 0 || data % 3 == 0)
		{
			LRemove(&list);
		}
	}


	//4. 마지막으로 리스트에 저장된 데이터를 순서대로 출력한다.
	LFirst(&list, &data);
	printf("4. print %d\n", data);
	while (list.curPosition < list.numOfData - 1)
	{

		LNext(&list, &data);
		printf("4. print %d\n", data);
	}

	int z = 5;
	
}