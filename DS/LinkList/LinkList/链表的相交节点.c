#define _CRT_SECURE_NO_WARNINGS 1

//---------------仅使用无环链表--------------------------------

//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/

//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
//如果两个链表不存在相交节点，返回 null 。

//intersection   美[ˈɪntərˌsekʃ(ə)n]  交集；交叉点；交点 交叉；相交；十字路口；交叉路口
//gap  美[ɡæp]   差距；间隙；缺口；间隔
//absolute   美[ˌæbsəˈlut]  完全的；全部的；绝对的；

//1·判断是否相交：分别遍历，尾节点相同则相交（交点后的所有节点必定相同）
//2·找交点
	//a·找长度差k，然后长的走k步使起点相同（计数器）,一样要遍历，故放1一起
	//b·循环比较节点地址，相等即是交点， 

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* tailA = headA, *tailB = headB;
	int lenA = 0, lenB = 0;

	//如果默认链表不为空，可设lenA = 1，循环条件为tail->next;

	while (tailA)  //A遍历，   
	{
		lenA++;
		tailA = tailA->next;
	}

	while (tailB)  //B遍历
	{
		lenB++;
		tailB = tailB->next;
	}

	//判断A、B尾节点是否相等（地址）
	if (tailA != tailB)  
	{
		return NULL;
	}

	//长度差，绝对值abs  <math.h>
	int gap = abs(lenA - lenB);

	//自动判断长短链表
	//先假设A长B短
	struct ListNode* longList = headA;
	struct ListNode* shortList = headB;
	if (lenA < lenB)  //不是再调整
	{
		longList = headB;
		shortList = headA;
	}

	//长的先走gap步
	while (gap--)
	{
		longList = longList->next;
	}

	//一起走，直到相等即交点
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
	return shortList;
}

















