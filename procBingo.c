#include <stdio.h>
#include <time.h>

#define N 5

// ���� ���� ��ȣ�� �Է� �� �����ϴ� �Լ�
void get_number_byMe(int num_Me[N*N])
{
	int i, j;
	int temp[N*N] = {0};
	int max = N*N;
	 
	do {
		printf("\n ## ��ȣ�� �Է��ϼ��� : ");
		scanf("%d", num_Me);
		
		if (wrong_num(&num_Me, temp))
			printf("\n ## �߸� �Է��ϼ̽��ϴ�.\n");
			
	} while (wrong_num(&num_Me, temp));
	
}	

int wrong_num(int num_Me[N*N], int temp)
{
	int i, j;
	int max = N*N;
	
	temp = 0;
	
	for (i=0; i<max; i++)
	{
		for (j=0; j<i; j++)
		{
			if ((num_Me[i] < 1) || (num_Me[i] > max))
			{
				num_Me[i] = temp;
				i--;
				return 1;
			}	
				
			else if (num_Me[j] == num_Me[i])
			{
				num_Me[j] = temp;
				i--;
				j--;
				return 1;
			}
		}	
	}
	
	return 0;
}

// ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ�� �����ϴ� �Լ�
void get_number_byCom(int num_Com[N*N])
{
	int i, j;
	int same_num;
	int max = N*N;
	
	do {	
		same_num = 0;
		num_Com[i] = 1+rand()%max;
	
		for (j=0; j<i; j++)
		{
			if (num_Com[j] == num_Com[i])
				same_num = 1;
		}
	} while (same_num);
	
	printf("\n ## ��ǻ�ʹ� %d ��(��) �����߽��ϴ�.", num_Com);
}

// ���õ� ���ڸ� �Է� �޾Ƽ� ���� ���̺� ĭ�� ä��� �Լ�
void process_bingo(int num_Me[N*N], int num_Com[N*N], int save_user[N*N], int save_com[N*N])
{
	int i, j; 
	int max = N*N;
	int user[N][N], com[N][N];
	
	get_number_byMe(num_Me);
	printf("1\n");
	get_number_byCom(num_Com);

	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if ((num_Me[max] == user[i][j]) && (num_Me[max] == com[i][j]))
			{
				user[i][j] = -1; 
				com[i][j] = -1;
			}	
				else if ((num_Com[max] == com[i][j]) && (num_Com[max] == user[i][j]))
			{
				user[i][j] = -1;
				com[i][j] = -1;
			}
		}
	}
		
	
	print_bingo(user, com);
}
