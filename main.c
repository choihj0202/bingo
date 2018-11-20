#include <stdio.h>
#include <stdlib.h>
#include "prtBingo.h"
#include "procBingo.h"
#include "cntBingo.h"

#define N 5
#define M 1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	printf("\n ##### B I N G O #####\n"); 
	printf("\n ## 먼저 빙고 %d 개를 완성하면 승리!\n\n", M); 
	
	int user_bingo[N][N];
	int com_bingo[N][N];
	int num_Me;
	int num_Com;
	int turn = 1;
	int count;
	int finish;

	srand((unsigned) time(NULL));
	
	initiate_bingo(user_bingo);
	initiate_bingo(com_bingo);
	
	print_bingo(user_bingo);
	print_bingo(com_bingo);
	
	printf(" # 현재 %d 턴\n\n ", turn); 
	
	do 
	{
		// user의 빙고 테이블에 대한 코드  
		num_Me = get_number_byMe(user_bingo);
		process_bingo(user_bingo, num_Me);
		process_bingo(com_bingo, num_Me);
		print_bingo(user_bingo);
		print_bingo(com_bingo);
		turn++;
		count = count_bingo(user_bingo);
		printf(" ## %d 빙고 완성!\n ", count);
		finish = win_bingo(user_bingo, com_bingo);
		
		
		if (finish == 0)
			break;
		
		printf("\n # 현재 %d 턴\n", turn);
		
		// computer의 빙고 테이블에 대한 코드  
		num_Com = get_number_byCom(com_bingo, num_Me);
		process_bingo(user_bingo, num_Com);
		process_bingo(com_bingo, num_Com);
		print_bingo(user_bingo);
		print_bingo(com_bingo);
		turn++;
		count = count_bingo(com_bingo);
		printf(" ## %d 빙고 완성!\n ", count);
		finish = win_bingo(user_bingo, com_bingo);
		
		if (finish == 0)
			break;
			
		printf("\n # 현재 %d 턴\n", turn);
		
		printf("\n");

	} while (finish);
	
	printf("\n ### 총 %d 턴\n", turn-1, count);

	return 0;
}
