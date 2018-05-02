#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
	int nData;
	struct _NODE *Next;
} Node;

void InitializeQueue(void);
void Put(int);
void Get(void);
void DisplayQueue(void);

Node *Front, *Rear;
Node *ptrNode;

void InitializeQueue(void)
{
	Front = (Node *)malloc(sizeof(Node));
	Rear = (Node *)malloc(sizeof(Node));
	
	Front->Next = Rear;
	Rear->Next = Front;
}

void Put(int num)
{
	ptrNode = (Node *)malloc(sizeof(Node));
	ptrNode->nData = num;
	
	if (Front->Next == Rear)
	{
		ptrNode->Next = Rear;
		Front->Next = ptrNode;
		Rear->Next = ptrNode;
	}
	else
	{
		Rear->Next->Next = ptrNode;
		ptrNode->Next = Rear;
		Rear->Next = ptrNode;
	}
}

void Get(void)
{
	int ret;
	Node *deleteNode;

	if (Front->Next == Rear)
		puts("Queue Empty");

	else
	{
		deleteNode = Front->Next;
		Front->Next = deleteNode->Next;
		ret = deleteNode->nData;
		printf("Get : %d\n", ret);

		free(deleteNode);
	}
}

void DisplayQueue(void)
{
	Node *indexptr;

	if (Front->Next == Rear)
		puts("Queue Empty");
	else
	{
		printf("Front ->");
		for (indexptr = Front->Next; indexptr != Rear; indexptr = indexptr->Next)
			printf(" %2d ->", indexptr->nData);
		printf(" Rear\n");
	}
}

int main()
{
	int nInput = 0;
	int chk = 0;
	int PutData = 0;

	InitializeQueue();

	puts("-----Queue-----");
	puts("1. Put");
	puts("2. Get");
	puts("3. DisplayQueue");
	puts("Other. Quit");
	puts("---------------");

	while (chk == 0)
	{
		printf("Insert : ");
		scanf("%d", &nInput);

		switch (nInput)
		{
		case 1:
			printf("Put : ");
			scanf("%d", &PutData);
			Put(PutData);
			break;
		case 2:
			Get();
			break;
		case 3:
			DisplayQueue();
			break;
		default:
			chk = 1;
			break;
		}
	}

	return 0;
}