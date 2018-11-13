#include <stdio.h>
#include <time.h>

#define N 5

// 내가 빙고 번호를 입력 및 선택하는 함수
void get_number_byMe(int num_Me[])
{
	int max = N*N;
	 
	do {
		printf("\n ## 번호를 입력하세요 : ");
		scanf("%d", &num_Me);
	
		if ((num_Me < 1) || (num_Me > max))
			printf("\n ## 잘못 입력하셨습니다!\n"); 
			
	} while ((num_Me < 1) || (num_Me > max));
	
}	

// 컴퓨터가 임의로 빙고 번호를 선택하는 함수
void get_number_byCom(int num_Com[])
{
	int i, j;
	int same_num;
	int max = N*N;
	
	do {	
		same_num = 0;
		num_Com[i] = 1+rand()%max;
	
		for (j=0; j<i; j++)
		{
			if (num_Com[j] == num_Com[i])
				same_num = 1;
		}
	} while (same_num);
	
	printf("\n ## 컴퓨터는 %d 를 선택했습니다.", num_Com);
}

// 선택된 숫자를 입력 받아서 빙고 테이블 칸을 채우는 함수
void process_bingo(int num_Me[], int num_Com[])
{
	int i, j; 
	int user[N][N], com[N][N];
	
	get_number_byMe(num_Me);
	get_number_byCom(num_Com);
	
	if (num_Me == user[i][j])
	{
		user[i][j] = -1; 
	}	
	else if (num_Com == com[i][j])
	{
		com[i][j] = -1;
	}	
	
}
