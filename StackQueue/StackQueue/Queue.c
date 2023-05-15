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
		next = pq->head->next;//�������ֹû�ڵ�ʱ�����á�
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
	//�ȳ�ʼ����ʹ��
	newnode->data = x;
	newnode->next = NULL;
	//���������-β��ͷɾ��
	if (pq->head == NULL)//ͷβ���У��ж�һ���Ϳ����� ---��ͷ���ã���Ҫ��β--��β���ܲ岻�������ɾ���βû���ÿյĻ�
	{
		pq->head = pq->tail = newnode;
	}
	else                             //β��
	{
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
		pq->tail = pq->head = NULL;//���ÿ� :tail �� head�����ÿգ���Ȼ�´ξͲ岻���� ---ΪʲôҪ�ÿգ���Ϊpush��ҪNULLʶ��ն��в���
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
	return pq->head == NULL ;//ֻҪ��һ���Ϳ�����
	//headΪ��tailҲΪ��
}
