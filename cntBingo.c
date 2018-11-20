#include <stdio.h>
#include <time.h>

#define N 5
#define M 1

// ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ�ϴ� �Լ�
int count_bingo(int bingo5[N][N])
{
	int i, j;
	int garo;	// ������ -1 ������ ��� ���� ����  
	int sero;	// ������ -1 ������ ��� ���� ����
	int daegak;	// �밢���� -1 ������ ��� ���� ����
	int count = 0;	// ������ ������ ���� ���� ����  
	
	// ���� ���� �� ���  
	for (i=0; i<N; i++)
	{
		garo = 0;	// ���� ����� �ϳ��� ���� �����ϰ� ���� ���� ���ؾ��ϹǷ� i�� ���� �ݺ��� ������ �ʱ�ȭ  
		
		for (j=0; j<N; j++)
		{
			if (bingo5[i][j] == -1)	  // ������ -1 ������ Ȯ�� 
				garo++;
		}
				
		if (garo == N)	// ���� ���� �ϼ��Ǹ� +1�� ��
			count++;
	}
	
	// ���� ���� �� ���
	for (j=0; j<N; j++)
	{
		sero = 0;	// ���� ����� �ϳ��� ���� �����ϰ� ���� ���� ���ؾ��ϹǷ� j�� ���� �ݺ��� ������ �ʱ�ȭ
		
		for (i=0; i<N; i++)
		{
			if (bingo5[i][j] == -1)	// ������ -1 ������ Ȯ��
				sero++;
		}		
			
		if (sero == N)	// ���� ���� �ϼ��Ǹ� +1�� ��
			count++; 
		
	}
	
	// �밢�� ���� �� ���  
	daegak = 0;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{	
			if (i == j)	// �� �밢�� �� '\' �밢���� �ش��� ��   
			{
				if (bingo5[i][j] == -1)	// '\' �밢���� -1 ������ Ȯ��  
					daegak++;
					
				if (daegak == N)	// '\' �밢�� ���� �ϼ��Ǹ� +1�� ��
					count++;
			}
			
			else if (i+j == N-1)	// �� �밢�� �� '/' �밢���� �ش��� ��
			{
				if (bingo5[i][j] == -1)	// '/' �밢���� -1 ������ Ȯ��  
					daegak++;
					
				if (daegak == N)	// '/' �밢�� ���� �ϼ��Ǹ� +1�� ��
					count++;
			}
		}
	} 
	
	return count;
}

int win_bingo(int bingo6[N][N], int bingo7[N][N])
{
	int finish;
	
	// user�� ������� M�� ���� ������Ű�� user �� 
	if ((count_bingo(bingo6) >= M) && (count_bingo(bingo6) > count_bingo(bingo7)))	 
	{
		printf("\n ## USER�� �̰���ϴ�! \n");
		finish = 0;
	}	
	
	// computer�� ������� M�� ���� ������Ű�� computer ��
	else if ((count_bingo(bingo7) >= M) && (count_bingo(bingo7) > count_bingo(bingo6)))
	{
		printf("\n ## COMPUTER�� �̰���ϴ�! \n");
		finish = 0;
	}
		
	// user�� computer�� ���ÿ� ������� M�� ������Ű�� ���º�
	else if ((count_bingo(bingo6) >= M) && (count_bingo(bingo7) >= M))	  
	{
		printf("\n ## �����ϴ�! \n");
		finish = 0;
	}
	
	else
		finish = 1;
	
	return finish;
}
