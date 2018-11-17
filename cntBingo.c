#include <stdio.h>
#include <time.h>

#define N 5
#define M 4

// ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ�ϴ� �Լ�
int count_bingo(int user[N][N], int com[N][N])
{
	int i, j;
	int garo_user = 0, garo_com = 0;
	int sero_user = 0, sero_com = 0;
	int daegak_user = 0, daegak_com = 0;
	int count_user = 0, count_com = 0;
	int turn = 0;
	
	// ���� ���� �� ���  
	for (j=0; j<N; j++)
	{
		if (user[i][j] == -1)
		{
			garo_user++;
		}
		
		else if (com[i][j] == -1)
		{
			garo_com++;
		}
	}
	
	
	// ���� ���� �� ���  
	for (i=0; i<N; i++)
	{
		if (user[i][j] == -1)
		{
			sero_user++;
		}
		
		else if (com[i][j] == -1)
		{
			sero_com++;
		}
	}
	
	// �밢�� ���� �� ���  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (i == j)
			{
				if (user[i][j] == -1)
				{
					daegak_user++;
				}
				
				else if (com[i][j] == -1)
				{
					daegak_com++;
				}
			}
			
			else if (i+j == N)
			{
				if (user[i][j] == -1)
				{
					daegak_user++;
				}
				
				else if (com[i][j] == -1)
				{
					daegak_com++;
				}
			}
		}
	}
	
	count_user = garo_user + sero_user + daegak_user;
	count_com = garo_com + sero_com + daegak_com;
	
	if ((count_user == M) && (count_user > count_com))
	{
		printf(" ## USER�� �̰���ϴ�!	turn : %d\n", turn);
	}
	
	else if ((count_com == M) && (count_com > count_user))
	{
		printf(" ## COMPUTER�� �̰���ϴ�!	turn : %d\n", turn);
	}
	
	else if ((count_user == M) && (count_com == M))
	{
		printf(" ## �����ϴ�! turn : %d\n", turn);
	}
	
	return count_user;
}
