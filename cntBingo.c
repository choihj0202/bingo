#include <stdio.h>
#include <time.h>

#define N 5
#define M 2

// 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환하는 함수
int count_bingo(int bingo7[N][N])
{
	int i, j;
	int garo;	// 가로의 -1 개수를 담는 변수 선언  
	int sero;	// 세로의 -1 개수를 담는 변수 선언
	int daegak1 = 0;	// '\' 대각선의 -1 개수를 담는 변수 선언, 0으로 초기화	 
	int daegak2 = 0;	// '/' 대각선의 -1 개수를 담는 변수 선언, 0으로 초기화  
	int count = 0;	// 빙고의 개수를 세는 변수 선언, 0으로 초기화  
	
	// 가로 빙고 수 계산  
	for (i=0; i<N; i++)
	{
		garo = 0;	// 가로 빙고는 하나의 행을 고정하고 열의 값을 비교해야하므로 i에 대해 반복할 때마다 0으로 초기화  
		
		for (j=0; j<N; j++)
		{
			if (bingo7[i][j] == -1)	  // 가로의 -1 개수를 확인 
				garo++;
		}
				
		if (garo == N)	// 가로 빙고가 완성되면 빙고 수 +1
			count++;
	}
	
	// 세로 빙고 수 계산
	for (j=0; j<N; j++)
	{
		sero = 0;	// 세로 빙고는 하나의 열을 고정하고 행의 값을 비교해야하므로 j에 대해 반복할 때마다 0으로 초기화
		
		for (i=0; i<N; i++)
		{
			if (bingo7[i][j] == -1)	// 세로의 -1 개수를 확인
				sero++;
		}		
			
		if (sero == N)	// 세로 빙고가 완성되면 빙고 수 +1
			count++; 
	}
	
	// 대각선 빙고 수 계산  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{	
			if (i == j)	// 두 대각선 중 '\' 대각선에 해당할 때   
			{
				if (bingo7[i][j] == -1)	// '\' 대각선의 -1 개수를 확인  
					daegak1++;
					
				if (daegak1 == N)	// '\' 대각선 빙고가 완성되면 빙고 수 +1
					count++;
			}
			
			if ((i + j) == (N-1))	// 두 대각선 중 '/' 대각선에 해당할 때
			{
				if (bingo7[i][j] == -1)	// '/' 대각선의 -1 개수를 확인  
					daegak2++;
					
				if (daegak2 == N)	// '/' 대각선 빙고가 완성되면 빙고 수 +1
					count++;
			}
		}
	} 
	
	return count;	// 빙고 수로 반환  
}

// 우승 조건에 대한 함수  
int win_bingo(int bingo8[N][N], int bingo9[N][N])
{
	int finish;	// 메인 함수에서 승패가 가려져 while 문을 탈출하는 용도로 사용되는 변수  
	
	// user가 우승조건 M을 먼저 만족시키면 user 승 
	if ((count_bingo(bingo8) >= M) && (count_bingo(bingo8) > count_bingo(bingo9)))	 
	{
		printf("\n ## USER가 이겼습니다! \n");
		finish = 0;	// while 문을 탈출하도록 설정  
	}	
	
	// computer가 우승조건 M을 먼저 만족시키면 computer 승
	else if ((count_bingo(bingo9) >= M) && (count_bingo(bingo9) > count_bingo(bingo8)))
	{
		printf("\n ## COMPUTER가 이겼습니다! \n");
		finish = 0;	// while 문을 탈출하도록 설정 
	}
		
	// user와 computer가 동시에 우승조건 M을 만족시키면 무승부
	else if ((count_bingo(bingo8) >= M) && (count_bingo(bingo9) >= M))	  
	{
		printf("\n ## 비겼습니다! \n");
		finish = 0;	// while 문을 탈출하도록 설정 
	}
	
	else	// 승패가 가려지지 않으면 while 문 탈출 불가  
		finish = 1;
	
	return finish;	// 0 또는 1로 반환 
}
