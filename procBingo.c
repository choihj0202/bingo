#include <stdio.h>
#include <time.h>

#define N 5

// ���� ���� ��ȣ�� �Է� �� �����ϴ� �Լ�
void get_number_byMe(int num_Me[])
{
	int max = N*N;
	 
	do {
		printf("\n ## ��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &num_Me);
	
		if ((num_Me < 1) || (num_Me > max))
			printf("\n ## �߸� �Է��ϼ̽��ϴ�!\n"); 
			
	} while ((num_Me < 1) || (num_Me > max));
	
}	

// ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ�� �����ϴ� �Լ�
void get_number_byCom(int num_Com[])
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
	
	printf("\n ## ��ǻ�ʹ� %d �� �����߽��ϴ�.", num_Com);
}

// ���õ� ���ڸ� �Է� �޾Ƽ� ���� ���̺� ĭ�� ä��� �Լ�
void process_bingo(int num_Me[], int num_Com[])
{
	int i, j; 
	int user[N][N], com[N][N];
	
	get_number_byMe(num_Me);
	get_number_byCom(num_Com);
	
	if (num_Me == user[i][j])
	{
		user[i][j] = -1; 
	}	
	else if (num_Com == com[i][j])
	{
		com[i][j] = -1;
	}	
	
}
