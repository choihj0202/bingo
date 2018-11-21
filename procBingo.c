#include <stdio.h>
#include <time.h>

#define N 5

// ���� ���� ��ȣ�� �Է� �� �����ϴ� �Լ�
int get_number_byMe(int bingo4[N][N])
{
	int i, j;
	int num_Me;	// user�� �Է��ϴ� ��ȣ�� ���� ���� ����  
	int max = N*N;
	 
	while (1) 
	{
		printf(" ## ��ȣ�� �Է��ϼ��� : ");	// user�� ��ȣ �Է�  
		scanf("%d", &num_Me);
		printf("\n");
		
		if ((num_Me > 0) && (num_Me < max+1))	// ���� ���� ��ȣ�� �Է����� ��  
		{
			for (i=0; i<N; i++)
			{
				for (j=0; j<N; j++)
				{
					if (bingo4[i][j] == num_Me)	// ���� ���� �Է��� ��ȣ�� ���� ���̺� ������ �� ��ȣ�� ��ȯ  
					{
						return num_Me;
					}
				}
			}
			
			printf(" ** �̹� �Է��� ��ȣ�Դϴ�.\n\n");	// ���� ���� ��ȣ�� �Է������� �̹� �Է��� ��ȣ�� ���  
		}	 
		
		else if ((num_Me < 0) || (num_Me > max))	// ���� ���� ��ȣ�� �Է����� ��  
			printf(" ** 1 ~ %d �� ��ȣ�� �Է��� �� �ֽ��ϴ�.\n\n", max);
		
	}
}

// ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ�� �����ϴ� �Լ�
int get_number_byCom(int bingo5[N][N], int num)
{
	int i, j;
	int num_Com;	// ��ǻ�Ͱ� ���Ƿ� �����ϴ� ��ȣ�� ���� ���� ����  
	int max = N*N;
	
	while (1) 
	{	
		num_Com = 1+rand()%max;	// ��ǻ�Ͱ� �����ϴ� ��ȣ ����ȭ  
	
		for (i=0; i<max; i++)
		{
			for (j=0; j<max; j++)
			{
				if (num == num_Com)	// user�� �̹� �Է��� ��ȣ�� �Է��ϸ� break (�����Լ����� num �ڸ��� user�� �Է��� ��ȣ�� ������ ��)
					break;
					
				else if (bingo5[i][j] == -1)	// �̹� ���� ���̺� -1�� ����������, �� �ߺ��� ��ȣ�� �Է������� break 
					break;
				
				else if (bingo5[i][j] == num_Com)	// �˸°� �Է��� ��� �� ��ȣ ��ȯ  
				{
					printf("\n ## ��ǻ�ʹ� %d ��(��) �����߽��ϴ�.\n\n", num_Com);
					return num_Com;
				}
			}
		}	
	}	
	
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
			if (bingo6[i][j] == num)	// ���� ���̺��� ���õ� ��ȣ�� -1�� �ٲ�� �� ���� ��ȯ  
				bingo6[i][j] = -1;
		}
	}	
	return bingo6[i][j];
}
