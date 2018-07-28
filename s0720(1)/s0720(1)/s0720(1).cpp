/*��дһ�㷨��ʶ�����ζ����һ����@Ϊ�����ַ������Ƿ�Ϊ���硰����1&����2��ģʽ��
�ַ����С���������1������2�������ַ�&��������2������1�������С�*/
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
	int   length;//ʵ�ʳ���
	int   stacksize;//����ռ䳤��
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
	if (S.base == S.top)  printf("��ջΪ��");
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
	printf("����������1������2���ڡ�&�����ĶԳƣ��������ַ�����@���Ž�β:\r\n");
	ch = getchar();
	while (ch != '@')
	{
		Pop_Stack(S, ch);
		ch = getchar();
	}
	printf("���������Ϊ��");
	Travel_Stack(S);
	printf("\r\n�����������ж���\r\n");
	DataType  *p, *q;
	p = S.base;
	q = S.top - 1;
	while (p < q&&*q == *p&&*p != '&')
	{
		printf("\r\n������֤:");
		printf("%c��%c", *p, *q);
		if (*p != *q)
		{
			printf("\r\n��ƥ�����");
			return  -1;
		}
		p++;
		q--;
	}
	if (p == q&&*p == '&')
	{
		printf("\r\nƥ��ɹ������ַ����������");
	}
	else
	{
		printf("\r\nƥ����򲻳ɹ���ƥ��ʧ��");
	}
	return 0;
}

