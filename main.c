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
	printf("\n ## ���� ���� %d ���� �ϼ��ϸ� �¸�!\n\n", M); 
	
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
	
	printf(" # ���� %d ��\n\n ", turn); 
	
	do 
	{
		// user�� ���� ���̺� ���� �ڵ�  
		num_Me = get_number_byMe(user_bingo);
		process_bingo(user_bingo, num_Me);
		process_bingo(com_bingo, num_Me);
		print_bingo(user_bingo);
		print_bingo(com_bingo);
		turn++;
		count = count_bingo(user_bingo);
		printf(" ## %d ���� �ϼ�!\n ", count);
		finish = win_bingo(user_bingo, com_bingo);
		
		
		if (finish == 0)
			break;
		
		printf("\n # ���� %d ��\n", turn);
		
		// computer�� ���� ���̺� ���� �ڵ�  
		num_Com = get_number_byCom(com_bingo, num_Me);
		process_bingo(user_bingo, num_Com);
		process_bingo(com_bingo, num_Com);
		print_bingo(user_bingo);
		print_bingo(com_bingo);
		turn++;
		count = count_bingo(com_bingo);
		printf(" ## %d ���� �ϼ�!\n ", count);
		finish = win_bingo(user_bingo, com_bingo);
		
		if (finish == 0)
			break;
			
		printf("\n # ���� %d ��\n", turn);
		
		printf("\n");

	} while (finish);
	
	printf("\n ### �� %d ��\n", turn-1, count);

	return 0;
}
