// s0722(2).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"
#define  MAXLENG  100
#define  INCREMENT   10
typedef  int   Status;
typedef  char   ElemType;
//求next数组,即满足关系next[j]=k时，模式串使用第k个字符与主串进行匹配
typedef  struct  SString
{
	ElemType  *base;
	int  length;
}sstring, *Lstring;
Status  Init_String(SString  &S)//切记使用"&",因为初始化，需用将实参改变，一定用引用，否则，只是形参改变，而实参并没有改变
{
	S.base = (char*)malloc(MAXLENG*sizeof(char));
	if (!S.base)  printf("分配失败");
	S.length = 1;//为了计算next的方便，这里不适用0号位置
	char  ch;
	printf("请输入一个字符串：");
	ch = getchar();
	while (ch != '\n')
	{
		S.base[S.length] = ch;
		S.length++;
		ch = getchar();
	}
	return  1;
}
int next[MAXLENG];
//j为串的第j个字符；k为第j个字符之前的最大匹配前缀和后缀
void  Next(SString t)
{
	int j = 1;
	int  k = 0;
	next[1] = 0;
	while (j < t.length)
	{
		if (k == 0 || t.base[k] == t.base[j])
		{
			k++;
			j++;
			next[j] = k;
		}
		else 
		{
			k = next[k];
		}
	}
	//printf("%d\r\n",t.base[0]);
	for (int i=1; i < t.length; i++)
	{
		printf("%d",next[i]);
	}
}
Status   Make_Kmp(SString  S, SString  T,int &e)//主串与模式串相互比较，并返回相同字符时在主串中的第一个字符位置
{
	Next(T);
	int  i = 1;
	int  j = 1;
	while (i < S.length&&j < T.length)
	{
		if (j==0||S.base[i] == T.base[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
		if (j>= T.length)
		{
			e = i - T.length+1;
			printf("\r\n%d,%d\r\n", i, T.length);
			printf("从第%d个位置开始匹配", e);
		}
		if (i >= S.length)
		{
			printf("主串中，没有该字符串");
		}
	}
	return  0;
}
/*Status  Insert_Char(SString  &S, char  ch)
{
	if (S.length == MAXLENG)
	{
		S.base = (char*)realloc(S.base, (MAXLENG + INCREMENT));
		if (!S.base)
		{
			printf("分配空间失败");
			return  -1;
		}
	}
	S.base[S.length] = ch;
	S.length++;
	return  1;
}*/
Status  Travel(SString  T)
{
	for (int i = 1; i < T.length; i++)
	{
		printf("%c",T.base[i]);
	}
	return  0;
}
int main()
{
	SString  T;
	SString  S;
	int  e;
	char  ch;
	Init_String(T);
	Init_String(S);
	Next(T);
	Travel(T);
	Travel(S);
	printf("\r\nkmp算法开始进行模式匹配：\r\n");
	Make_Kmp(S,T,e);
	return 0;
}
