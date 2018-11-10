#include <stdio.h>
#include <time.h>

#define N 5

// �ʱ� ���� ���̺��� ����� �Լ�
void initiate_bingo(int user[N][N], int com[N][N])		  
{  
	int i, j;
	int temp;	// �迭�� ���Ŀ� �ӽ÷� ���Ǵ� ���� ����  
	int max = N*N;	// ������ �ִ� ������ �ʿ��� ���� ����  

	srand((unsigned) time(NULL));
	
	printf("\n ##### B I N G O #####\n");  
	
	// �ʱ� USER ���� ����  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			temp = 1+rand()%max;	// ���� temp�� ���� ������ �������� ���� 
			
			if (repeat(user, temp))	// �ߺ��� ���ڸ� ������ ��� �� �� ������ ���� �ٽ� ������   
				j--;
			else
				user[i][j] = temp;	// �ߺ����� ���� ��� �״�� �� ����  
		}
	}
	
	// �ʱ� COMPUTER ���� ����  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			temp = 1+rand()%max;	// ���� temp�� ���� ������ �������� ����  
			
			if (repeat(com, temp))	// �ߺ� ���ڸ� ������ ��� �� �� ������ ���� �ٽ� ������
				j--;
			else
				com[i][j] = temp;	// �ߺ����� ���� ��� �״�� �� ����  
		}
	}
}

// ���� ���̺� ���� ��Ȳ�� ȭ�鿡 ����ϴ� �Լ�  
void print_bingo(int user[N][N], int com[N][N])			 
{
	int i, j;
	
	// USER ���� ���  
	printf("\n [USER] \n");
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf(" %2d ", user[i][j]);	// ���ڸ� ���� ���� �����ϱ� ���� ��� �� �ڸ� ���� ����  
		}
		printf("\n");
	}
	printf("\n");
	
	// COMPUTER ���� ���  
	printf("\n [COMPUTER] \n");
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf(" %2d ", com[i][j]);	// ���ڸ� ���� ���� �����ϱ� ���� ��� �� �ڸ� ���� ����  
		}
		printf("\n");
	}
}

// �ߺ� ���� ����� ���� �Լ�
int repeat(int user[N][N], int temp)	// temp�� �迭�� ���Ŀ� �ӽ÷� ���Ǵ� ����  
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{	
			if (user[i][j] == temp)	// �ߺ��Ǵ� ���ڰ� ������ 1�� ��ȯ�Ͽ� �ߺ� ���θ� ������ Ȯ��  
				return 1;
		}
	}
	return 0;
}
