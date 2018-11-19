#include <stdio.h>
#include <time.h>

#define N 5
#define M 1

// ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ�ϴ� �Լ�
int count_bingo(int bingo5[N][N])
{
	int i, j;
	int garo = 0;
	int sero = 0;
	int daegak = 0;
	int count = 0;
	int finish;
	
	// ���� ���� �� ���  
	for (j=0; j<N; j++)
	{
		if (bingo5[i][j] == -1)	// ���� ���� �ϼ��Ǹ� +1�� ��  
			garo++;
	}
	
	
	// ���� ���� �� ���  
	for (i=0; i<N; i++)
	{
		if (bingo5[i][j] == -1)	// ���� ���� �ϼ��Ǹ� +1�� ��
			sero++;
	}
	
	// �밢�� ���� �� ���  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (i == j)	// �� �밢�� �� '\' �밢���� �ش��� ��   
			{
				if (bingo5[i][j] == -1)	// '\' �밢�� ���� �ϼ��Ǹ� +1�� ��
					daegak++;
			}
			
			else if (i+j == N)	// �� �밢�� �� '/' �밢���� �ش��� ��
			{
				if (bingo5[i][j] == -1)	// '/' �밢�� ���� �ϼ��Ǹ� +1�� ��
					daegak++;
			}
		}
	}
	
	count = garo + sero + daegak;	// ���� ���̺��� �� ���� ���� ���  
	
	printf(" ## ���� ���� %d ��, ���� ���� %d ��, �밢�� ���� %d �� �ϼ� (�� %d ��)\n ", garo, sero, daegak, count);

	return count;
}
