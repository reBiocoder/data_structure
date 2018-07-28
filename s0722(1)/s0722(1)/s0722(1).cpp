// 字符串的模式匹配：KMP算法
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
}sstring,*Lstring;
Status  Init_String(SString  &S)
{
	S.base = (char*)malloc(MAXLENG*sizeof(char));
	if (!S.base)  printf("分配失败");
	S.length = 1;//为了计算next的方便，这里不适用0号位置
	return  1;
}
int  next[MAXLENG];//j为串的第j个字符；k为第j个字符之前的最大匹配前缀和后缀
Status  Next(SString  T)
{
	int j = 1, k = 0;
	next[1] = 0;
	for (j = 2, k = 0; j <= T.length; j++)
	{
		while (k > 0 && T.base[k] != T.base[j])
			k = next[k];
		if (T.base[k] == T.base[j])
		{
			k++;
		}
		next[j] = k;
	}
	printf("%s",next);
	return  1;
}
Status  Insert_Char(SString  &S, char  ch)
{
	if (S.length == MAXLENG)
	{
		S.base = (char*)realloc(S.base,(MAXLENG+INCREMENT));
		if (!S.base)
		{
			printf("分配空间失败");
			return  -1;
		}
	}
	S.base[S.length] = ch;
	S.length++;
	return  1;
}




int main()
{
	SString  T;
	char  ch;
	Init_String(T);
	printf("请输入一个字符串：");
	ch = getchar();
	while (ch != '\n')
	{
		T.base[T.length] = ch;
		T.length++;
		ch = getchar();
	}
	Next(T);
    return 0;
}

