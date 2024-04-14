#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode-cn.com/problems/middle-of-the-linked-list/description/


//876. ������м���
//����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣


struct ListNode {
	int val;
	struct ListNode *next;
};

//fast and slow pointe

//˼�룺һ��һ����һ����һ��һ��������
//һ�����������м�ֵ��һ����һ����ֵ��(2n+1)/2      ->��ѧ������������
//0 1 2 3 4 5 6 7 8 9  
//���������ǲ�����0
//ֱ��1 2 3 4 5 6 7 8 9 ���м�ֵ��5.
struct ListNode* middleNode(struct ListNode* head){
	//1 2 3 
	//1 3 5 NULL
	//1 2 3 4
	//1 3 5 6 NULL
	
	struct ListNode *n1, *n2;
	n1 = n2 = head;
	while (n2)          //ʵ���ǵ�n2->next->next == NULLʱ�˳�ѭ��
	{
		if (!n2->next)   
		{
			return n1;  //ʵ����n2->nextΪ��ʱ���˳�ѭ��
		}
		n1 = n1->next;
		n2 = n2->next->next;
	}
	return n1;
}

//�Ż�
struct ListNode* middleNode(struct ListNode* head){
	struct ListNode *slow, *fast;
	slow = fast = head;
	while (fast&&fast->next)  //fast��fast->next��Ϊ�� 
	{                            //���� fastΪ�ջ�fast->nextΪ�������
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}



#include<stdio.h>
#include<stdlib.h>
int main()  //�Լ������ṹ���ģ��
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
	middleNode(n1); //���ýӿ�
	//����
	return 0;
}