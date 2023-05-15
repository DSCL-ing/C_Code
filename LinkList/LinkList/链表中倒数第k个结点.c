#define _CRT_SECURE_NO_WARNINGS 1


//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//链表中倒数第k个结点

//输入一个链表，输出该链表中倒数第k个结点。

/**
* struct ListNode {
*	int val;
*	struct ListNode *next;
* };
*/

//原理：快慢指针，tail先走k步，定两指针距离，然后同步移动指针，快指针到尾时慢指针位置就是倒k
//条件：链表未知大小

//与尾（NULL）相差k或有效尾值相距k-1。

//是指针动，数不动，两个指针定距离移动到末尾

#include<stdio.h>
struct ListNode* FindKthToTail(struct ListNode * pListHead, int k) {
	struct ListNode* fast, *slow;
	fast = slow = pListHead;
	while (fast)  //循环条件：判断fast是否为空
	{
		if (k > 0)  //走K步
		{
			fast = fast->next;
			k--;
		}
		else {       //同步走
			fast = fast->next;
			slow = slow->next;
		}
	}
	if (k > 0)      //k没走完就为空说明k>链表长度
	{
		return NULL;
	}
	return slow;
}

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode* fast, *slow;
	fast = slow = pListHead;
	while (k--)   //   先走K步   O(1)
	{
		if (fast == NULL) //没走完就为空，说明k大于n
		{
			return NULL;
		}
		fast = fast->next;
	}
	while (fast)       //后同步走
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}