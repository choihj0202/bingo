#include <stdio.h>
#include <time.h>

#define N 5
#define M 1

// 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환하는 함수
int count_bingo(int bingo5[N][N])
{
	int i, j;
	int garo = 0;
	int sero = 0;
	int daegak = 0;
	int count = 0;
	int finish;
	
	// 가로 빙고 수 계산  
	for (j=0; j<N; j++)
	{
		if (bingo5[i][j] == -1)	// 가로 빙고가 완성되면 +1을 함  
			garo++;
	}
	
	
	// 세로 빙고 수 계산  
	for (i=0; i<N; i++)
	{
		if (bingo5[i][j] == -1)	// 세로 빙고가 완성되면 +1을 함
			sero++;
	}
	
	// 대각선 빙고 수 계산  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (i == j)	// 두 대각선 중 '\' 대각선에 해당할 때   
			{
				if (bingo5[i][j] == -1)	// '\' 대각선 빙고가 완성되면 +1을 함
					daegak++;
			}
			
			else if (i+j == N)	// 두 대각선 중 '/' 대각선에 해당할 때
			{
				if (bingo5[i][j] == -1)	// '/' 대각선 빙고가 완성되면 +1을 함
					daegak++;
			}
		}
	}
	
	count = garo + sero + daegak;	// 빙고 테이블의 총 빙고 수를 계산  
	
	printf(" ## 가로 빙고 %d 개, 세로 빙고 %d 개, 대각선 빙고 %d 개 완성 (총 %d 개)\n ", garo, sero, daegak, count);

	return count;
}
