#include <stdio.h>
#include <time.h>

#define N 5

// 초기 빙고 테이블을 만드는 함수
void initiate_bingo(int bingo[N][N])	// save에 빙고 테이블의 각 숫자를 저장 		  
{  
	int i, j;
	int temp;	// 중간에 임시로 사용되는 변수 선언  
	int max = N*N;	// 난수의 최댓값 설정에 필요한 변수 선언  
	  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			temp = 1+rand()%max;	// 정수 temp를 범위 내에서 랜덤으로 생성 
						
			if (repeat_number(bingo, temp))	// 중복된 숫자를 생성할 경우 한 열 앞으로 가서 다시 실행함   
				j--;
				
			else
				bingo[i][j] = temp;	// 중복되지 않을 경우 그대로 값 저장  
		}
	}
	
	return;
}

// 빙고 테이블 현재 상황을 화면에 출력하는 함수  
void print_bingo(int bingo2[N][N])
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf(" %4d ", bingo2[i][j]);	// 숫자를 보기 좋게 정렬하기 위해 모두 세 자리 수로 설정  
		}
		printf("\n");
	}
	printf("\n");
	
	return;
}

// 중복 숫자 출력을 막는 함수
int repeat_number(int bingo3[N][N], int temp)	// temp는 배열의 정렬에 임시로 사용되는 변수  
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{	
			if (bingo3[i][j] == temp)	// 중복되는 숫자가 있으면 1을 반환하여 위의 if 문에 활용하기 용이하도록 함   
				return 1;
		}
	}
	return 0;
}
