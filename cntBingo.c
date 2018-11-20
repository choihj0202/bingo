#include <stdio.h>
#include <time.h>

#define N 5
#define M 2

// ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ�ϴ� �Լ�
int count_bingo(int bingo7[N][N])
{
	int i, j;
	int garo;	// ������ -1 ������ ��� ���� ����  
	int sero;	// ������ -1 ������ ��� ���� ����
	int daegak1 = 0;	// '\' �밢���� -1 ������ ��� ���� ����, 0���� �ʱ�ȭ	 
	int daegak2 = 0;	// '/' �밢���� -1 ������ ��� ���� ����, 0���� �ʱ�ȭ  
	int count = 0;	// ������ ������ ���� ���� ����, 0���� �ʱ�ȭ  
	
	// ���� ���� �� ���  
	for (i=0; i<N; i++)
	{
		garo = 0;	// ���� ����� �ϳ��� ���� �����ϰ� ���� ���� ���ؾ��ϹǷ� i�� ���� �ݺ��� ������ 0���� �ʱ�ȭ  
		
		for (j=0; j<N; j++)
		{
			if (bingo7[i][j] == -1)	  // ������ -1 ������ Ȯ�� 
				garo++;
		}
				
		if (garo == N)	// ���� ���� �ϼ��Ǹ� ���� �� +1
			count++;
	}
	
	// ���� ���� �� ���
	for (j=0; j<N; j++)
	{
		sero = 0;	// ���� ����� �ϳ��� ���� �����ϰ� ���� ���� ���ؾ��ϹǷ� j�� ���� �ݺ��� ������ 0���� �ʱ�ȭ
		
		for (i=0; i<N; i++)
		{
			if (bingo7[i][j] == -1)	// ������ -1 ������ Ȯ��
				sero++;
		}		
			
		if (sero == N)	// ���� ���� �ϼ��Ǹ� ���� �� +1
			count++; 
	}
	
	// �밢�� ���� �� ���  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{	
			if (i == j)	// �� �밢�� �� '\' �밢���� �ش��� ��   
			{
				if (bingo7[i][j] == -1)	// '\' �밢���� -1 ������ Ȯ��  
					daegak1++;
					
				if (daegak1 == N)	// '\' �밢�� ���� �ϼ��Ǹ� ���� �� +1
					count++;
			}
			
			if ((i + j) == (N-1))	// �� �밢�� �� '/' �밢���� �ش��� ��
			{
				if (bingo7[i][j] == -1)	// '/' �밢���� -1 ������ Ȯ��  
					daegak2++;
					
				if (daegak2 == N)	// '/' �밢�� ���� �ϼ��Ǹ� ���� �� +1
					count++;
			}
		}
	} 
	
	return count;	// ���� ���� ��ȯ  
}

// ��� ���ǿ� ���� �Լ�  
int win_bingo(int bingo8[N][N], int bingo9[N][N])
{
	int finish;	// ���� �Լ����� ���а� ������ while ���� Ż���ϴ� �뵵�� ���Ǵ� ����  
	
	// user�� ������� M�� ���� ������Ű�� user �� 
	if ((count_bingo(bingo8) >= M) && (count_bingo(bingo8) > count_bingo(bingo9)))	 
	{
		printf("\n ## USER�� �̰���ϴ�! \n");
		finish = 0;	// while ���� Ż���ϵ��� ����  
	}	
	
	// computer�� ������� M�� ���� ������Ű�� computer ��
	else if ((count_bingo(bingo9) >= M) && (count_bingo(bingo9) > count_bingo(bingo8)))
	{
		printf("\n ## COMPUTER�� �̰���ϴ�! \n");
		finish = 0;	// while ���� Ż���ϵ��� ���� 
	}
		
	// user�� computer�� ���ÿ� ������� M�� ������Ű�� ���º�
	else if ((count_bingo(bingo8) >= M) && (count_bingo(bingo9) >= M))	  
	{
		printf("\n ## �����ϴ�! \n");
		finish = 0;	// while ���� Ż���ϵ��� ���� 
	}
	
	else	// ���а� �������� ������ while �� Ż�� �Ұ�  
		finish = 1;
	
	return finish;	// 0 �Ǵ� 1�� ��ȯ 
}
