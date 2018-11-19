/*#include <stdio.h>
#include <time.h>

#define N 5

// 내가 빙고 번호를 입력 및 선택하는 함수
void get_number_byMe(int *bingo4[N*N])
{
	int i, j;
	int num_Me;
	int temp = 0;	// 배열의 정렬에 임시로 사용되는 변수(배열) 선언
	int max = N*N;
	 
	while (1) {
		printf("\n ## 번호를 입력하세요 : ");	// user가 번호 입력  
		scanf("%d", &num_Me);
		
		if ((num_Me < 1) || (num_Me > max))	// 범위 밖의 번호 입력 시 아래 멘트 실행 후 재입력하도록 함 
			printf("\n ## 1 ~ %d 의 번호만 입력할 수 있습니다.\n", max);
		
		else	// 정상적인 범위 내의 번호를 입력했을 때   
		{
			for (i=0; i<max; i++)	// 정상적으로 입력할 때  
			{
				for (j=0; j<max; j++)
				{
					
				}
				if (bingo[i] == num_Me)	// save에 저장된 번호들과 num_Me에 저장된 번호가 일치하면  
				{	
					check[i] = 1;	  
					break;	 
				}	 
						
			}
			
			if (check[i])	// temp=1이면 중복의 문제가 없다는 뜻이므로 while문 탈출  
			{
				printf("\n ## 이미 입력하셨습니다.\n");
				break;
			}	
				
			else	//  일치하지 않다면, 즉 이미 선택한 숫자를 입력했다면 아래 문장 실행  
			{	
				check[i] = 0;
				break;
			}		
		}
	}
	
	return;
}	

// 컴퓨터가 임의로 빙고 번호를 선택하는 함수
void get_number_byCom(int save_com[N*N], int check[N*N])
{
	int i, j;
	int num_Com;
	int same_num;
	int max = N*N;
	
	do {	
		same_num = 0;
		num_Com = 1+rand()%max;
	
		for (i=0; i<max; i++)
		{
			if (save_com[i] == num_Com)
				same_num = 1;
		}
		
		if (same_num)
			break;
			
	} while (1);
	
	printf("\n ## 컴퓨터는 %d 을(를) 선택했습니다.\n", num_Com);
	
	return;
}

// 선택된 숫자를 입력 받아서 빙고 테이블 칸을 채우는 함수
void process_bingo(int save_user[N*N], int save_com[N*N])
{
	int i, j; 
	int max = N*N;
	int num_Me, num_Com;

	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if ((save_user[i] == num_Me) && (save_user[i] == num_Com))
			{
				save_user[i] = -1; 
				save_com[i] = -1;
			}	
				else if ((save_com[i] == num_Me) && (save_com[i] == num_Com))
			{
				save_user[i] = -1; 
				save_com[i] = -1;
			}
		}
	}

	print_bingo(save_user, save_com);
	
	return;
}*/
