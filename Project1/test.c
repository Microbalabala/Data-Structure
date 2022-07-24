//栈和队列
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

//栈的类型定义
typedef struct _SqStack
{
	StackElemType* base;
	StackElemType* top;
	int stacksize;
}SqStack;

//栈的初始化
Status StackInit(SqStack* S)
{
	S->base = (StackElemType*)malloc(sizeof(StackElemType) * MAXSTACK);
	if (!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = MAXSTACK;
	return OK;
}

//判断栈是否为空
Status StackEmpty(SqStack* S)
{
	if (S->base = S->top)
		return TRUE;
	else
		return FALSE;
}

//求顺序栈的长度
int StackLength(SqStack* S)
{
	return S->top - S->base;
}

//清空顺序栈
Status StackClear(SqStack* S)
{
	if (S->base)
		S->top = S->base;
	return OK;
}

//销毁顺序栈
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

//入栈
Status SqSPush(SqStack* S, StackElemType e)
{
	if (S->top - S->base == S->stacksize)
		return ERROR;
	*S->top = e;
	S->top++;
	return OK;
}

//出栈
Status Pop(SqStack* S, StackElemType e)
{
	if (S->top = S->base)
		return ERROR;
	S->top--;
	e = *S->top;
	return OK;
}


//链栈
//链栈的类型定义
typedef struct _StackNode
{
	StackElemType data;
	struct _StackNode* next;
}StackNode, *LinkStack;

//链栈的初始化
Status StackInit(LinkStack S)
{
	S = NULL;
	return	OK;
}

//链栈的入栈
Status LSPus(LinkStack S, StackElemType e)
{
	LinkStack pnew = (LinkStack)malloc(sizeof(StackNode));
	pnew->data = e;
	pnew->next = S;
	S = pnew;
	return OK;
}

//链栈的出栈
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



//队列

//循环队列
//用一维数组
#define QMAXSIZE 100
typedef char QElemType;
typedef struct _SqQuene
{
	QElemType* base;//初始化的动态分配存储空间
	int front;//头指针
	int rear;//尾指针
}SqQuene;

//初始化
Status QueneInit(SqQuene* Q)
{
	Q->base = (QElemType*)malloc(sizeof(QElemType) * QMAXSIZE);
	if (!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

//求队列的长度
int QueneLength(SqQuene Q)
{
	return ((Q.rear - Q.front  + QMAXSIZE) % QMAXSIZE);
}

//入队
Status EnQuene(SqQuene* Q, QElemType e)
{
	if ((Q->rear + 1) % QMAXSIZE == Q->front)
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % QMAXSIZE;
	return OK;
}

//出队
Status DeQuene(SqQuene Q, QElemType e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % QMAXSIZE;
	return OK;
}

//链队

//链队的类型定义
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

//初始化
Status InitQuene(LinkQuene* Q)
{
	Q->front = Q->rear = (QuenePtr)malloc(sizeof(QNode));
	Q->front->next = NULL;
	return OK;
}

//销毁
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

//将元素e入队
Status EnQuene(LinkQuene* Q, QElemType e)
{
	QuenePtr p = (QuenePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

//出队
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