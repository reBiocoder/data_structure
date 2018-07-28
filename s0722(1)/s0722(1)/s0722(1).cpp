// �ַ�����ģʽƥ�䣺KMP�㷨
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
}sstring,*Lstring;
Status  Init_String(SString  &S)
{
	S.base = (char*)malloc(MAXLENG*sizeof(char));
	if (!S.base)  printf("����ʧ��");
	S.length = 1;//Ϊ�˼���next�ķ��㣬���ﲻ����0��λ��
	return  1;
}
int  next[MAXLENG];//jΪ���ĵ�j���ַ���kΪ��j���ַ�֮ǰ�����ƥ��ǰ׺�ͺ�׺
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
			printf("����ռ�ʧ��");
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
	printf("������һ���ַ�����");
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

