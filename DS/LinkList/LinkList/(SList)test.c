#define _CRT_SECURE_NO_WARNINGS 1





#include"SingleLinkList.h"
//void TestSList1()
//{
//	SListNode *head = NULL;
//	PrintSList(head);
//	PushBackSList(&head, 1);
//	PushBackSList(&head, 2);
//	PushBackSList(&head, 3);
//	//PushFrontSList(&head, 1);
//	//PushFrontSList(&head, 2);
//	//PushFrontSList(&head, 3);
//	PrintSList(head);
//	PopFrontSList(&head);
//	//PopFrontSList(&head);
//	//PopFrontSList(&head);
//	//PopFrontSList(&head);
//	//PopFrontSList(&head);
//	PopBackSList(&head);
//
//	PrintSList(head);
//}
//
//void TestSList2()//Find的妙用
//{
//	SListNode *head = NULL;
//
//	PushBackSList(&head, 1);
//	PushBackSList(&head, 2);
//	PushBackSList(&head, 3);
//	PushBackSList(&head, 2);
//	PushBackSList(&head, 5);
//	PrintSList(head);
//	SListNode *pos = FindSList(head,2);
//	while (pos) //找其他重复的元素
//	{
//		printf("%p\n",pos);
//		pos = FindSList(pos->next, 2);//
//	}
//
//	//pos定义成指针变量的好处
//	pos = FindSList(head,3);
//	if (pos)
//	{
//		pos->data = 30;//能直接修改Find到的值
//	}
//	PrintSList(head);
//	pos=FindSList(head,6);
//	InsertSList(&head, pos, 999);
//
//	PrintSList(head);
//
//
//}

void TestSList3()
{
	int a[] = { 7, 6, 5, 4, 3, };
	SListNode *head = NULL;
	for (int i = 0; i < 5; ++i)
	{
		PushBackSList(&head,a[i]);
	}
	SListNode* tmp = FindElement(head, 4);
	printf("%d", tmp->data);

}

int main()
{
	//TestSList1();
	//TestSList2();
	TestSList3();


	return 0;
}