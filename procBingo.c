#include <stdio.h>
#include <time.h>

#define N 5

// ���� ���� ��ȣ�� �Է� �� �����ϴ� �Լ�
void get_number_byMe(int num_Me)
{
	printf("\n ## ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &num_Me); 
} 

// ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ�� �����ϴ� �Լ�
void get_number_byCom(int num_Com)
{
	int max = N*N;
	
	num_Com = 1+rand()%max;
	
	printf("\n ## ��ǻ�ʹ� %d �� �����߽��ϴ�.", num_Com);
}

// ���õ� ���ڸ� �Է� �޾Ƽ� ���� ���̺� ĭ�� ä��� �Լ�
int process_bingo(); 
