#include <stdio.h>

int Put(int *pnData, int nData)
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

	printf("Put Data Input : ");
	scanf("%d", pnData + nData);
	return 0;
}

int Get(int *pnData, int nData)
{
	if (nData < 0)
	{
		puts("Underflow!!");
		return 0;
	}

	printf("Get Data : %d\n", *pnData);

	for (int i = 0; i < nData; i++)
		pnData[i] = pnData[i + 1];

	pnData[nData] = NULL;
	return 0;
}

int main()
{
	int nInput;
	int nArray[500] = { 0, };
	int nPos = 0;

	printf("----Queue----\n");
	printf("1. Put\n");
	printf("2. Get\n");
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
			Put(nArray, nPos);
			if (nPos <= 499)	nPos++;
			break;
		case 2:
			if (nPos >= 0)	nPos--;
			Get(nArray, nPos);
			if (nPos < 0)		nPos = 0;
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