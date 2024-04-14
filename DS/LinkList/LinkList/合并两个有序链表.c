#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>


//https://leetcode-cn.com/problems/merge-two-sorted-lists/description/

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ������������������
//�����ɵ�

struct ListNode {                   ////leetcode ����ṹ��
	int val;
	struct ListNode *next;
};

//����˼·�У���һ������ϲ�����һ���������ż򵥣������鷳�������жϲźð���
//��ÿ�ζ��Ƚϱ������������ǰһ��С�ں�һ�����ܲ��ȥ ��...��С�ڲ�ǰ����������¸�...��

	//˼·���Ƚ���������ͷԪ�أ�˭С��˭����������
//����д����һ��һ���д�����޴�������
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	if (!list1)
	{
		return list2;
	}
	if (!list2)
	{
		return list1;
	}
	struct ListNode *newnode = NULL;
	struct ListNode *cur1, *cur2, *cur =NULL;
	cur1 = list1; cur2 = list2; 
	struct ListNode *next = NULL;
	while (list1&&list2)
	{
		if (cur1->val <= cur2->val)
		{
			list1 = cur1->next;//����
			if (!newnode)
			{
				cur = cur1;
				cur1 = list1;
				cur->next = NULL;
				newnode = cur;
				next = cur->next;
			}
			else
			{
				cur1->next = next;
				cur->next = cur1;
				cur1 = list1;
				cur = cur->next;
				next = cur->next;
			}
		}
		else
		{
			list2 = cur2->next;
			if (!newnode)
			{
				cur = cur2;
				cur2 = list2;
				cur->next = NULL;
				newnode = cur;
				next = cur->next;

			}
			else
			{
				cur2->next = next;
				cur->next = cur2;
				cur2 = list2;
				cur = cur->next;
				next = cur->next;
			}
		}
	}
	//if (!list1)
	//{
	//	while (list2)
	//	{
	//		list2 = cur2->next;//����
	//		cur2->next = next;
	//		cur->next = cur2;
	//		cur2 = list2;
	//		cur = cur->next;
	//		next = cur->next;
	//	}
	//}
	//if (!list2)
	//{
	//	while (list1)
	//	{
	//		list1 = cur1->next;//����
	//		cur1->next = next;
	//		cur->next = cur1;
	//		cur1 = list1;
	//		cur = cur->next;
	//		next = cur->next;
	//	}
	//}
	if (!list1)
	{
		cur->next = list2;
	}
	if (!list2)
	{
		cur->next = list1;
	}
	return newnode;
}


//����д���������ɣ������������������ƣ�
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	struct ListNode *head = NULL, *tail = NULL;
	if (!list1)
	{
		return list2;
	}
	if (!list2)
	{
		return list1;
	}
	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			if (!head)
			{
				head = tail = list1;//ֱ�ӽ�����1�ù���
			}
			else
			{
				tail->next = list1;//��������1
				tail = list1;//����1��ͷΪ��һ��β
			}
			list1 = list1->next;//����1ͷ�ڵ����һ��Ϊ��ͷ
		}
		else
		{
			if (!head)
			{
				head = tail = list2;
			}
			else
			{
				tail->next = list2;
				tail = list2;
			}
			list2 = list2->next;
		}
	}
	if (list1)//�������жϳ�����2��յ�ǰ��������1���нڵ�
	{
		tail->next = list1; //ֱ�ӽ�������1
	}
	if (list2)
	{
		tail->next = list2;
	}
	return head;
}

//С�Ż�1������ÿ���ж�ͷ
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	struct ListNode *head = NULL, *tail = NULL;
	if (!list1)
	{
		return list2;
	}
	if (!list2)
	{
		return list1;
	}

	if (list1->val < list2->val)  //��ʼ��������������1������2��ͷ�ڵ㡣
	{
		head = tail = list1;
		list1 = list1->next;
	}
	else
	{
		head = tail = list2;
		list2 = list2->next;
	}
	

	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{

			tail->next = list1;//��������1
			tail = list1;//����1��ͷΪ��һ��β
			list1 = list1->next;//����1ͷ�ڵ����һ��Ϊ��ͷ
		}
		else
		{

			tail->next = list2;
			tail = list2;
			list2 = list2->next;
		}
	}
	if (list1)//�������жϳ�����2��յ�ǰ��������1���нڵ�
	{
		tail->next = list1; //ֱ�ӽ�������1
	}
	if (list2)
	{
		tail->next = list2;
	}
	return head;
}

//С�Ż�2�����ж�ͷ�ˣ����ڱ���ֱ���м�壬
//��1���е�ʧ��1ֱ�ӷ��أ������ͷš�2�����ж�ͷ����Ҫ�ͷ�
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	struct ListNode *head = NULL, *tail = NULL;
	if (!list1)
	{
		return list2;
	}
	if (!list2)
	{
		return list1;
	}

	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
	//˭����˭�ͷ�

	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{

			tail->next = list1;//��������1
			tail = list1;//����1��ͷΪ��һ��β
			list1 = list1->next;//����1ͷ�ڵ����һ��Ϊ��ͷ
		}
		else
		{

			tail->next = list2;
			tail = list2;
			list2 = list2->next;
		}
	}
	if (list1)//�������жϳ�����2��յ�ǰ��������1���нڵ�
	{
		tail->next = list1; //ֱ�ӽ�������1
	}
	if (list2)
	{
		tail->next = list2;
	}
	struct ListNode *list = head->next;
	free(head);
	return;list;
}

#include<stdio.h>
#include<stdlib.h>
int main()  //�Լ������ṹ���ģ��
{
	struct ListNode *n11 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n12 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n13 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n14 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n11->val = 1;
	n12->val = 2;
	n13->val = 3;
	n14->val = 4;
	n11->next = n12;
	n12->next = n13;
	n13->next = n14;
	n14->next = NULL;

	struct ListNode *n21 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n22 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n23 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n24 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n21->val = 1;
	n22->val = 2;
	n23->val = 3;
	n24->val = 4;
	n21->next = n22;
	n22->next = n23;
	n23->next = n24;
	n24->next = NULL;


	mergeTwoLists(n11, n21);
	//����

	return 0;
}




