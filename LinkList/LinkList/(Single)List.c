#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleLinkList.h"

//断言目的：防传参出错

SListNode* CreateSListNode(SLDataType x)
{

	SListNode* node = (SListNode*)malloc(sizeof(SListNode));//注意不要sizeof(...*),犯病，后面会free错误，其他bug不明显
	if (node == NULL)
	{
		perror("malloc fail\n ");
		exit(-1);
	}

	node->data = x;
	node->next=NULL;//初始化为空
	return node;
}


void PrintSList(SListNode *phead)
{
	SListNode *cur = phead;//current:当前  ->记忆当前的节点地址
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

int SizeSList(SListNode *phead)
{
	SListNode*cur = phead;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

SListNode *FindSList(SListNode *phead, SLDataType x)
{
	SListNode *cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

SListNode* FindElement(SListNode*L, SLDataType x)
{
	if (!L)
	{
		return NULL;
	}
	if (L->data == x)
	{
		return L;
	}
	   return FindElement(L->next, x);
}



//pphead=&phead  //目的要改变phead的值
//*pphead==phead
//**pphead==结构体变量
void PushBackSList(SListNode** pphead, SLDataType x)
{
	//为什么要有这一步，不能合并的原因：当head==NULL，tail->next对NULL解引用，错误
	if (*pphead == NULL)
	{
		SListNode* newnode = CreateSListNode(x);
		*pphead = newnode;//将newnode的值（尾节点的地址）赋给指针变量head
	}
	else
	{
		SListNode* tail = *pphead;//用于寻找、记忆尾节点的指针变量
		while (tail->next != NULL)
		{
			tail = tail->next;//得到下个节点的地址
		}
		SListNode *newnode = CreateSListNode(x);
		tail->next = newnode;//连接上尾节点，将newnode的值（尾节点的地址）赋给指针域
	}
}


void PushFrontSList(SListNode **pphead, SLDataType x)
{
	SListNode *newnode = CreateSListNode(x);
	newnode->next = *pphead;//将新节点链接在头节点前。
	*pphead = newnode;//将newnode的值（首节点的地址）赋给head，使head成为首节点。
}

void PopBackSList(SListNode **pphead)
{
	//1.头空
	//2.只有头
	//3.有多个
	if (*pphead == NULL)//判断空表
	{
		return;
	}

	if ((*pphead)->next == NULL)//不能合并，因为找尾节点需要对next解引用
	{
		*pphead = NULL;
		free(*pphead);//释放头节点
		return;//可以不用return，换成if-else
	}

	SListNode *tail, *prev;//previous
	tail = prev = *pphead;
	while (tail->next != NULL)//找尾节点
	{
		prev = tail;  //先记录当前节点
		tail = tail->next;//再到下个节点
	}
	free(tail);//释放尾节点
	prev->next = NULL;
}

void PopFrontSList(SListNode **pphead)
{
	//1.头空
	//2.只有头
	//3.有多个
	if (*pphead == NULL)
	{
		return;
	}

	//-------可以合并，将next放到头指针
	//if ((*pphead)->next == NULL)
	//{
	//	*pphead = NULL;
	//	free(*pphead);//释放头节点
	//	//return;//可以不用return，换成if-else
	//}
	//else
	//{



	//--方法一
		SListNode *cur = *pphead;//记录下头节点地址
		*pphead = (*pphead)->next;//丢掉头节点：将下一个节点放到头指针
		free(cur);//释放空间
	//--方法二
	//SListNode* next = (*pphead)->next;//记录下后一个节点
	//free(*pphead);//释放掉头节点
	//(*pphead) = next;//将下一个节点放到头指针
}


void InsertSList(SListNode **pphead, SListNode *pos, SLDataType x)
{
	SListNode *newnode = CreateSListNode(x);
	SListNode *prev;
	prev = *pphead;
	if (pos == *pphead)
	{
		//you can also call the Head insertion function  :你也可以使用头插函数
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		//--------方法一
		while (prev->next)
		{
			if (prev->next == pos)
			{
				newnode->next = prev->next;
				prev->next = newnode;
				return;
			}
			prev = prev->next;
		}
		printf("Insert position not find\n");

		//--------方法二
		/*
		while(prev-> != pos)
		{
			prev=prev->next;
		}
		newnode->next = prev->next;
		prev->next = newnode;
		*/
	}
}


void InsertAfterSList(SListNode **pphead, SListNode *pos, SLDataType x)
{
	SListNode *newnode = CreateSListNode(x);

	//方法三:
	newnode->next = pos->next;
	pos->next = newnode;

	//方法一
	//	SListNode *cur = *pphead;
	//	while (cur)
	//	{
	//		if (cur == pos)
	//		{
	//			newnode->next = cur->next;
	//			cur->next = newnode;
	//			return ;
	//		}
	//		cur = cur->next;
	//	}
	//	printf("InsertAfter fail\n");

	/*方法二
	while(cur!=pos)
	{
	cur=cur->next;
	}
	newnode->next=cur->next;
	cur->next=newnode;
	*/

}

void EraseSList(SListNode **pphead, SListNode *pos)
{
	SListNode *prev = *pphead;
	if (*pphead == pos)
	{
		*pphead = prev->next;
		free(prev);
	}
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	prev->next = prev->next->next;
	free(pos);
	pos = NULL;//没用，但是习惯
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);

	SListNode* next = pos->next;
	pos->next = next->next;

	free(next);
	next = NULL;
}

void DesrtoySList(SListNode **pphead)
{
	SListNode *cur = *pphead;
	SListNode *next = cur->next;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;//指针变量要置空
}


