#define _CRT_SECURE_NO_WARNINGS 1


//https://leetcode-cn.com/problems/reverse-linked-list/description/

//206. 反转链表
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//（这个头节点不是哨兵卫）


//struct ListNode {
//	int val;
//	struct ListNode *next;
//};

//1·改箭头法：用多个指针变量控制进行箭头翻转
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	//初始条件
	struct ListNode* n1 = NULL;    
	struct ListNode* n2 = head; 
	struct ListNode* n3 = head->next;
	while (n2)  //循环最后一步要求，通过控制n3在最后时不再前进，防止NULL解引用，
	{                                          //让最后一步翻转得以进行
		//核心逻辑:翻转
		n2->next = n1;

		//迭代往后走
		n1 = n2;   
		n2 = n3;
		if (n3) //指针指太远了，让最后一步进行，同时使n3不动。
		{
			n3 = n3->next;
		}
	}
	return n1;//n1为翻转后的头节点。

}


//法二：头插到新头指针。
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