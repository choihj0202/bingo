#include <stdio.h>
#include <time.h>

#define N 5
#define M 1

// 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환하는 함수
int count_bingo(int bingo5[N][N])
{
	int i, j;
	int garo;	// 가로의 -1 개수를 담는 변수 선언  
	int sero;	// 세로의 -1 개수를 담는 변수 선언
	int daegak;	// 대각선의 -1 개수를 담는 변수 선언
	int count = 0;	// 빙고의 개수를 세는 변수 선언  
	
	// 가로 빙고 수 계산  
	for (i=0; i<N; i++)
	{
		garo = 0;	// 가로 빙고는 하나의 행을 고정하고 열의 값을 비교해야하므로 i에 대해 반복할 때마다 초기화  
		
		for (j=0; j<N; j++)
		{
			if (bingo5[i][j] == -1)	  // 가로의 -1 개수를 확인 
				garo++;
		}
				
		if (garo == N)	// 가로 빙고가 완성되면 +1을 함
			count++;
	}
	
	// 세로 빙고 수 계산
	for (j=0; j<N; j++)
	{
		sero = 0;	// 세로 빙고는 하나의 열을 고정하고 행의 값을 비교해야하므로 j에 대해 반복할 때마다 초기화
		
		for (i=0; i<N; i++)
		{
			if (bingo5[i][j] == -1)	// 세로의 -1 개수를 확인
				sero++;
		}		
			
		if (sero == N)	// 세로 빙고가 완성되면 +1을 함
			count++; 
		
	}
	
	// 대각선 빙고 수 계산  
	daegak = 0;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{	
			if (i == j)	// 두 대각선 중 '\' 대각선에 해당할 때   
			{
				if (bingo5[i][j] == -1)	// '\' 대각선의 -1 개수를 확인  
					daegak++;
					
				if (daegak == N)	// '\' 대각선 빙고가 완성되면 +1을 함
					count++;
			}
			
			else if (i+j == N-1)	// 두 대각선 중 '/' 대각선에 해당할 때
			{
				if (bingo5[i][j] == -1)	// '/' 대각선의 -1 개수를 확인  
					daegak++;
					
				if (daegak == N)	// '/' 대각선 빙고가 완성되면 +1을 함
					count++;
			}
		}
	} 
	
	return count;
}

int win_bingo(int bingo6[N][N], int bingo7[N][N])
{
	int finish;
	
	// user가 우승조건 M을 먼저 만족시키면 user 승 
	if ((count_bingo(bingo6) >= M) && (count_bingo(bingo6) > count_bingo(bingo7)))	 
	{
		printf("\n ## USER가 이겼습니다! \n");
		finish = 0;
	}	
	
	// computer가 우승조건 M을 먼저 만족시키면 computer 승
	else if ((count_bingo(bingo7) >= M) && (count_bingo(bingo7) > count_bingo(bingo6)))
	{
		printf("\n ## COMPUTER가 이겼습니다! \n");
		finish = 0;
	}
		
	// user와 computer가 동시에 우승조건 M을 만족시키면 무승부
	else if ((count_bingo(bingo6) >= M) && (count_bingo(bingo7) >= M))	  
	{
		printf("\n ## 비겼습니다! \n");
		finish = 0;
	}
	
	else
		finish = 1;
	
	return finish;
}
