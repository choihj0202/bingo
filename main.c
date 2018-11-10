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
	int num_Me;
	int num_Com;
	
	initiate_bingo(user, com);
	print_bingo(user, com);
	get_number_byMe(num_Me);
	get_number_byCom(num_Com);
	
	return 0;
}
