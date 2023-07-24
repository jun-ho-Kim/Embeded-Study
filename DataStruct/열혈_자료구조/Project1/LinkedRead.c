#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

//예제 4.1 

int main(void)
{
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node* newNode = NULL;
	int readData;

	while (1)
	{
		printf("자연수 입력 : ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		//노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));	// 노드의 생성
		newNode->data = readData;				// 노드의 데이터 저장
		newNode->next = NULL;					// 노드의 next를 NULL로 초기화

		if (head == NULL)	// 첫 번째 노드라면
			head = newNode;	// 첫 번째 노드를 head가 가르키게 함
		else				// 두 번째 이후 노드라면!
			tail->next = newNode;

		tail = newNode;		// 노드의 끝을 tail이 가리키게 함.
	}

	printf("\n");

	//입력 받은 데이터의 출력과정 //////
	printf("입력 받은 데이터의 전체 출력 \n");
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

	// 메모리의 해제과정 ////

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

		while (delNextNode != NULL) // 두 번째 이후 노드 삭제
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);// 첫 번째 노드 삭제
		}
	}

	return 0;
}