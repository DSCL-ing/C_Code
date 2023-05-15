#define _CRT_SECURE_NO_WARNINGS 1
#include"DoubleList.h"

void Test1()
{
	ListNode *head=InitList();
	PushFrontList(head,1);
	PushBackList(head, 1);
	int n = ListSize(head);
	printf("%d \n", n);
}


int main()
{
	Test1();
	return 0;
}