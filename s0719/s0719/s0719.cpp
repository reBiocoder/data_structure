// s0719.cpp : �������̨Ӧ�ó������ڵ㡣
/*question����˳���va�е�����Ԫ�ص���������дһ�㷨����x���뵽˳�����ʵ�λ���ϣ��Ա��ָñ��������*/
/*answer����ǰ��ѧϰ������һ��ʹ�õ������ö�̬˳����������������������˼·��ͨ������ָ������ɣ��������ʹ��
�����������ͬ���Ĳ�����ʵ���ϳ������ҽ���ǰһ���ڵ���Ҫ�Լ��������취���⣬������˼·�ȵ���ָ��Ҫ�����*/
#include "stdafx.h"
#include "stdlib.h"
#include "malloc.h"
#define  BASIC_Length   100
#define   INCREMENT   10
//#define  int   Status;����������ش��󣺢�define����Ҫ�ֺŢ�������Ӧ��ʹ�õ���typedef
typedef   int  Status;
typedef  struct  Lnode
{
	int  data;
	struct  Lnode  *next;
}lnode,*LinkList;
Status Create_Init_List(LinkList  &L)//�����ʼ��
{
	L = (LinkList)malloc(sizeof(Lnode));
	if (!L)  return  -1;
	else
	{
		L->data = 0;
		L->next = NULL;
	}
	int  m;
	printf("�������һ������(��0��ʾ����)��");
	scanf("%d\r\n",&m);
	LinkList  fp;
	fp = L;
	while(m != 0)
	{
		/*ͷ�巨��LinkList  p = (LinkList)malloc(sizeof(Lnode));
		p->data = m;
		p->next=L->next;
		L->next = p;
		printf("������һ�����֣�");
		scanf("%d",&m);*/
		//β�巨���£�
		LinkList  p = (LinkList)malloc(sizeof(Lnode));
		p->data = m;
		fp->next = p;
		fp = p;
		p->next = NULL;
		printf("������һ�����֣�");
		scanf("%d", &m);
	}
	return  1;
}
void  Insert_Static_List(LinkList &L, int number)
{
	LinkList  p = (LinkList)malloc(sizeof(Lnode));
	/*���￼�ǵ��������޷��ҵ�ǰһ��ָ�룬�����ҵĽ��������ͬʱ������ָ�룬�ټ���һ�������������м�������*/
	LinkList  q = L->next;
	LinkList  fp=L->next;
	int  i = 0;
	while (number>q->data)
	{
		q = q->next;
		i=i+1;//����Ҳ����дΪ��i+=1;����ǧ��Ҫд��i=+1;�������� д�����������������ΪiΪ��ֵ����+1�ˡ�
	}
	printf("%d\r\n",i);
	if (number <= q->data)
	{
		p->data = number;
		while (i>1)
		{
			fp = fp->next;
			i--;
		}
		fp->next = p;
		p->next = q;
	}
}
void  Travel_List(LinkList L)
{
	LinkList  p;
	p = L->next;
	while(p!= NULL)
	{
		printf("%d",p->data);
		p = p->next;
	}
}
int main()
{
	LinkList  L;
	int  data;
	Create_Init_List(L);
	printf("����֮ǰ�����У�\r\n");
	Travel_List(L);
	printf("\r\n������Ҫ���������");
	scanf("%d",&data);
	Insert_Static_List(L,data);
	printf("����֮������У�\r\n");
	Travel_List(L);
    return 0;
}

