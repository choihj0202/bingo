#include <stdio.h>
#include <time.h>

#define N 5
#define M 4

// 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환하는 함수
int count_bingo(int user[N][N], int com[N][N])
{
	int i, j;
	int garo_user = 0, garo_com = 0;
	int sero_user = 0, sero_com = 0;
	int daegak_user = 0, daegak_com = 0;
	int count_user = 0, count_com = 0;
	int turn = 0;
	
	// 가로 빙고 수 계산  
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
	
	
	// 세로 빙고 수 계산  
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
	
	// 대각선 빙고 수 계산  
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
		printf(" ## USER가 이겼습니다!	turn : %d\n", turn);
	}
	
	else if ((count_com == M) && (count_com > count_user))
	{
		printf(" ## COMPUTER가 이겼습니다!	turn : %d\n", turn);
	}
	
	else if ((count_user == M) && (count_com == M))
	{
		printf(" ## 비겼습니다! turn : %d\n", turn);
	}
	
	return count_user;
}
