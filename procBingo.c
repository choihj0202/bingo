/*#include <stdio.h>
#include <time.h>

#define N 5

// ���� ���� ��ȣ�� �Է� �� �����ϴ� �Լ�
void get_number_byMe(int *bingo4[N*N])
{
	int i, j;
	int num_Me;
	int temp = 0;	// �迭�� ���Ŀ� �ӽ÷� ���Ǵ� ����(�迭) ����
	int max = N*N;
	 
	while (1) {
		printf("\n ## ��ȣ�� �Է��ϼ��� : ");	// user�� ��ȣ �Է�  
		scanf("%d", &num_Me);
		
		if ((num_Me < 1) || (num_Me > max))	// ���� ���� ��ȣ �Է� �� �Ʒ� ��Ʈ ���� �� ���Է��ϵ��� �� 
			printf("\n ## 1 ~ %d �� ��ȣ�� �Է��� �� �ֽ��ϴ�.\n", max);
		
		else	// �������� ���� ���� ��ȣ�� �Է����� ��   
		{
			for (i=0; i<max; i++)	// ���������� �Է��� ��  
			{
				for (j=0; j<max; j++)
				{
					
				}
				if (bingo[i] == num_Me)	// save�� ����� ��ȣ��� num_Me�� ����� ��ȣ�� ��ġ�ϸ�  
				{	
					check[i] = 1;	  
					break;	 
				}	 
						
			}
			
			if (check[i])	// temp=1�̸� �ߺ��� ������ ���ٴ� ���̹Ƿ� while�� Ż��  
			{
				printf("\n ## �̹� �Է��ϼ̽��ϴ�.\n");
				break;
			}	
				
			else	//  ��ġ���� �ʴٸ�, �� �̹� ������ ���ڸ� �Է��ߴٸ� �Ʒ� ���� ����  
			{	
				check[i] = 0;
				break;
			}		
		}
	}
	
	return;
}	

// ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ�� �����ϴ� �Լ�
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
	
	printf("\n ## ��ǻ�ʹ� %d ��(��) �����߽��ϴ�.\n", num_Com);
	
	return;
}

// ���õ� ���ڸ� �Է� �޾Ƽ� ���� ���̺� ĭ�� ä��� �Լ�
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
