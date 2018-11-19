#include <stdio.h>
#include <time.h>

#define N 5

// 내가 빙고 번호를 입력 및 선택하는 함수
int get_number_byMe(int bingo4[N][N])
{
	int i, j;
	int num_Me;
	int max = N*N;
	 
	while (1) 
	{
		printf("## 번호를 입력하세요 : ");	// user가 번호 입력  
		scanf("%d", &num_Me);
		printf("\n");
		
		if ((num_Me > 0) && (num_Me < max+1))
		{
			for (i=0; i<max; i++)
			{
				for (j=0; j<max; j++)
				{
					if (bingo4[i][j] == num_Me)
						return num_Me;
				}
			}
		}	 
		
		else if ((num_Me < 0) && (num_Me > max))	// 범위 밖의 번호를 입력했을 때  
			printf(" ## 1 ~ %d 의 번호만 입력할 수 있습니다.\n", max);
			
		else 
			printf(" ## 이미 입력한 번호입니다.\n\n");
	}
}

// 컴퓨터가 임의로 빙고 번호를 선택하는 함수
int get_number_byCom(int bingo5[N][N])
{
	int i, j;
	int num_Com;
/*	int same_num;*/
	int max = N*N;
	
	while (1) 
	{	
		/*same_num = 0;*/
		num_Com = 1+rand()%max;
	
		for (i=0; i<max; i++)
		{
			if (bingo5[i][j] == num_Com)
				return num_Com;
		}	
		/* if (same_num)
			break;*/
	}	
	printf("\n ## 컴퓨터는 %d 을(를) 선택했습니다.\n", num_Com);

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
			if (bingo6[i][j] == num)
				bingo6[i][j] = -1;		
		}
	}	
	return bingo6[i][j];
}
