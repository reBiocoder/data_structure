// s0725.cpp : 定义控制台应用程序的入口点。
/*question：若矩阵Am*n中的某个元素aij是第i行中的最小值，同时又是第j列中
的最大值，则称此元素为该矩阵中的一个马鞍点。假设以二维数组存贮
矩阵Am*n，试编写求出矩阵中所有马鞍点的算法，并分析你的算法在最坏
情况下的时间复杂度。*/
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
			printf("第%d行的最小值所在的列为第%d列\r\n", j + 1,a+1);
			printf("正在计算中...\r\n");
			for (int m = 0; m < A.row; m++)
			{
				if (A.array[j][a]>=A.array[m][a])
				{
					printf("第%d次计算成功\r\n",m+1);
				}
				else
				{
					printf("失败，该点不是马鞍点\r\n");
					break;
				}
				if (m == A.row - 1)
				{
					printf("该点是马鞍点\r\n");
				}
			}
			
		}
		else
		{
			printf("求出第%d行的最小值所在的列为第%d列\r\n", j + 1, b + 1);
			printf("正在计算中...\r\n");
			for (int m = 0; m < A.row; m++)
			{
				if (A.array[j][b] >= A.array[m][b])
				{
					printf("第%d次计算成功\r\n", m + 1);
				}
				else
				{
					printf("失败，该点不是马鞍点\r\n");
					break;
				}
				if (m == A.row - 1)
				{
					printf("该点是马鞍点\r\n");
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
	printf("本矩阵为%d*%d矩阵，请输入矩阵的各个元素:\r\n",Max_Length,Max_Length);
	for (i = 0; i < Max_Length; i++)
	{
		for (j = 0; j < Max_Length; j++)
		{
			printf("请输入第%d行第%d列的元素(按回车之后表示一个数据输入结束):",i+1,j+1);
			scanf("%d",&A.array[i][j]);
		}
	}
	printf("请输入矩阵的行数：");
	scanf("%d",&A.row);
	printf("请输入矩阵的列数：");
	scanf("%d", &A.loc);
	printf("%d,%d",A.row,A.loc);
	int a=Get_Row(A);
	return 0;
}

