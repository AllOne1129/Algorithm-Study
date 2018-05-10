#include "node.h"

extern void InitializeStack(void);
extern void Push(NODE *);
extern NODE *Pop(void);
extern int IsStackEmpty(void);

void InitializeTree(void);
void MakeTree(void);
void Recursive_Traverse(NODE *);
void Stack_Traverse(NODE *);
void Visit(NODE *);

NODE *Parent, *LeftChild, *RightChild;
NODE *HeadNode, *EndNode;

void InitializeTree(void)
{
	HeadNode = (NODE *)malloc(sizeof(NODE));
	EndNode = (NODE *)malloc(sizeof(NODE));

	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;
}

void MakeTree(void)
{
	Parent = (NODE *)malloc(sizeof(NODE));
	Parent->Data = 'A';

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'B';

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'C';

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

	HeadNode->Left = Parent;
	HeadNode->Right = Parent;

	Parent = Parent->Left;

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'D';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'E';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
	Parent = HeadNode->Right->Right;

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'F';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'G';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
}

void Recursive_Traverse(NODE *ptrNode)
{
	if (ptrNode != EndNode)
	{
		Recursive_Traverse(ptrNode->Left);
		Recursive_Traverse(ptrNode->Right);
		Visit(ptrNode);
	}
}

void Stack_Traverse(NODE *ptrNode)
{
	int Finish = 0;
	NODE *ptrVisited = EndNode;
	NODE *ptrPushed = EndNode;
	do
	{
		while (ptrNode != EndNode&&ptrNode != ptrVisited)
		{
			if (ptrNode != ptrPushed)
				Push(ptrNode);

			if (ptrNode->Right != EndNode)
				Push(ptrNode->Right);

			if (ptrNode->Left != EndNode)
				Push(ptrNode->Left);
			
			ptrPushed = ptrNode->Left;
			ptrNode = ptrNode->Left;
		}

		if (!IsStackEmpty())
		{
			ptrNode = Pop();

			if (ptrNode->Left != EndNode && ptrNode->Right == EndNode && ptrNode->Left != ptrVisited)
			{
				Push(ptrNode);
				ptrNode = ptrNode->Left;
			}

			if (ptrNode->Right == EndNode || ptrNode->Right == ptrVisited)
			{
				Visit(ptrNode);
				ptrVisited = ptrNode;
			}
		}
		else
			Finish = 1;
	} while (!Finish);
}

void Visit(NODE *ptrNode)
{
	printf("%2c -> ", ptrNode->Data);
}

int main()
{
	InitializeStack();
	InitializeTree();
	MakeTree();

	printf("재귀 호출을 사용한 중위 순회 : ");
	Recursive_Traverse(HeadNode->Left);

	printf("\n스택을 사용한 중위 순회 : ");
	Stack_Traverse(HeadNode->Left);
	return 0;
}