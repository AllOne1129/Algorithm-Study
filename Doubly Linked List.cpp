#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
	char Data;
	struct _NODE *Next;
	struct _NODE *Prev;
} NODE;

NODE *head, *end, *temp;
NODE *temp1, *temp2, *temp3, *temp4;

void Initialize(void);
void InsertNode(NODE *);
void DeleteNode(NODE *);

void Initialize(void)
{
	NODE *ptr;
	head = (NODE *)malloc(sizeof(NODE));
	end = (NODE *)malloc(sizeof(NODE));

	temp1 = (NODE *)malloc(sizeof(NODE));
	temp1->Data = 'A';
	head->Next = temp1;
	temp1->Next = end;
	temp1->Prev = head;
	end->Next = end;
	ptr = temp1;

	temp2 = (NODE *)malloc(sizeof(NODE));
	temp2->Data = 'B';
	ptr->Next = temp2;
	temp2->Next = end;
	temp2->Prev = ptr;
	ptr = temp2;

	temp3 = (NODE *)malloc(sizeof(NODE));
	temp3->Data = 'D';
	ptr->Next = temp3;
	temp3->Next = end;
	temp3->Prev = ptr;
	ptr = temp3;

	temp4 = (NODE *)malloc(sizeof(NODE));
	temp4->Data = 'E';
	ptr->Next = temp4;
	temp4->Next = end;
	temp4->Prev = ptr;
	ptr = temp4;
}

void InsertNode(NODE *ptr)
{
	NODE *indexptr;
	for (indexptr = head->Next; indexptr != end; indexptr = indexptr->Next)
		if (indexptr->Data < ptr->Data && indexptr->Next->Data > ptr->Data)
			break;

	ptr->Next = indexptr->Next;
	indexptr->Next->Prev = ptr;
	indexptr->Next = ptr;
	ptr->Prev = indexptr;
}

void DeleteNode(NODE *ptr)
{
	NODE *indexptr;
	NODE *deleteptr;

	for (indexptr = head->Next; indexptr != end; indexptr = indexptr->Next)
	{
		if (indexptr->Next->Data == ptr->Data)
		{
			deleteptr = indexptr->Next;
			break;
		}
	}

	indexptr->Next = indexptr->Next->Next;
	indexptr->Next->Next->Prev = indexptr;
	free(deleteptr);
}

int main()
{
	NODE *ptr;
	int i = 0;
	Initialize();

	printf("노드 C의 삽입 전\n");
	ptr = head->Next;

	for (i = 0; i < 4; i++)
	{
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	temp = (NODE *)malloc(sizeof(NODE));
	temp->Data = 'C';

	InsertNode(temp);

	printf("\n노드 C의 삽입 후\n");
	ptr = head->Next;

	for (i = 0; i < 5; i++)
	{
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	DeleteNode(temp);

	printf("\n노드 C의 삭제 후\n");
	ptr = head->Next;

	for (i = 0; i < 4; i++)
	{
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	return 0;
}