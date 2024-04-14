#define _CRT_SECURE_NO_WARNINGS 1


//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。

//palindrome [ˈpæ lɪndroʊm]
//回文结构：结构相同、方向相反的序列（数据对称链表）
//1->2->2->1 

//练习用写法
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		//1·求中点
		struct ListNode *slow = A, *fast = A;
		while (fast&&fast->next)
		{
			slow = slow -> next;
			fast = fast->next->next;
		}
		//2·逆置
		//头删头插
		struct ListNode *B = slow ;//reverseList
		struct ListNode *newnode;//
		struct ListNode *cur = B;
		while (cur)
		{
			struct ListNode *next = cur->next;
			cur->next = newnode;
			newnode = cur;
			cur = next;
		}
		B = newnode;
		//头删尾插

		//3·比较
		struct ListNode *curA = A, *curB = B;
		while (curA && curB)
		{
			if (curA->val == curB->val)
			{
				curA = curA->next;
				curB = curB->next;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};




//模块化写法
struct ListNode* middleNode(struct ListNode* head){
	struct ListNode *slow, *fast;
	slow = fast = head;
	while (fast&&fast->next)  //fast且fast->next不为空 
	{                            //----- fast为空或fast->next为空则结束
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

struct ListNode* reverseList(struct ListNode* head){
	//初始条件
	struct ListNode* newnode = NULL; //创建新链表
	struct ListNode *cur = head;     //cur指向原链表的头节点
	while (cur)  //分析画图到最后一步，cur为空刚好
	{
		//头插
		//核心逻辑
		//记下原链表下一个节点的地址
		struct ListNode *next = cur->next;
		//cur的next指向头节点，然后新节点cur给给newnode,使newnode指向新节点
		cur->next = newnode;
		newnode = cur;

		//迭代往后走
		cur = next;
	}
	return newnode;
}

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {



		struct ListNode *B = middleNode(A);	//1·求中点
		B = reverseList(B);	//2·逆置
		struct ListNode *curA = A, *curB = B;
		while (curA && curB)	//3·比较
		{
			if (curA->val != curB->val)
			{
				return false;
			}
			else
			{
				curA = curA->next;
				curB = curB->next;
			}
		}
		return true;
	}
};