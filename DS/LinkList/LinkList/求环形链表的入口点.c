#define _CRT_SECURE_NO_WARNINGS 1


//https://leetcode-cn.com/problems/linked-list-cycle-ii/

//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

//法一：需证明前提结论：
	//结论：设head到入环点长度为l，到相遇点长度为l+x ， 则从相遇点开始一直走的距离等于从head开始走到入环点的距离，并且他们会在入环点相遇。
	//证明：
	//2(l+x) = l+nC+x;
	//化简 l = nC - x;  
	//l = (n - 1)C + C - x; 
	//即l的距离为n-1个环的和加上相遇点到入环点的长度 ， 得证
//1·练习示例
struct ListNode *detectCycle(struct ListNode *head) {
	//1·求环确认点
	struct ListNode* fast;
	struct ListNode* slow;
	slow = fast = head;
	while (fast && fast->next)  //找环确定点
	{
	fast = fast->next->next;
	slow = slow->next;
	if (fast == slow)  //不能先比较，第一个就会pass
	{
		printf("%d,%d\n", slow->val, fast->val);
		break;
	}
	}
	//必须写在循环外，循环内执行不到
	if (fast == NULL || fast->next == NULL)  //不是环则返回空
	{
		return NULL;
	}
	//2·公式法求入环点
	struct ListNode * tail1 = head;
	struct ListNode * tail2 = fast;
	while (tail1 != tail2)
	{
		tail1 = tail1->next;
		tail2 = tail2->next;
	}
	return tail1;
}

//2·优化示例
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* fast;
	struct ListNode* slow;
	slow = fast = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)  //找到相遇点了，执行下一步
		{
			struct ListNode * tail = head; 
			while (tail != fast)  //相同就是入环点
			{
				tail = tail->next;
				fast = fast->next;
			}
			return tail; //返回入环点
		}
	}
	return NULL; //fast 为空，说明是无环链表。
}



//法二：求交点法，求差(不能调用接口，接口仅适用不带环链表)
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* fast ;
	struct ListNode* slow;
	slow = fast = head;
	//-------------------------------------------错误示例
	//while (fast != slow)  //开局就相等-------------------------<
	//{
	//	if (fast == NULL || fast->next == NULL)
	//	{
	//		printf("不带环\n");
	//		return NULL;
	//	}
	//	fast = fast->next->next;
	//	slow = slow->next;
	//}

	while (fast && fast->next)  //找环确定点
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)  //不能先比较，第一个就会pass
		{
			printf("%d,%d\n", slow->val, fast->val);
			break;
		}
	}
	//必须写在循环外，循环内执行不到
	if (fast == NULL || fast->next == NULL)  //不是环则返回空
	{
		return NULL;
	}

	
//--------------这下面可以当作求有环链表节点的接口函数了-------------------
//--------------这下面可以当作求有环链表节点的接口函数了-------------------
	-- -

	//把环确定点当作终点，环确定点的下一个节点为头
	struct ListNode* tail1 = head;
	struct ListNode* tail2 = fast->next;  

	//len为1好，因为len2会和fast->next相等---->寄
	int len1 = 1, len2 = 1;
	//计算1长度
	while (tail1->next != fast->next)
	{
		len1++;
		tail1 = tail1->next;
	}

	//计算2长度
	while (tail2->next != fast->next)
	{
		len2++;
		tail2 = tail2->next;
	}

	//找交点（入口点）
	int gap = abs(len1 - len2);
	//printf("len1 = %d , len2 = %d , gap = %d \n", len1, len2, gap);  leetcode测试用
	struct ListNode* longList = head;
	struct ListNode* shortList = fast->next;
	if (len1 < len2)
	{
		longList = fast->next;
		shortList = head;
	}
	
	while (gap--)
	{
		longList = longList->next;
	}

	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}

	return longList;
}


