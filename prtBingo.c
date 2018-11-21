#include <stdio.h>
#include <time.h>

#define N 5

// �ʱ� ���� ���̺��� ����� �Լ�
void initiate_bingo(int bingo[N][N])	// save�� ���� ���̺��� �� ���ڸ� ���� 		  
{  
	int i, j;
	int temp;	// �߰��� �ӽ÷� ���Ǵ� ���� ����  
	int max = N*N;	// ������ �ִ� ������ �ʿ��� ���� ����  
	  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			temp = 1+rand()%max;	// ���� temp�� ���� ������ �������� ���� 
						
			if (repeat_number(bingo, temp))	// �ߺ��� ���ڸ� ������ ��� �� �� ������ ���� �ٽ� ������   
				j--;
				
			else
				bingo[i][j] = temp;	// �ߺ����� ���� ��� �״�� �� ����  
		}
	}
	
	return;
}

// ���� ���̺� ���� ��Ȳ�� ȭ�鿡 ����ϴ� �Լ�  
void print_bingo(int bingo2[N][N])
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf(" %4d ", bingo2[i][j]);	// ���ڸ� ���� ���� �����ϱ� ���� ��� �� �ڸ� ���� ����  
		}
		printf("\n");
	}
	printf("\n");
	
	return;
}

// �ߺ� ���� ����� ���� �Լ�
int repeat_number(int bingo3[N][N], int temp)	// temp�� �迭�� ���Ŀ� �ӽ÷� ���Ǵ� ����  
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{	
			if (bingo3[i][j] == temp)	// �ߺ��Ǵ� ���ڰ� ������ 1�� ��ȯ�Ͽ� ���� if ���� Ȱ���ϱ� �����ϵ��� ��   
				return 1;
		}
	}
	return 0;
}
