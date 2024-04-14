#define _CRT_SECURE_NO_WARNINGS 1


#include"DoubleList.h"

void Print(ListNode *phead)
{
	assert(phead);
	ListNode *cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//void ListNode(ListNode *phead)


ListNode *InitList(void)
{
	//ListNode *prev, *tail;
	//�ڱ���ͷ�ڵ�
	//�ڱ������ص��ǲ��洢���ݣ��ɴˣ����Բ���ʼ�������ֵ����
	ListNode *phead = (ListNode*)malloc(sizeof(ListNode));
	if (phead == NULL)
	{
		printf("malloc fail\n ");
		exit(-1);
	}
	phead->prev = phead;
	phead->next = phead;
	return phead;
}

ListNode *CreateListNode(ListDataType x)
{
	ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}


void PushBackList(ListNode *phead, ListDataType x)
{
	ListNode *newnode = CreateListNode(x);
	ListNode *tail = phead->prev;//����������������Ի���λ��
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;

	//phead->prev->next = newnode;//β�ڵ�ָ���½ڵ�
	//newnode->prev = phead->prev;//�½ڵ�ָ��β�ڵ�
	//newnode->next = phead;//�½ڵ�ָ��ͷ�ڵ�
	//phead->prev = newnode;//ͷ�ڵ�ָ���½ڵ�


	//Insert(phead, x);
}

void PushFrontList(ListNode *phead,ListDataType x)
{
	ListNode *newnode = CreateListNode(x);
	ListNode *next = phead->next;//����������������Ի���λ��
	newnode->next = next;//�¸��ڵ��λ�ø��½ڵ�
	next->prev = newnode;//�½ڵ��ַ���½ڵ�
	phead->next = newnode;
	newnode->prev = phead;


	//Insert(phead->next, x);
}

void PopBackList(ListNode *phead)
{
	ListNode *tail = phead->prev;
	ListNode *tailPrev = tail->prev;
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;
	//EraseList(phead->prev);
}

void PopFrontList(ListNode *phead)
{
	ListNode *next = phead->next;
	ListNode *nextNext = next->next;
	free(next);
	phead->next = nextNext;
	nextNext->prev = phead;
	next = NULL;
	//EraseList(phead->next);
}


ListNode *FindList(ListNode *phead, ListDataType x)
{
	assert(phead);
	ListNode *pos = phead->next;
	while (pos!=phead)
	{
		if (pos->next = x)
		{
			return pos;
		}
		pos = pos->next;
	}
	printf("not find");
	return NULL;
	
}


void InsertList(ListNode *pos,ListDataType x)//�ò���phead
{
	ListNode *newnode = CreateListNode(x);
	ListNode *prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void EraseList(ListNode *pos)
{
	ListNode *posPrev = pos->prev;
	ListNode *posNext = pos->next;
	free(pos);
	pos = NULL;
	posPrev->next = posNext;
	posNext->prev = posNext;
}

void DestroyList(ListNode *phead)
{
	assert(phead);
	ListNode *cur = phead->next;
	ListNode *next = NULL;
	while (cur)
	{
		if (cur != phead)
		{
			next = cur->next;
			free(cur);
			cur = next;
		}
	}
	free(phead);
}
//head = NULL;//������ÿ�


bool ListEmpty(ListNode *phead)
{
	assert(phead);
	return phead->next == phead;
}

size_t ListSize(ListNode *phead)
{

	assert(phead);
	size_t n = 0;
	ListNode *cur = phead->next;
	while (cur!=phead )
	{
		n++;
		cur = cur->next;
	}
	return n;
}
