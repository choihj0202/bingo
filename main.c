#include <stdio.h>
#include <stdlib.h>
#include "prtBingo.h"
#include "procBingo.h"
#include "cntBingo.h"

#define N 5
#define M 4

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int user[N][N];
	int com[N][N];
	int save_user[N*N];
	int save_com[N*N];
	int num_Me;
	int num_Com;

	initiate_bingo(user, com, save_user, save_com);
	print_bingo(user, com);
	process_bingo(&num_Me, &num_Com);
	count_bingo(user, com);
	
	return 0;
}
