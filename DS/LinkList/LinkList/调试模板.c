#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

struct ListNode {                   //leetcode会给结构体
    int val;
    struct ListNode *next;
};


struct ListNode* removeElements(struct ListNode* head, int val){
	struct  ListNode *cur, *prev;
	cur = head; prev = head;
	while (cur)
	{
		if (cur->val == val)
		{
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;

			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}






int main()  //自己创建结构体的模板
{
	struct ListNode *n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	removeElements(n1, 2); //调用接口
	//调试

	return 0;
}

