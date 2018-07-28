// s0722(2).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"
#define  MAXLENG  100
#define  INCREMENT   10
typedef  int   Status;
typedef  char   ElemType;
//��next����,�������ϵnext[j]=kʱ��ģʽ��ʹ�õ�k���ַ�����������ƥ��
typedef  struct  SString
{
	ElemType  *base;
	int  length;
}sstring, *Lstring;
Status  Init_String(SString  &S)//�м�ʹ��"&",��Ϊ��ʼ�������ý�ʵ�θı䣬һ�������ã�����ֻ���βθı䣬��ʵ�β�û�иı�
{
	S.base = (char*)malloc(MAXLENG*sizeof(char));
	if (!S.base)  printf("����ʧ��");
	S.length = 1;//Ϊ�˼���next�ķ��㣬���ﲻ����0��λ��
	char  ch;
	printf("������һ���ַ�����");
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
//jΪ���ĵ�j���ַ���kΪ��j���ַ�֮ǰ�����ƥ��ǰ׺�ͺ�׺
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
Status   Make_Kmp(SString  S, SString  T,int &e)//������ģʽ���໥�Ƚϣ���������ͬ�ַ�ʱ�������еĵ�һ���ַ�λ��
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
			printf("�ӵ�%d��λ�ÿ�ʼƥ��", e);
		}
		if (i >= S.length)
		{
			printf("�����У�û�и��ַ���");
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
			printf("����ռ�ʧ��");
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
	printf("\r\nkmp�㷨��ʼ����ģʽƥ�䣺\r\n");
	Make_Kmp(S,T,e);
	return 0;
}
