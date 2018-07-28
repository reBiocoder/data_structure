/*question:���轫ѭ�����ж���Ϊ���������rear��length�ֱ�ָʾѭ�������ж�βԪ�ص�λ�ú��ں�Ԫ�صĸ�����
�Ը�����ѭ�����еĶ�����������д����Ӧ������кͳ����е��㷨*/ 
/*answer�����ϸ��Ĵ�����headָʾѭ�������ж�ͷԪ�ص�λ�ã�����
 head=((q.rear+MAXLEN)-q.length+1)/MAXLEN������MAXLEN��ѭ�����е����Ԫ�ش洢����
 -----------------------�ָ���--------------------------
 �����Ҿ��ý�length��Ϊ���λ��ֱ��ָʾѭ��������Ԫ�صĸ����������*/
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
	int  length;//ʵ�ʳ���
	int  queuesize;//�Ѿ�����ĳ���
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
Status   Delete_Static_Queue(Queue &Q, int &e)//��ֵ��Ҫ���иı�ʱ������Ҫʹ�á�&��,���÷��ţ���ʵ��ֱ�ӵ����βΡ�
{
	if (Q.length == 0)
		printf("�ö����Ѿ�û��Ԫ���ˣ�");
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
	printf("���������Ԫ�أ�������ӣ�");
	scanf("%d",&e);
	getchar();
	while (e != 0)
	{
		Insert_Static_Queue(Q,e);
		scanf("%d",&e);
	}
	Travel_Queue(Q);
	printf("���Ӳ�����\r\n");
	Delete_Static_Queue(Q,m);
	printf("���ӵ�Ԫ��Ϊ��%d\r\n",m);
	Travel_Queue(Q);
    return 0;
}

