#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>


//https://leetcode-cn.com/problems/merge-two-sorted-lists/description/

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有
//结点组成的

struct ListNode {                   ////leetcode 会给结构体
	int val;
	struct ListNode *next;
};

//其他思路有：把一个链表合并到另一个链表，想着简单，超级麻烦。（少判断才好啊）
//（每次都比较被插的链表，大于前一个小于后一个才能插进去 ，...，小于插前，都大比下下个...）

	//思路：比较两链表中头元素，谁小把谁放入新链表
//新手写法，一点一点的写法，愚蠢！！！
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
			list1 = cur1->next;//断链
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
	//		list2 = cur2->next;//断链
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
	//		list1 = cur1->next;//断链
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


//熟练写法，链表技巧（链表和数组的区别，优势）
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
				head = tail = list1;//直接将链表1拿过来
			}
			else
			{
				tail->next = list1;//接上链表1
				tail = list1;//链表1的头为下一个尾
			}
			list1 = list1->next;//链表1头节点的下一个为新头
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
	if (list1)//在上面判断出链表2清空的前提下链表1还有节点
	{
		tail->next = list1; //直接接上链表1
	}
	if (list2)
	{
		tail->next = list2;
	}
	return head;
}

//小优化1，不用每次判断头
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

	if (list1->val < list2->val)  //开始就先链接上链表1或链表2当头节点。
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

			tail->next = list1;//接上链表1
			tail = list1;//链表1的头为下一个尾
			list1 = list1->next;//链表1头节点的下一个为新头
		}
		else
		{

			tail->next = list2;
			tail = list2;
			list2 = list2->next;
		}
	}
	if (list1)//在上面判断出链表2清空的前提下链表1还有节点
	{
		tail->next = list1; //直接接上链表1
	}
	if (list2)
	{
		tail->next = list2;
	}
	return head;
}

//小优化2，不判断头了，带哨兵卫直接中间插，
//和1各有得失，1直接返回，不用释放。2不用判断头，需要释放
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
	//谁开辟谁释放

	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{

			tail->next = list1;//接上链表1
			tail = list1;//链表1的头为下一个尾
			list1 = list1->next;//链表1头节点的下一个为新头
		}
		else
		{

			tail->next = list2;
			tail = list2;
			list2 = list2->next;
		}
	}
	if (list1)//在上面判断出链表2清空的前提下链表1还有节点
	{
		tail->next = list1; //直接接上链表1
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
int main()  //自己创建结构体的模板
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
	//调试

	return 0;
}




