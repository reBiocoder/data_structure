/*question:假设将循环队列定义为：以域变量rear和length分别指示循环队列中队尾元素的位置和内含元素的个数。
试给出此循环队列的队满条件，并写出相应的入队列和出队列的算法*/ 
/*answer：书上给的答案是设head指示循环队列中对头元素的位置，则有
 head=((q.rear+MAXLEN)-q.length+1)/MAXLEN，其中MAXLEN是循环队列的最大元素存储长度
 -----------------------分割线--------------------------
 但是我觉得将length作为标记位，直接指示循环队列中元素的个数会更容易*/
#include "stdafx.h"
#include  "malloc.h"
#define  BASIC_LENGTH  5
#define  INCREMENT    10
typedef   int   Status;
typedef   int   ElemType;
typedef  struct  Queue
{
	ElemType  *base;
	int  front;
	int  rear;
	int  length;//实际长度
	int  queuesize;//已经分配的长度
}queue,*LinkQueue;

Status  Init_Queue(Queue  &Q)
{
	Q.base = (ElemType*)malloc(BASIC_LENGTH*sizeof(ElemType));
	if (!Q.base)  return  -1;
	Q.front = Q.rear = 0;
	Q.length = 0;
	Q.queuesize = BASIC_LENGTH;
	return  1;
}
Status  Insert_Static_Queue(Queue  &Q, int e)
{
	if (Q.length >= Q.queuesize)
	{
		Q.base = (ElemType*)realloc(Q.base,(BASIC_LENGTH+INCREMENT));
		Q.queuesize = Q.queuesize + INCREMENT;
		if (!Q.base)  return  -1;
	}
	Q.base[Q.rear] = e;
	Q.rear++;
	Q.length++;
	return  1;
}
Status   Delete_Static_Queue(Queue &Q, int &e)//当值需要进行改变时，就需要使用“&”,引用符号，将实参直接当作形参。
{
	if (Q.length == 0)
		printf("该队列已经没有元素了！");
	e = Q.base[Q.front];
	Q.front++;
	Q.length--;
	return 1;
}
Status   Travel_Queue(Queue  Q)
{
	while (Q.length > 0)
	{
		printf("%d",Q.base[Q.front]);
		Q.front++;
		Q.length--;
	}
	return  1;
}
int main()
{
	Queue   Q;
	int  e,m;
	Init_Queue(Q);
	printf("请输入队列元素，依次入队：");
	scanf("%d",&e);
	getchar();
	while (e != 0)
	{
		Insert_Static_Queue(Q,e);
		scanf("%d",&e);
	}
	Travel_Queue(Q);
	printf("出队操作：\r\n");
	Delete_Static_Queue(Q,m);
	printf("出队的元素为：%d\r\n",m);
	Travel_Queue(Q);
    return 0;
}

