#include <time.h>

#define N 4

void initiate_bingo()	// 빙고 테이블을 초기에 만들어줌
{
	int ROWS, COLS;
	int i, j;
	int max = N*N;
	
	srand((unsigned) time(NULL));
	for (i=0; i<ROWS; i++)
	{
		for (j=0; j<COLS; j++)
		{
			printf("%d", 1+rand()%max);
		}
		printf("\n");
	}
	
	return;
}

void print_bingo()		// 빙고 테이블 현재 상황을 화면에 출력  
{
	return;
}
