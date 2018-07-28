/*试写一算法，识别依次读入的一个以@为结束字符序列是否为形如“序列1&序列2”模式的
字符序列。其中序列1和序列2均不含字符&，且序列2是序列1的逆序列。*/
#include "stdafx.h"
#include "malloc.h"
#define  BASIC_LENGTH  100
#define  INCREMENT  10
typedef  char  DataType;
typedef  int   Status;
typedef  struct  sqstack
{
	DataType  *base;
	DataType  *top;
	int   length;//实际长度
	int   stacksize;//分配空间长度
}Sqstack;
Status  Init_stack(Sqstack  &S)
{
	S.base = (DataType*)malloc(BASIC_LENGTH*sizeof(DataType));
	if (!S.base)  return -1;
	S.top = S.base;
	S.stacksize = BASIC_LENGTH;
	S.length = 0;
	return  0;
}
Status   Pop_Stack(Sqstack &S, char  ch)
{
	if (S.length == S.stacksize)
	{
		S.base = (DataType*)realloc(S.base,(BASIC_LENGTH+INCREMENT));
		if (!S.base) return  -1;
		else
		{
			S.stacksize = BASIC_LENGTH + INCREMENT;
		}
	}
	*S.top++ = ch;
	S.length++;
	return  0;
}

Status Travel_Stack(Sqstack S)
{
	if (S.base == S.top)  printf("该栈为空");
	else
	{
		while (S.base < S.top)
		{
			printf("%c",*S.base);
			S.base++;
		}
	}
	return  0;
}
int main()
{
	Sqstack  S;
	char  ch;
	Init_stack(S);
	printf("（规则：序列1和序列2关于“&”回文对称）请输入字符，以@符号结尾:\r\n");
	ch = getchar();
	while (ch != '@')
	{
		Pop_Stack(S, ch);
		ch = getchar();
	}
	printf("输入的序列为：");
	Travel_Stack(S);
	printf("\r\n下面对其进行判定：\r\n");
	DataType  *p, *q;
	p = S.base;
	q = S.top - 1;
	while (p < q&&*q == *p&&*p != '&')
	{
		printf("\r\n正在验证:");
		printf("%c和%c", *p, *q);
		if (*p != *q)
		{
			printf("\r\n不匹配规则");
			return  -1;
		}
		p++;
		q--;
	}
	if (p == q&&*p == '&')
	{
		printf("\r\n匹配成功，该字符串满足规则");
	}
	else
	{
		printf("\r\n匹配规则不成功，匹配失败");
	}
	return 0;
}

