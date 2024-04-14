#define _CRT_SECURE_NO_WARNINGS 1

//203. 移除链表元素
//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足
//Node.val == val 的节点，并返回 新的头节点 。


//1·头删
//2·中间删


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