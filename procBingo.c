#include <stdio.h>
#include <time.h>

#define N 5

// 내가 빙고 번호를 입력 및 선택하는 함수
void get_number_byMe(int num_Me)
{
	printf("\n ## 번호를 입력하세요 : ");
	scanf("%d", &num_Me); 
} 

// 컴퓨터가 임의로 빙고 번호를 선택하는 함수
void get_number_byCom(int num_Com)
{
	int max = N*N;
	
	num_Com = 1+rand()%max;
	
	printf("\n ## 컴퓨터는 %d 를 선택했습니다.", num_Com);
}

// 선택된 숫자를 입력 받아서 빙고 테이블 칸을 채우는 함수
int process_bingo(); 
