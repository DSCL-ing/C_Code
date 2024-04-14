#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode-cn.com/problems/middle-of-the-linked-list/description/


//876. 链表的中间结点
//给定一个头结点为 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。


struct ListNode {
	int val;
	struct ListNode *next;
};

//fast and slow pointe

//思想：一个一次走一步，一个一次走两步
//一次走两部的中间值是一次走一步的值，(2n+1)/2      ->数学计算上是这样
//0 1 2 3 4 5 6 7 8 9  
//物理上我们不考虑0
//直接1 2 3 4 5 6 7 8 9 的中间值是5.
struct ListNode* middleNode(struct ListNode* head){
	//1 2 3 
	//1 3 5 NULL
	//1 2 3 4
	//1 3 5 6 NULL
	
	struct ListNode *n1, *n2;
	n1 = n2 = head;
	while (n2)          //实际是当n2->next->next == NULL时退出循环
	{
		if (!n2->next)   
		{
			return n1;  //实际是n2->next为空时，退出循环
		}
		n1 = n1->next;
		n2 = n2->next->next;
	}
	return n1;
}

//优化
struct ListNode* middleNode(struct ListNode* head){
	struct ListNode *slow, *fast;
	slow = fast = head;
	while (fast&&fast->next)  //fast且fast->next不为空 
	{                            //《》 fast为空或fast->next为空则结束
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}



#include<stdio.h>
#include<stdlib.h>
int main()  //自己创建结构体的模板
{
	struct ListNode *n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;
	n5->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	middleNode(n1); //调用接口
	//调试
	return 0;
}