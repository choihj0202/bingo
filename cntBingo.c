#include <stdio.h>
#include <time.h>

#define N 5
#define M 1

// 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환하는 함수
int count_bingo(int user[N][N], int com[N][N])
{
	int i, j;
	int garo_user = 0, garo_com = 0;
	int sero_user = 0, sero_com = 0;
	int daegak_user = 0, daegak_com = 0;
	int count_user = 0, count_com = 0;
	int finish;
	
	// 가로 빙고 수 계산  
	for (j=0; j<N; j++)
	{
		if (user[i][j] == -1)	// user의 가로 빙고가 완성되면 +1을 함  
		{
			garo_user++;
		}
		
		else if (com[i][j] == -1)	// computer의 가로 빙고가 완성되면 +1을 함  
		{
			garo_com++;
		}
	}
	
	
	// 세로 빙고 수 계산  
	for (i=0; i<N; i++)
	{
		if (user[i][j] == -1)	// user의 세로 빙고가 완성되면 +1을 함
		{
			sero_user++;
		}
		
		else if (com[i][j] == -1)	// computer의 세로 빙고가 완성되면 +1을 함
		{
			sero_com++;
		}
	}
	
	// 대각선 빙고 수 계산  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (i == j)	// 두 대각선 중 '\' 대각선에 해당할 때   
			{
				if (user[i][j] == -1)	// user의 '\' 대각선 빙고가 완성되면 +1을 함
				{
					daegak_user++;
				}
				
				else if (com[i][j] == -1)	// computer의 '\' 대각선 빙고가 완성되면 +1을 함
				{
					daegak_com++;
				}
			}
			
			else if (i+j == N)	// 두 대각선 중 '/' 대각선에 해당할 때
			{
				if (user[i][j] == -1)	// user의 '/' 대각선 빙고가 완성되면 +1을 함
				{
					daegak_user++;
				}
				
				else if (com[i][j] == -1)	// computer의 '/' 대각선 빙고가 완성되면 +1을 함
				{
					daegak_com++;
				}
			}
		}
	}
	
	count_user = garo_user + sero_user + daegak_user;	// user 빙고 테이블의 총 빙고 수를 계산  
	count_com = garo_com + sero_com + daegak_com;	// computer 빙고 테이블의 총 빙고 수를 계산  
	
	if ((count_user == M) && (count_user > count_com))	// user가 우승조건 M을 먼저 만족시키면 user 승  
	{
		printf(" ## USER가 이겼습니다! \n\n");
		finish = 0;
	}
	
	else if ((count_com == M) && (count_com > count_user))	// computer가 우승조건 M을 먼저 만족시키면 computer 승
	{
		printf(" ## COMPUTER가 이겼습니다! \n\n");
		finish = 0;
	}
	
	else if ((count_user == M) && (count_com == M))	// user와 computer가 동시에 우승조건 M을 만족시키면 무승부  
	{
		printf(" ## 비겼습니다! \n\n");
		finish = 0;
	}
	
	return count_user;
}
