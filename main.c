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
	printf(" ## 먼저 빙고 %d 개를 완성하면 승리!\n", M); 
	
	int user_bingo[N][N];
	int com_bingo[N][N];
	int turn = 0;

	srand((unsigned) time(NULL));
	
	initiate_bingo(user_bingo);
	initiate_bingo(com_bingo);
	
	print_bingo(user_bingo);
	print_bingo(com_bingo);
	
	do 
	{
		get_number_byMe(user_bingo);
		print_bingo(user_bingo);
		turn++;
		
		get_number_byCom(com_bingo);
		print_bingo(com_bingo);
		turn++;
		
		break;
		
	} while (1);
	
	// user가 우승조건 M을 먼저 만족시키면 user 승 
	if ((count_bingo(user_bingo) == M) && (count_bingo(user_bingo) > count_bingo(com_bingo)))	 
		printf(" ## USER가 이겼습니다! \n\n");
	
	// computer가 우승조건 M을 먼저 만족시키면 computer 승
	else if ((count_bingo(com_bingo) == M) && (count_bingo(com_bingo) > count_bingo(user_bingo)))
		printf(" ## COMPUTER가 이겼습니다! \n\n");
	
	// user와 computer가 동시에 우승조건 M을 만족시키면 무승부
	else if ((count_bingo(user_bingo) == M) && (count_bingo(com_bingo) == M))	  
		printf(" ## 비겼습니다! \n\n");

	
/*	do {
	get_number_byMe(save_user, check);
	turn++;
	process_bingo(save_user, save_com);
	count_bingo(user, com);
	
	get_number_byCom(save_com);
	turn++;
	process_bingo(save_user, save_com);
	count_bingo(user, com);
	} while(!finish);*/
	
	return 0;
}
