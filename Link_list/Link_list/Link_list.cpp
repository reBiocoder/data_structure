//˳������
#include "stdafx.h"
#include "malloc.h"
#include  "stdlib.h"
#define OK  1
#define ERROR  -1
#define OVERFLOW  -2
#define  LIST_SIZE  100//�����ʼ����
#define  LISTINCREMENT   10//������������
typedef  int  ElemType;
typedef   int   Status;
typedef  struct
{
	ElemType  *elem;
	int   Length;
	int   listsize;
}SqList;
Status  InitList_Sq(SqList  &L)
{
	L.elem = (ElemType*)malloc(LIST_SIZE*sizeof(ElemType));
	L.Length = 0;
	L.listsize = LIST_SIZE;
	return  OK;
}//��̬˳���ĳ�ʼ��
Status ListInsert_Sq(SqList  &L, int  i, ElemType  e)
{
	ElemType   *p;
	if (i<1 || i>L.Length + 1)
		return  ERROR;
	if (L.Length >= L.listsize)
	{
		ElemType* newbase = (ElemType*)realloc(L.elem, (LIST_SIZE + LISTINCREMENT)*sizeof(ElemType));
		if (!newbase)   return  OVERFLOW;
		else
		{
			L.elem = newbase;
			L.listsize = LIST_SIZE + LISTINCREMENT;
		}
	}
		ElemType*  q = &(L.elem[i - 1]);
		for (p = &(L.elem[L.Length - 1]); p >= q; --p)
			*(p + 1) = *p;
		*q = e;
		++L.Length;
		return  OK;
	
}///��Ԫ��e���뵽��̬˳���ĵ�i��λ��
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
	ElemType  *p, *q;
	if (i<1 || i>L.Length)  return ERROR;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.Length + 1;//��ѧ:�������ϳ��ȣ�����ʵ��β��ҪҪ��һ
	for (++p; p <= q; ++p)   *(p - 1) = *p;
	--L.Length;
	return  OK;
}//ɾ��˳����е�i��λ�õ�Ԫ�أ�ͬʱ���䱣����e��
Status  LocateElem_Sq(SqList  L, ElemType e)
{
	int  i;
	ElemType  *p;
	i = 1;
	p = L.elem;
	while (i <= L.Length && (*p++ != e))
		++i;
	if (i <= L.Length)  return  i;
	else  return   -1;
}//����֪һ��Ԫ��Ϊeʱ���ж����Ƿ���˳����У����ڣ������λ�á�
Status  LocateElem_Del_Sq(SqList  &L, ElemType  e)
{
	int  k = 0;
	int  i = LocateElem_Sq(L,e);//�ж���L���Ƿ���Ԫ��e������������˳����е�λ��
	if (i >= 0)
		return  ListDelete_Sq(L,i,k);
	return  0;
}
void  MergeList_Sq(SqList  La, SqList  Lb, SqList  &Lc)
{
	ElemType  *pa, *pb, *pc, *pa_last, *pb_last;
	pa = La.elem; pb = La.elem;
	Lc.listsize = Lc.Length = La.Length + Lb.Length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize*sizeof(ElemType));
	if (!Lc.elem)
		exit(OVERFLOW);//exit()������ʾǿ���˳�����0��ʾ���������˳�����0��ʾ�����������˳�����������ͷ�ļ�"stdlib.h"��
	pa_last = La.elem + La.Length - 1;
	pb_last = Lb.elem + Lb.Length - 1;
	while (pa <= pa_last&&pb <= pb_last)
	{
		if (*pa <= *pb)   *pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pb < pb_last)   *pc++ =*pb++;
	while (pa < pa_last)    *pc++ = *pa++;
}//��������кϲ���ע��һ�����⣬ָ��++�ǲ��еġ�
void  Travel_Sq(SqList a)
{
	int k = 0;
	while (k < a.Length)
	{
		printf("%d\r\n",a.elem[k]);
		k++;
	}
}
int main()
{
	SqList  L;
	char  c;
	InitList_Sq(L);
	int  a = 10;
	int s=ListInsert_Sq(L,1,10);
	if (s == OK)
	{
		printf("�������ɹ����ok,�������ERROR����%s��\r\n", "OK");
	}
	else
	{
		printf("%s", "ERROR\r\n");
	}
	ListInsert_Sq(L,1,20);
	ListInsert_Sq(L,1,30);
	ListInsert_Sq(L,1,40);
	ListInsert_Sq(L,1,50);
	Travel_Sq(L);
	int  m = LocateElem_Sq(L,40);
	printf("40��λΪ��%d",m);
    return 0;
}

