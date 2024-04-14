
//https://leetcode-cn.com/problems/implement-stack-using-queues/


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode *next;
	QDataType data;
}QNode;

//控制变量结构体
//只有一个值，就不用定义结构体，有多个就定义结构题。

typedef struct Queue
{
	QNode *head; //队头，出队，头删
	QNode *tail; //队尾，入队，尾插
}Queue;
//是指针变量就传二级指针，是普通变量就传一级

void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);

void QueuePush(Queue *pq, QDataType x);
void QueuePop(Queue *pq);

QDataType QueueFront(Queue *pq);
QDataType QueueBack(Queue *pq);

int QueueSize(Queue *pq);
bool QueueEmpty(Queue *pq);



void QueueInit(Queue *pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;


}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode * next = NULL;
	QNode *cur = pq->head;
	while (cur)
	{
		//粗心 next = pq->head->next   错误！！！，head已经释放了，不能再解引用了
		next = cur->next;//放这里防止没节点时解引用。
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue *pq, QDataType x)
{
	assert(pq);
	QNode *newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail ");
		exit(-1);
	}
	//先初始化再使用
	newnode->data = x;
	newnode->next = NULL;
	//单链表队列-尾插头删。
	if (pq->tail == NULL)//头尾都行，判断一个就可以了
	{
		pq->head = pq->tail = newnode;
	}
	else                             //尾插
	{
		pq->tail->next = NULL;
		pq->tail->next = newnode; //队尾指向的节点链接上新节点
		pq->tail = newnode;      //队尾指向新节点
	}
}

void QueuePop(Queue *pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->head->next == NULL)//只有一个节点
	{
		free(pq->head);//先释放
		pq->head = NULL;//后置空
		pq->tail = NULL;
	}
	else
	{
		QNode *next = pq->head->next;//记住下一个
		free(pq->head);//释放头节点
		pq->head = next;//下个节点成为新节点
	}
}

QDataType QueueFront(Queue *pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}


QDataType QueueBack(Queue *pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

int QueueSize(Queue *pq)
{
	assert(pq);
	QNode *cur = pq->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

bool QueueEmpty(Queue *pq)
{
	assert(pq);
	//return QueueSize(pq) == 0;
	return pq->head == NULL && pq->tail == NULL;//只要有一个就可以了
	//head为空tail也为空
}





//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------


typedef struct {
	Queue q1;
	Queue q2;

} MyStack;


MyStack* myStackCreate() {
	//防止函数结束后销毁栈空间
	//法一：全局静态，问题多
	//法二：在堆中开辟一个空间，在堆中进行操作。MyStack放Q1、Q2
	//:>Q1，Q2存放指针，整型。
	//而指针变量又指向链式结构，指向的链式结构的内存与MyStack无关，总体大小固定
	
	MyStack *tmp= (MyStack*)malloc(sizeof(MyStack));
	if (!tmp)
	{
		perror("fail malloc");
		exit(-1);
	}
	 QueueInit(&tmp->q1);
	 QueueInit(&tmp->q2);
	 return tmp;
}

void myStackPush(MyStack* obj, int x) {
	assert(obj);
	if (!QueueEmpty(&obj->q1))
		QueuePush(&obj->q1, x);
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	//先默认q1为空，q2非空
	Queue *EmptyQ = &obj->q1;
	Queue *noneEmptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1))   // 否则相反
	{
		EmptyQ = &obj->q2;
		noneEmptyQ = &obj->q1;  
	}

	while (QueueSize(noneEmptyQ) > 1)
	{
		QueuePush(EmptyQ, QueueFront(noneEmptyQ));
		QueuePop(noneEmptyQ);
	}
	QDataType n =  QueueBack(noneEmptyQ);
	QueuePop(noneEmptyQ);
	return n;
}

int myStackTop(MyStack* obj) {
	assert(obj);
	//Queue *EmptyQ = &obj->q1;
	//Queue *noneEmptyQ = &obj->q2;
	//if (!QueueEmpty(&obj->q1))   // 否则相反
	//{
	//	EmptyQ = &obj->q2;
	//	noneEmptyQ = &obj->q1;
	//}

	if (!QueueEmpty(&obj->q1))
		return QueueBack(&obj->q1);
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	assert(obj);
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	assert(obj);
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);

}

int main()
{
	MyStack *stack = myStackCreate();


	myStackPush(stack, 1);
	myStackPush(stack, 2);
	myStackPush(stack, 3);
	myStackPush(stack, 4);

	while (!myStackEmpty(stack))
	{
		printf("%d ", myStackTop(stack));
		myStackPop(stack);
	}
	myStackFree(stack);
	return 0;
}