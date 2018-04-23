#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
	char Data;
	struct _NODE *Next;
	struct _NODE *Prev;
} NODE;

NODE *temp;
NODE *temp1, *temp2, *temp3, *temp4;

void Initialize(void);
void InsertNode(NODE *);
void DeleteNode(NODE *);

void Initialize(void)
{
	temp1 = (NODE*)malloc(sizeof(NODE));
	temp2 = (NODE*)malloc(sizeof(NODE));
	temp3 = (NODE*)malloc(sizeof(NODE));
	temp4 = (NODE*)malloc(sizeof(NODE));

	temp1->Next = temp2;
	temp2->Next = temp3;
	temp3->Next = temp4;
	temp4->Next = temp1;

	temp1->Prev = temp4;
	temp2->Prev = temp1;
	temp3->Prev = temp2;
	temp4->Prev = temp3;

	temp1->Data = 'A';
	temp2->Data = 'B';
	temp3->Data = 'D';
	temp4->Data = 'E';
}

void InsertNode(NODE *ptr)
{
	NODE *indexptr;

	for (indexptr = temp4->Next; ; indexptr = indexptr->Next)
	{
		if (indexptr->Data < ptr->Data && indexptr->Next->Data > ptr->Data)
			break;
	}

	ptr->Next = indexptr->Next;
	ptr->Prev = indexptr;
	indexptr->Next->Prev = ptr;
	indexptr->Next = ptr;
}

void DeleteNode(NODE *ptr)
{
	NODE *indexptr;
	NODE *deleteptr;

	for (indexptr = temp4->Next; ; indexptr = indexptr->Next)
	{
		if (ptr->Data == indexptr->Data)
			break;
	}

	indexptr->Next->Prev = indexptr->Prev;
	indexptr->Prev->Next = indexptr->Next;
	free(indexptr);
}

int main()
{
	NODE *ptr;
	int i = 0;
	Initialize();

	printf("노드 C의 삽입 전\n");
	ptr = temp4->Next;

	for (i = 0; i < 4; i++)
	{
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	temp = (NODE *)malloc(sizeof(NODE));
	temp->Data = 'C';

	InsertNode(temp);
	printf("\n노드 C의 삽입 후\n");
	ptr = temp4->Next;

	for (i = 0; i < 5; i++)
	{
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	DeleteNode(temp);

	printf("\n노드 C의 삭제 후\n");
	ptr = temp4->Next;

	for (i = 0; i < 4; i++)
	{
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	return 0;
}