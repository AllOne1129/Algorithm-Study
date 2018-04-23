#include <stdio.h>

int Push(int *pnData, int nData)
{
	if (nData >= 500)
	{
		puts("Overflow!!");
		return 0;
	}

	if (nData == 0)
		printf("%dst ", nData + 1);
	else if (nData == 1)
		printf("%dnd ", nData + 1);
	else if (nData == 2)
		printf("%drd ", nData + 1);
	else
		printf("%dth ", nData + 1);

	printf("Push Data Input : ");
	scanf("%d", pnData + nData);
	return 0;
}

int Pop(int *pnData, int nData)
{
	if (nData < 0)
	{
		puts("Underflow!!");
		return 0;
	}

	if (nData == 0)
		printf("%dst ", nData + 1);
	else if (nData == 1)
		printf("%dnd ", nData + 1);
	else if (nData == 2)
		printf("%drd ", nData + 1);
	else
		printf("%dth ", nData + 1);

	printf("Pop Data : %d\n", *(pnData + nData));
	return 0;
}

int main()
{
	int nInput;
	int nArray[500] = { 0, };
	int nPos = 0;

	printf("----Stack----\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Count\n");
	printf("Other. exit\n");
	printf("-------------\n");

	while (1)
	{
		printf("Select : ");
		scanf("%d", &nInput);

		switch (nInput)
		{
		case 1:
			Push(nArray, nPos);
			nPos++;
			break;
		case 2:
			nPos--;
			Pop(nArray, nPos);
			break;
		case 3:
			printf("Stack size : %d\n", nPos);
			break;
		default:
			goto End;
		}
	}
End:

	return 0;
}