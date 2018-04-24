#include <stdio.h>
#include <stdlib.h>

// ������ ���� �ڷᱸ���� ��� ����
typedef struct _NODE
{
	int Data;
	struct _NODE *Next;
} NODE;

NODE *head, *end;
NODE *ptrNode;

void InitializeStack(void);		// ���� �ʱ�ȭ �Լ�
void Push(int);					// ������ ����
int Pop(void);					// ������ ����
void DisplayStack(void);		// ������ ������

void InitializeStack(void)
{
	head = (NODE *)malloc(sizeof(NODE));
	end = (NODE *)malloc(sizeof(NODE));
	head->Next = end;
	end->Next = end;
}

void Push(int num)
{
	ptrNode = (NODE *)malloc(sizeof(NODE));
	ptrNode->Data = num;
	ptrNode->Next = head->Next;
	head->Next = ptrNode;
}

int Pop(void)
{
	int ret;
	ptrNode = head->Next;
	head->Next = head->Next->Next;
	ret = ptrNode->Data;
	free(ptrNode);

	return ret;
}

void DisplayStack(void)
{
	NODE *indexNode;
	printf("head -> ");

	for (indexNode = head->Next; indexNode != end; indexNode = indexNode->Next)
		printf("%d -> ", indexNode->Data);

	printf("end\n");
}
int main()
{
	int nInput = 0;
	int chk = 0;
	int PushData = 0;

	InitializeStack();

	puts("-----Stack-----");
	puts("1. Push");
	puts("2. Pop");
	puts("3. DisplayStack");
	puts("Other. Quit");
	puts("---------------");
	
	while (chk == 0)
	{
		printf("Insert : ");
		scanf("%d", &nInput);
		
		switch (nInput)
		{
		case 1:
			printf("Push : ");
			scanf("%d", &PushData);
			Push(PushData);
			break;
		case 2:
			printf("Pop : %d\n",Pop());
			break;
		case 3:
			DisplayStack();
			break;
		default:
			chk = 1;
			break;
		}
	}

	return 0;
}