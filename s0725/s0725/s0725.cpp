// s0725.cpp : �������̨Ӧ�ó������ڵ㡣
/*question��������Am*n�е�ĳ��Ԫ��aij�ǵ�i���е���Сֵ��ͬʱ���ǵ�j����
�����ֵ����ƴ�Ԫ��Ϊ�þ����е�һ�����㡣�����Զ�ά�������
����Am*n���Ա�д�������������������㷨������������㷨���
����µ�ʱ�临�Ӷȡ�*/
#include "stdafx.h"
#include  "stdlib.h"
#define  Max_Length   4
typedef  int    Status;
int sum[Max_Length];
typedef  struct  Array
{
	int   array[Max_Length][Max_Length];
	int   row, loc;
}Array_List,*LArray;
Status   Init_Array(Array_List  &A)
{
	A.loc = 0;
	A.row = 0;
	int  i, j;
	for (i = 0; i <Max_Length; i++)
	{
		for (j = 0; j <Max_Length; j++)
		{
			A.array[i][j] = 0;
		}
	}
	return  0;
}
Status  Get_Row(Array  A)
{
	for (int j = 0; j < A.row; j++)
	{
		int a = 0;
		int b = 1;
		int  c = 2;
		while (a < A.loc&&b < A.loc)
		{
			if (A.array[j][a] <= A.array[j][b])
			{
				b = c;
				c++;
			}
			else
			{
				a = c;
				c++;
			}
		}
		if (a <= b)
		{
			printf("��%d�е���Сֵ���ڵ���Ϊ��%d��\r\n", j + 1,a+1);
			printf("���ڼ�����...\r\n");
			for (int m = 0; m < A.row; m++)
			{
				if (A.array[j][a]>=A.array[m][a])
				{
					printf("��%d�μ���ɹ�\r\n",m+1);
				}
				else
				{
					printf("ʧ�ܣ��õ㲻������\r\n");
					break;
				}
				if (m == A.row - 1)
				{
					printf("�õ�������\r\n");
				}
			}
			
		}
		else
		{
			printf("�����%d�е���Сֵ���ڵ���Ϊ��%d��\r\n", j + 1, b + 1);
			printf("���ڼ�����...\r\n");
			for (int m = 0; m < A.row; m++)
			{
				if (A.array[j][b] >= A.array[m][b])
				{
					printf("��%d�μ���ɹ�\r\n", m + 1);
				}
				else
				{
					printf("ʧ�ܣ��õ㲻������\r\n");
					break;
				}
				if (m == A.row - 1)
				{
					printf("�õ�������\r\n");
				}
			}
		}
	}
	return  0;
}
int main()
{
	Array_List   A;
	Init_Array(A);
	int i, j;
	printf("������Ϊ%d*%d�������������ĸ���Ԫ��:\r\n",Max_Length,Max_Length);
	for (i = 0; i < Max_Length; i++)
	{
		for (j = 0; j < Max_Length; j++)
		{
			printf("�������%d�е�%d�е�Ԫ��(���س�֮���ʾһ�������������):",i+1,j+1);
			scanf("%d",&A.array[i][j]);
		}
	}
	printf("����������������");
	scanf("%d",&A.row);
	printf("����������������");
	scanf("%d", &A.loc);
	printf("%d,%d",A.row,A.loc);
	int a=Get_Row(A);
	return 0;
}

