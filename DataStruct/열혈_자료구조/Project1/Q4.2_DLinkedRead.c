#include <stdio.h>
#include <stdlib.h>

// 더미 노드를 추가하고, 그에 따른 코드의 변화를 직접 확인하기로 하겠다.
// 이 예제는 리스트이 끝에다가 노드를 추가하는 방식으로 head와 tail이 모두 필요하다.
// Q4.1_LinkedRead.c 코드와 동일
typedef struct __node
{
	int data;
	struct __node* next;
} Node;

int main(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;
	Node* dummy = NULL;

	Node* newNode = NULL;
	int readData;

	//데이터를 입력 받는 과정 ////
	while (1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);

		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		// 내가 Q4.1에서 수정한 코든
		if (head == NULL)
		{
			dummy->data = "DMY";
			dummy->next = newNode;
			head->next = dummy;
		}
		else
			tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	//입력 받은 데이터의 출력과정 ////
	printf("입력 받은 데이터의 전체 출력! \n");
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}

	printf("\n\n");

	//메모리의 해제과정 ////
	if (head == NULL)
	{
		return 0;
	} 
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d을(를) 삭제합니다. \n", head->data);

		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}

	

	

}