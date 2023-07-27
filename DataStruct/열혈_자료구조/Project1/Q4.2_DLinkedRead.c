#include <stdio.h>
#include <stdlib.h>

// ���� ��带 �߰��ϰ�, �׿� ���� �ڵ��� ��ȭ�� ���� Ȯ���ϱ�� �ϰڴ�.
// �� ������ ����Ʈ�� �����ٰ� ��带 �߰��ϴ� ������� head�� tail�� ��� �ʿ��ϴ�.

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

	head = (Node*)malloc(sizeof(Node));
	tail = head;

	//�����͸� �Է� �޴� ���� ////
	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);

		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		// ���� Q4.1���� ������ �ڵ�
		//if (head == NULL)
		//{
		//	dummy->data = "DMY";
		//	dummy->next = newNode;
		//	head->next = dummy;
		//}
		//else

		tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	//�Է� ���� �������� ��°��� ////
	printf("�Է� ���� �������� ��ü ���! \n");
	if (head == tail)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		cur = head;
		//printf("%d ", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}

	printf("\n\n");

	//�޸��� �������� ////
	if (head == tail)
	{
		return 0;
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		//printf("%d��(��) �����մϴ�. \n", head->data);
		//free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);
		}
	}
}