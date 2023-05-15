#define _CRT_SECURE_NO_WARNINGS 1


//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//�����е�����k�����

//����һ����������������е�����k����㡣

/**
* struct ListNode {
*	int val;
*	struct ListNode *next;
* };
*/

//ԭ������ָ�룬tail����k��������ָ����룬Ȼ��ͬ���ƶ�ָ�룬��ָ�뵽βʱ��ָ��λ�þ��ǵ�k
//����������δ֪��С

//��β��NULL�����k����Чβֵ���k-1��

//��ָ�붯��������������ָ�붨�����ƶ���ĩβ

#include<stdio.h>
struct ListNode* FindKthToTail(struct ListNode * pListHead, int k) {
	struct ListNode* fast, *slow;
	fast = slow = pListHead;
	while (fast)  //ѭ���������ж�fast�Ƿ�Ϊ��
	{
		if (k > 0)  //��K��
		{
			fast = fast->next;
			k--;
		}
		else {       //ͬ����
			fast = fast->next;
			slow = slow->next;
		}
	}
	if (k > 0)      //kû�����Ϊ��˵��k>������
	{
		return NULL;
	}
	return slow;
}

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode* fast, *slow;
	fast = slow = pListHead;
	while (k--)   //   ����K��   O(1)
	{
		if (fast == NULL) //û�����Ϊ�գ�˵��k����n
		{
			return NULL;
		}
		fast = fast->next;
	}
	while (fast)       //��ͬ����
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}