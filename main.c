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
	printf("\n ## 먼저 빙고 %d 개를 완성하면 승리!\n\n", M);	// 완성해야할 빙고 수를 안내하는 문구 출력  
	
	int user_bingo[N][N];	// user의 빙고 테이블에 대한 변수 선언  
	int com_bingo[N][N];	// computer의 빙고 테이블에 대한 변수 선언 
	int num_Me;	// user가 입력하는 번호에 대한 변수 선언 
	int num_Com;	// computer가 임의로 선택하는 번호에 대한 변수 선언 
	int turn = 1;	// 턴 수에 대한 변수 선언, 1로 초기화  
	int count = 0;	// 빙고 수 계산에 대한 변수 선언  
	int finish;	// 승패가 가려짐과 while 문 탈출 여부를 결정하는 변수 선언  

	srand((unsigned) time(NULL));	// 난수 발생  
	
	initiate_bingo(user_bingo);	// user의 빙고 테이블 초기화 
	initiate_bingo(com_bingo);	// computer의 빙고 테이블 초기화  
	
	print_bingo(user_bingo);	// user의 현재 빙고 테이블 출력 
	print_bingo(com_bingo);	// computer의 현재 빙고 테이블 출력  
	
	printf(" # 현재 %d 턴\n\n ", turn); // 시작하는 턴이 1턴이라고 출력  
	
	do 
	{
		// user의 빙고 테이블에 대한 코드  
		num_Me = get_number_byMe(user_bingo);	// user의 번호를 받음  
		process_bingo(user_bingo, num_Me);	// 입력된 번호에 대해 user 빙고 번호를 -1로 바꿈 
		process_bingo(com_bingo, num_Me);	// 입력된 번호에 대해 computer 빙고 번호를 -1로 바꿈  
		print_bingo(user_bingo);	// 현재 user 빙고 출력  
		print_bingo(com_bingo);	// 현재 computer 빙고 출력  
		turn++;	// 턴 수 1 증가  
		count = count_bingo(user_bingo);	// user 빙고의 빙고 수 계산 
		printf(" ## %d 빙고 완성!\n ", count);	// 빙고 수 출력  
		finish = win_bingo(user_bingo, com_bingo);	// 승패가 가려졌는 지의 여부에 대한 값을 받음  
		
		if (finish == 0)	// 승패가 가려졌다면 while 문 탈출  
			break;
		
		printf("\n # 현재 %d 턴\n", turn);	// 턴 수 출력  
		
		// computer의 빙고 테이블에 대한 코드  
		num_Com = get_number_byCom(com_bingo, num_Me);	// computer의 번호를 받음
		process_bingo(user_bingo, num_Com);	// 입력된 번호에 대해 user 빙고 번호를 -1로 바꿈
		process_bingo(com_bingo, num_Com);	// 입력된 번호에 대해 computer 빙고 번호를 -1로 바꿈
		print_bingo(user_bingo);	// 현재 user 빙고 출력
		print_bingo(com_bingo);	// 현재 computer 빙고 출력
		turn++;	// 턴 수 1 증가
		count = count_bingo(user_bingo);	// user 빙고의 빙고 수 계산
		printf(" ## %d 빙고 완성!\n ", count);	// 빙고 수 출력
		finish = win_bingo(user_bingo, com_bingo);	// 승패가 가려졌는 지의 여부에 대한 값을 받음
		
		if (finish == 0)	// 승패가 가려졌다면 while 문 탈출
			break;
			
		printf("\n # 현재 %d 턴\n", turn);	// 턴 수 출력
		
		printf("\n");

	} while (finish);	// 승패가 가려질 때 까지 반복  
	
	printf("\n ### 총 %d 턴\n", turn-1);	// 최종 턴 수 출력  

	return 0;
}
