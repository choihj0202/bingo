#include <time.h>

#define N 4

void initiate_bingo()	// ���� ���̺��� �ʱ⿡ �������
{
	int ROWS, COLS;
	int i, j;
	int max = N*N;
	
	srand((unsigned) time(NULL));
	for (i=0; i<ROWS; i++)
	{
		for (j=0; j<COLS; j++)
		{
			printf("%d", 1+rand()%max);
		}
		printf("\n");
	}
	
	return;
}

void print_bingo()		// ���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���  
{
	return;
}
