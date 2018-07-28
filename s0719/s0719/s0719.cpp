// s0719.cpp : 定义控制台应用程序的入口点。
/*question：设顺序表va中的数据元素递增有序。设写一算法，将x插入到顺序表的适当位置上，以保持该表的有序性*/
/*answer：以前的学习过程中一般使用的是利用动态顺序表来进行这个操作，具体思路是通过调整指针来完成，这次我想使用
单链表来完成同样的操作，实际上除了在找结点的前一个节点需要自己想出解决办法以外，其他的思路比调整指针要简单许多*/
#include "stdafx.h"
#include "stdlib.h"
#include "malloc.h"
#define  BASIC_Length   100
#define   INCREMENT   10
//#define  int   Status;这条语句严重错误：①define不需要分号②重命名应该使用的是typedef
typedef   int  Status;
typedef  struct  Lnode
{
	int  data;
	struct  Lnode  *next;
}lnode,*LinkList;
Status Create_Init_List(LinkList  &L)//链表初始化
{
	L = (LinkList)malloc(sizeof(Lnode));
	if (!L)  return  -1;
	else
	{
		L->data = 0;
		L->next = NULL;
	}
	int  m;
	printf("请输入第一个数字(以0表示结束)：");
	scanf("%d\r\n",&m);
	LinkList  fp;
	fp = L;
	while(m != 0)
	{
		/*头插法：LinkList  p = (LinkList)malloc(sizeof(Lnode));
		p->data = m;
		p->next=L->next;
		L->next = p;
		printf("请输入一个数字：");
		scanf("%d",&m);*/
		//尾插法如下：
		LinkList  p = (LinkList)malloc(sizeof(Lnode));
		p->data = m;
		fp->next = p;
		fp = p;
		p->next = NULL;
		printf("请输入一个数字：");
		scanf("%d", &m);
	}
	return  1;
}
void  Insert_Static_List(LinkList &L, int number)
{
	LinkList  p = (LinkList)malloc(sizeof(Lnode));
	/*这里考虑到单链表无法找到前一个指针，所以我的解决方法是同时设两个指针，再加上一个计数器来进行计数操作*/
	LinkList  q = L->next;
	LinkList  fp=L->next;
	int  i = 0;
	while (number>q->data)
	{
		q = q->next;
		i=i+1;//这里也可以写为：i+=1;但是千万不要写成i=+1;。。。。 写成这样计算机就误以为i为定值等于+1了。
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
	printf("插入之前的序列：\r\n");
	Travel_List(L);
	printf("\r\n请输入要插入的数：");
	scanf("%d",&data);
	Insert_Static_List(L,data);
	printf("插入之后的序列：\r\n");
	Travel_List(L);
    return 0;
}

