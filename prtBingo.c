#include <stdio.h>
#include <time.h>

#define N 5

// 초기 빙고 테이블을 만드는 함수
void initiate_bingo(int user[N][N], int com[N][N])		  
{  
	int i, j;
	int temp;	// 배열의 정렬에 임시로 사용되는 변수 선언  
	int max = N*N;	// 난수의 최댓값 설정에 필요한 변수 선언  

	srand((unsigned) time(NULL));
	
	printf("\n ##### B I N G O #####\n");  
	
	// 초기 USER 빙고 형성  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			temp = 1+rand()%max;	// 정수 temp를 범위 내에서 랜덤으로 생성 
			
			if (repeat(user, temp))	// 중복된 숫자를 생성할 경우 한 열 앞으로 가서 다시 실행함   
				j--;
			else
				user[i][j] = temp;	// 중복되지 않을 경우 그대로 값 저장  
		}
	}
	
	// 초기 COMPUTER 빙고 형성  
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			temp = 1+rand()%max;	// 정수 temp를 범위 내에서 랜덤으로 생성  
			
			if (repeat(com, temp))	// 중복 숫자를 생성할 경우 한 열 앞으로 가서 다시 실행함
				j--;
			else
				com[i][j] = temp;	// 중복되지 않을 경우 그대로 값 저장  
		}
	}
}

// 빙고 테이블 현재 상황을 화면에 출력하는 함수  
void print_bingo(int user[N][N], int com[N][N])			 
{
	int i, j;
	
	// USER 빙고 출력  
	printf("\n [USER] \n");
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf(" %2d ", user[i][j]);	// 숫자를 보기 좋게 정렬하기 위해 모두 두 자리 수로 설정  
		}
		printf("\n");
	}
	printf("\n");
	
	// COMPUTER 빙고 출력  
	printf("\n [COMPUTER] \n");
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf(" %2d ", com[i][j]);	// 숫자를 보기 좋게 정렬하기 위해 모두 두 자리 수로 설정  
		}
		printf("\n");
	}
}

// 중복 숫자 출력을 막는 함수
int repeat(int user[N][N], int temp)	// temp는 배열의 정렬에 임시로 사용되는 변수  
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{	
			if (user[i][j] == temp)	// 중복되는 숫자가 있으면 1을 반환하여 중복 여부를 참으로 확정  
				return 1;
		}
	}
	return 0;
}
