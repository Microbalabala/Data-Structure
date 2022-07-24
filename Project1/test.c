//ջ�Ͷ���
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

#define MAXSTACK 100
typedef char StackElemType;

//ջ�����Ͷ���
typedef struct _SqStack
{
	StackElemType* base;
	StackElemType* top;
	int stacksize;
}SqStack;

//ջ�ĳ�ʼ��
Status StackInit(SqStack* S)
{
	S->base = (StackElemType*)malloc(sizeof(StackElemType) * MAXSTACK);
	if (!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = MAXSTACK;
	return OK;
}

//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack* S)
{
	if (S->base = S->top)
		return TRUE;
	else
		return FALSE;
}

//��˳��ջ�ĳ���
int StackLength(SqStack* S)
{
	return S->top - S->base;
}

//���˳��ջ
Status StackClear(SqStack* S)
{
	if (S->base)
		S->top = S->base;
	return OK;
}

//����˳��ջ
Status StackDestroy(SqStack* S)
{
	if (S->base)
	{
		free(S->base);
		S->stacksize = 0;
		S->base = S->top = NULL;
	}
	return OK;
}

//��ջ
Status SqSPush(SqStack* S, StackElemType e)
{
	if (S->top - S->base == S->stacksize)
		return ERROR;
	*S->top = e;
	S->top++;
	return OK;
}

//��ջ
Status Pop(SqStack* S, StackElemType e)
{
	if (S->top = S->base)
		return ERROR;
	S->top--;
	e = *S->top;
	return OK;
}


//��ջ
//��ջ�����Ͷ���
typedef struct _StackNode
{
	StackElemType data;
	struct _StackNode* next;
}StackNode, *LinkStack;

//��ջ�ĳ�ʼ��
Status StackInit(LinkStack S)
{
	S = NULL;
	return	OK;
}

//��ջ����ջ
Status LSPus(LinkStack S, StackElemType e)
{
	LinkStack pnew = (LinkStack)malloc(sizeof(StackNode));
	pnew->data = e;
	pnew->next = S;
	S = pnew;
	return OK;
}

//��ջ�ĳ�ջ
Status LSPop(LinkStack S, StackElemType e)
{
	if (!S)
		return ERROR;
	LinkStack pfree = S;
	e = S->data;
	S = S->next;
	free(pfree);
	pfree = NULL;
	return OK;
}



//����

//ѭ������
//��һά����
#define QMAXSIZE 100
typedef char QElemType;
typedef struct _SqQuene
{
	QElemType* base;//��ʼ���Ķ�̬����洢�ռ�
	int front;//ͷָ��
	int rear;//βָ��
}SqQuene;

//��ʼ��
Status QueneInit(SqQuene* Q)
{
	Q->base = (QElemType*)malloc(sizeof(QElemType) * QMAXSIZE);
	if (!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

//����еĳ���
int QueneLength(SqQuene Q)
{
	return ((Q.rear - Q.front  + QMAXSIZE) % QMAXSIZE);
}

//���
Status EnQuene(SqQuene* Q, QElemType e)
{
	if ((Q->rear + 1) % QMAXSIZE == Q->front)
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % QMAXSIZE;
	return OK;
}

//����
Status DeQuene(SqQuene Q, QElemType e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % QMAXSIZE;
	return OK;
}

//����

//���ӵ����Ͷ���
typedef struct _QNode
{
	QElemType data;
	struct _QNode* next;
}QNode,*QuenePtr;

typedef struct _LinkQuene
{
	QuenePtr front;
	QuenePtr rear;
}LinkQuene;

//��ʼ��
Status InitQuene(LinkQuene* Q)
{
	Q->front = Q->rear = (QuenePtr)malloc(sizeof(QNode));
	Q->front->next = NULL;
	return OK;
}

//����
Status DestroyQuene(LinkQuene* Q)
{
	while (Q->front)
	{
		QuenePtr p = Q->front->next;
		free(Q->front);
		Q->front = p;

		/*Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;*/
	}
	return OK;
}

//��Ԫ��e���
Status EnQuene(LinkQuene* Q, QElemType e)
{
	QuenePtr p = (QuenePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

//����
Status DeQuene(LinkQuene* Q, QElemType* e)
{
	if (Q->front == Q->rear)
		return ERROR;
	QuenePtr p = Q->front->next;
	e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	p = NULL;
	return OK;
}