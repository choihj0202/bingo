#include <stdio.h>
#include <stdlib.h>
#include "prtBingo.h"
#include "procBingo.h"
#include "cntBingo.h"

#define N 5
#define M 1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	/*int user[N][N];
	int com[N][N];
	int check[N*N];
	int num_Me;
	int num_Com;
	int turn = 0;
	int finish;*/
	printf("\n ##### B I N G O #####\n"); 
	
	int user_bingo[N][N];
	int com_bingo[N][N];

	srand((unsigned) time(NULL));
	
	initiate_bingo(user_bingo);
	initiate_bingo(com_bingo);
	
	print_bingo(user_bingo);
	print_bingo(com_bingo);
	
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
