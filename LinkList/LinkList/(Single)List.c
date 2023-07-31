#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleLinkList.h"

//����Ŀ�ģ������γ���

SListNode* CreateSListNode(SLDataType x)
{

	SListNode* node = (SListNode*)malloc(sizeof(SListNode));//ע�ⲻҪsizeof(...*),�����������free��������bug������
	if (node == NULL)
	{
		perror("malloc fail\n ");
		exit(-1);
	}

	node->data = x;
	node->next=NULL;//��ʼ��Ϊ��
	return node;
}


void PrintSList(SListNode *phead)
{
	SListNode *cur = phead;//current:��ǰ  ->���䵱ǰ�Ľڵ��ַ
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



//pphead=&phead  //Ŀ��Ҫ�ı�phead��ֵ
//*pphead==phead
//**pphead==�ṹ�����
void PushBackSList(SListNode** pphead, SLDataType x)
{
	//ΪʲôҪ����һ�������ܺϲ���ԭ�򣺵�head==NULL��tail->next��NULL�����ã�����
	if (*pphead == NULL)
	{
		SListNode* newnode = CreateSListNode(x);
		*pphead = newnode;//��newnode��ֵ��β�ڵ�ĵ�ַ������ָ�����head
	}
	else
	{
		SListNode* tail = *pphead;//����Ѱ�ҡ�����β�ڵ��ָ�����
		while (tail->next != NULL)
		{
			tail = tail->next;//�õ��¸��ڵ�ĵ�ַ
		}
		SListNode *newnode = CreateSListNode(x);
		tail->next = newnode;//������β�ڵ㣬��newnode��ֵ��β�ڵ�ĵ�ַ������ָ����
	}
}


void PushFrontSList(SListNode **pphead, SLDataType x)
{
	SListNode *newnode = CreateSListNode(x);
	newnode->next = *pphead;//���½ڵ�������ͷ�ڵ�ǰ��
	*pphead = newnode;//��newnode��ֵ���׽ڵ�ĵ�ַ������head��ʹhead��Ϊ�׽ڵ㡣
}

void PopBackSList(SListNode **pphead)
{
	//1.ͷ��
	//2.ֻ��ͷ
	//3.�ж��
	if (*pphead == NULL)//�жϿձ�
	{
		return;
	}

	if ((*pphead)->next == NULL)//���ܺϲ�����Ϊ��β�ڵ���Ҫ��next������
	{
		*pphead = NULL;
		free(*pphead);//�ͷ�ͷ�ڵ�
		return;//���Բ���return������if-else
	}

	SListNode *tail, *prev;//previous
	tail = prev = *pphead;
	while (tail->next != NULL)//��β�ڵ�
	{
		prev = tail;  //�ȼ�¼��ǰ�ڵ�
		tail = tail->next;//�ٵ��¸��ڵ�
	}
	free(tail);//�ͷ�β�ڵ�
	prev->next = NULL;
}

void PopFrontSList(SListNode **pphead)
{
	//1.ͷ��
	//2.ֻ��ͷ
	//3.�ж��
	if (*pphead == NULL)
	{
		return;
	}

	//-------���Ժϲ�����next�ŵ�ͷָ��
	//if ((*pphead)->next == NULL)
	//{
	//	*pphead = NULL;
	//	free(*pphead);//�ͷ�ͷ�ڵ�
	//	//return;//���Բ���return������if-else
	//}
	//else
	//{



	//--����һ
		SListNode *cur = *pphead;//��¼��ͷ�ڵ��ַ
		*pphead = (*pphead)->next;//����ͷ�ڵ㣺����һ���ڵ�ŵ�ͷָ��
		free(cur);//�ͷſռ�
	//--������
	//SListNode* next = (*pphead)->next;//��¼�º�һ���ڵ�
	//free(*pphead);//�ͷŵ�ͷ�ڵ�
	//(*pphead) = next;//����һ���ڵ�ŵ�ͷָ��
}


void InsertSList(SListNode **pphead, SListNode *pos, SLDataType x)
{
	SListNode *newnode = CreateSListNode(x);
	SListNode *prev;
	prev = *pphead;
	if (pos == *pphead)
	{
		//you can also call the Head insertion function  :��Ҳ����ʹ��ͷ�庯��
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		//--------����һ
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

		//--------������
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

	//������:
	newnode->next = pos->next;
	pos->next = newnode;

	//����һ
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

	/*������
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
	pos = NULL;//û�ã�����ϰ��
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
	*pphead = NULL;//ָ�����Ҫ�ÿ�
}


