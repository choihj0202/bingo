#include <stdio.h>
#include <time.h>

#define N 5

// ���� ���� ��ȣ�� �Է� �� �����ϴ� �Լ�
int get_number_byMe(int bingo4[N][N])
{
	int i, j;
	int num_Me;
	int max = N*N;
	 
	while (1) 
	{
		printf("## ��ȣ�� �Է��ϼ��� : ");	// user�� ��ȣ �Է�  
		scanf("%d", &num_Me);
		printf("\n");
		
		if ((num_Me > 0) && (num_Me < max+1))
		{
			for (i=0; i<max; i++)
			{
				for (j=0; j<max; j++)
				{
					if (bingo4[i][j] == num_Me)
						return num_Me;
				}
			}
		}	 
		
		else if ((num_Me < 0) && (num_Me > max))	// ���� ���� ��ȣ�� �Է����� ��  
			printf(" ## 1 ~ %d �� ��ȣ�� �Է��� �� �ֽ��ϴ�.\n", max);
			
		else 
			printf(" ## �̹� �Է��� ��ȣ�Դϴ�.\n\n");
	}
}

// ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ�� �����ϴ� �Լ�
int get_number_byCom(int bingo5[N][N])
{
	int i, j;
	int num_Com;
/*	int same_num;*/
	int max = N*N;
	
	while (1) 
	{	
		/*same_num = 0;*/
		num_Com = 1+rand()%max;
	
		for (i=0; i<max; i++)
		{
			if (bingo5[i][j] == num_Com)
				return num_Com;
		}	
		/* if (same_num)
			break;*/
	}	
	printf("\n ## ��ǻ�ʹ� %d ��(��) �����߽��ϴ�.\n", num_Com);

	return 0;
}

// ���õ� ���ڸ� �Է� �޾Ƽ� ���� ���̺� ĭ�� ä��� �Լ�
int process_bingo(int bingo6[N][N], int num)
{
	int i, j; 
	int max = N*N;

	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (bingo6[i][j] == num)
				bingo6[i][j] = -1;		
		}
	}	
	return bingo6[i][j];
}
