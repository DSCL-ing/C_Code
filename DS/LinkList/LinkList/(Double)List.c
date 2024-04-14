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
	//哨兵卫头节点
	//哨兵卫的特点是不存储数据，由此，可以不初始化，随机值都行
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
	ListNode *tail = phead->prev;//这样定义更加灵活，可以互换位置
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;

	//phead->prev->next = newnode;//尾节点指向新节点
	//newnode->prev = phead->prev;//新节点指向尾节点
	//newnode->next = phead;//新节点指向头节点
	//phead->prev = newnode;//头节点指向新节点


	//Insert(phead, x);
}

void PushFrontList(ListNode *phead,ListDataType x)
{
	ListNode *newnode = CreateListNode(x);
	ListNode *next = phead->next;//这样定义更加灵活，可以互换位置
	newnode->next = next;//下个节点的位置给新节点
	next->prev = newnode;//新节点地址给下节点
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


void InsertList(ListNode *pos,ListDataType x)//用不到phead
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
//head = NULL;//在外界置空


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
