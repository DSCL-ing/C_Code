#include "Queue.h"


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
		next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head=pq->tail = NULL;
}

void QueuePush(Queue *pq,QDataType x)
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
		pq->tail = pq->head = NULL;//后置空
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
	return pq->head == NULL ;//只要有一个就可以了
	//head为空tail也为空
}
