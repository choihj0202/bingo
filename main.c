#include <stdio.h>
#include <stdlib.h>
#include "prtBingo.h"
#include "procBingo.h"
#include "cntBingo.h"

#define N 5
#define M 2

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	printf("\n ##### B I N G O #####\n"); 
	printf("\n ## ���� ���� %d ���� �ϼ��ϸ� �¸�!\n\n", M);	// �ϼ��ؾ��� ���� ���� �ȳ��ϴ� ���� ���  
	
	int user_bingo[N][N];	// user�� ���� ���̺� ���� ���� ����  
	int com_bingo[N][N];	// computer�� ���� ���̺� ���� ���� ���� 
	int num_Me;	// user�� �Է��ϴ� ��ȣ�� ���� ���� ���� 
	int num_Com;	// computer�� ���Ƿ� �����ϴ� ��ȣ�� ���� ���� ���� 
	int turn = 1;	// �� ���� ���� ���� ����, 1�� �ʱ�ȭ  
	int count = 0;	// ���� �� ��꿡 ���� ���� ����  
	int finish;	// ���а� �������� while �� Ż�� ���θ� �����ϴ� ���� ����  

	srand((unsigned) time(NULL));	// ���� �߻�  
	
	initiate_bingo(user_bingo);	// user�� ���� ���̺� �ʱ�ȭ 
	initiate_bingo(com_bingo);	// computer�� ���� ���̺� �ʱ�ȭ  
	
	print_bingo(user_bingo);	// user�� ���� ���� ���̺� ��� 
	print_bingo(com_bingo);	// computer�� ���� ���� ���̺� ���  
	
	printf(" # ���� %d ��\n\n ", turn); // �����ϴ� ���� 1���̶�� ���  
	
	do 
	{
		// user�� ���� ���̺� ���� �ڵ�  
		num_Me = get_number_byMe(user_bingo);	// user�� ��ȣ�� ����  
		process_bingo(user_bingo, num_Me);	// �Էµ� ��ȣ�� ���� user ���� ��ȣ�� -1�� �ٲ� 
		process_bingo(com_bingo, num_Me);	// �Էµ� ��ȣ�� ���� computer ���� ��ȣ�� -1�� �ٲ�  
		print_bingo(user_bingo);	// ���� user ���� ���  
		print_bingo(com_bingo);	// ���� computer ���� ���  
		turn++;	// �� �� 1 ����  
		count = count_bingo(user_bingo);	// user ������ ���� �� ��� 
		printf(" ## %d ���� �ϼ�!\n ", count);	// ���� �� ���  
		finish = win_bingo(user_bingo, com_bingo);	// ���а� �������� ���� ���ο� ���� ���� ����  
		
		if (finish == 0)	// ���а� �������ٸ� while �� Ż��  
			break;
		
		printf("\n # ���� %d ��\n", turn);	// �� �� ���  
		
		// computer�� ���� ���̺� ���� �ڵ�  
		num_Com = get_number_byCom(com_bingo, num_Me);	// computer�� ��ȣ�� ����
		process_bingo(user_bingo, num_Com);	// �Էµ� ��ȣ�� ���� user ���� ��ȣ�� -1�� �ٲ�
		process_bingo(com_bingo, num_Com);	// �Էµ� ��ȣ�� ���� computer ���� ��ȣ�� -1�� �ٲ�
		print_bingo(user_bingo);	// ���� user ���� ���
		print_bingo(com_bingo);	// ���� computer ���� ���
		turn++;	// �� �� 1 ����
		count = count_bingo(user_bingo);	// user ������ ���� �� ���
		printf(" ## %d ���� �ϼ�!\n ", count);	// ���� �� ���
		finish = win_bingo(user_bingo, com_bingo);	// ���а� �������� ���� ���ο� ���� ���� ����
		
		if (finish == 0)	// ���а� �������ٸ� while �� Ż��
			break;
			
		printf("\n # ���� %d ��\n", turn);	// �� �� ���
		
		printf("\n");

	} while (finish);	// ���а� ������ �� ���� �ݺ�  
	
	printf("\n ### �� %d ��\n", turn-1);	// ���� �� �� ���  

	return 0;
}
