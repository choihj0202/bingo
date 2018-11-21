#include <stdio.h>
#include <time.h>

#define N 5

// 내가 빙고 번호를 입력 및 선택하는 함수
int get_number_byMe(int bingo4[N][N])
{
	int i, j;
	int num_Me;	// user가 입력하는 번호에 대한 변수 선언  
	int max = N*N;
	 
	while (1) 
	{
		printf(" ## 번호를 입력하세요 : ");	// user가 번호 입력  
		scanf("%d", &num_Me);
		printf("\n");
		
		if ((num_Me > 0) && (num_Me < max+1))	// 범위 내의 번호를 입력했을 때  
		{
			for (i=0; i<N; i++)
			{
				for (j=0; j<N; j++)
				{
					if (bingo4[i][j] == num_Me)	// 만약 내가 입력한 번호가 빙고 테이블에 있으면 그 번호를 반환  
					{
						return num_Me;
					}
				}
			}
			
			printf(" ** 이미 입력한 번호입니다.\n\n");	// 범위 내의 번호를 입력했지만 이미 입력한 번호일 경우  
		}	 
		
		else if ((num_Me < 0) || (num_Me > max))	// 범위 밖의 번호를 입력했을 때  
			printf(" ** 1 ~ %d 의 번호만 입력할 수 있습니다.\n\n", max);
		
	}
}

// 컴퓨터가 임의로 빙고 번호를 선택하는 함수
int get_number_byCom(int bingo5[N][N], int num)
{
	int i, j;
	int num_Com;	// 컴퓨터가 임의로 선택하는 번호에 대한 변수 선언  
	int max = N*N;
	
	while (1) 
	{	
		num_Com = 1+rand()%max;	// 컴퓨터가 선택하는 번호 랜덤화  
	
		for (i=0; i<max; i++)
		{
			for (j=0; j<max; j++)
			{
				if (num == num_Com)	// user가 이미 입력한 번호를 입력하면 break (메인함수에서 num 자리에 user가 입력한 번호의 변수가 들어감)
					break;
					
				else if (bingo5[i][j] == -1)	// 이미 빙고 테이블에 -1이 적혀있으면, 즉 중복된 번호를 입력했으면 break 
					break;
				
				else if (bingo5[i][j] == num_Com)	// 알맞게 입력한 경우 그 번호 반환  
				{
					printf("\n ## 컴퓨터는 %d 을(를) 선택했습니다.\n\n", num_Com);
					return num_Com;
				}
			}
		}	
	}	
	
	return 0;
}

// 선택된 숫자를 입력 받아서 빙고 테이블 칸을 채우는 함수
int process_bingo(int bingo6[N][N], int num)
{
	int i, j; 
	int max = N*N;

	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (bingo6[i][j] == num)	// 빙고 테이블에서 선택된 번호는 -1로 바뀌고 그 수를 반환  
				bingo6[i][j] = -1;
		}
	}	
	return bingo6[i][j];
}
