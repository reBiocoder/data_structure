//顺序表代码
#include "stdafx.h"
#include "malloc.h"
#include  "stdlib.h"
#define OK  1
#define ERROR  -1
#define OVERFLOW  -2
#define  LIST_SIZE  100//数组初始长度
#define  LISTINCREMENT   10//数组增量长度
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
}//动态顺序表的初始化
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
	
}///将元素e插入到动态顺序表的第i个位置
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
	ElemType  *p, *q;
	if (i<1 || i>L.Length)  return ERROR;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.Length + 1;//数学:首数加上长度，它其实比尾数要要多一
	for (++p; p <= q; ++p)   *(p - 1) = *p;
	--L.Length;
	return  OK;
}//删除顺序表中第i个位置的元素，同时将其保存在e中
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
}//当已知一个元素为e时，判断其是否在顺序表中，若在，输出其位置。
Status  LocateElem_Del_Sq(SqList  &L, ElemType  e)
{
	int  k = 0;
	int  i = LocateElem_Sq(L,e);//判断在L中是否含有元素e，并返回它在顺序表中的位置
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
		exit(OVERFLOW);//exit()函数表示强行退出程序，0表示正常运行退出，非0表示非正常运行退出，它包含在头文件"stdlib.h"中
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
}//两个表进行合并，注意一个问题，指针++是不行的。
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
		printf("如果插入成功输出ok,否则输出ERROR：【%s】\r\n", "OK");
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
	printf("40定位为：%d",m);
    return 0;
}

