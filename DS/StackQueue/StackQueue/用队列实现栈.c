
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

//���Ʊ����ṹ��
//ֻ��һ��ֵ���Ͳ��ö���ṹ�壬�ж���Ͷ���ṹ�⡣

typedef struct Queue
{
	QNode *head; //��ͷ�����ӣ�ͷɾ
	QNode *tail; //��β����ӣ�β��
}Queue;
//��ָ������ʹ�����ָ�룬����ͨ�����ʹ�һ��

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
		//���� next = pq->head->next   ���󣡣�����head�Ѿ��ͷ��ˣ������ٽ�������
		next = cur->next;//�������ֹû�ڵ�ʱ�����á�
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
	//�ȳ�ʼ����ʹ��
	newnode->data = x;
	newnode->next = NULL;
	//���������-β��ͷɾ��
	if (pq->tail == NULL)//ͷβ���У��ж�һ���Ϳ�����
	{
		pq->head = pq->tail = newnode;
	}
	else                             //β��
	{
		pq->tail->next = NULL;
		pq->tail->next = newnode; //��βָ��Ľڵ��������½ڵ�
		pq->tail = newnode;      //��βָ���½ڵ�
	}
}

void QueuePop(Queue *pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->head->next == NULL)//ֻ��һ���ڵ�
	{
		free(pq->head);//���ͷ�
		pq->head = NULL;//���ÿ�
		pq->tail = NULL;
	}
	else
	{
		QNode *next = pq->head->next;//��ס��һ��
		free(pq->head);//�ͷ�ͷ�ڵ�
		pq->head = next;//�¸��ڵ��Ϊ�½ڵ�
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
	return pq->head == NULL && pq->tail == NULL;//ֻҪ��һ���Ϳ�����
	//headΪ��tailҲΪ��
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
	//��ֹ��������������ջ�ռ�
	//��һ��ȫ�־�̬�������
	//�������ڶ��п���һ���ռ䣬�ڶ��н��в�����MyStack��Q1��Q2
	//:>Q1��Q2���ָ�룬���͡�
	//��ָ�������ָ����ʽ�ṹ��ָ�����ʽ�ṹ���ڴ���MyStack�޹أ������С�̶�
	
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
	//��Ĭ��q1Ϊ�գ�q2�ǿ�
	Queue *EmptyQ = &obj->q1;
	Queue *noneEmptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1))   // �����෴
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
	//if (!QueueEmpty(&obj->q1))   // �����෴
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