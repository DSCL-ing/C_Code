#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"


void TestSeqList1()
{
	SL s1;
	InitSeqList(&s1);
	PushBack(&s1, 1);
	PushBack(&s1, 2);
	PushBack(&s1, 3);
	PushBack(&s1, 4);
	PushBack(&s1, 5);
	PopBack(&s1);
	PopFront(&s1);
	Print(&s1);
	SLDestory(&s1);

}

void TestSeqList2()
{
	SL s1;
	InitSeqList(&s1);
	PushBack(&s1, 1);
	PushBack(&s1, 2);
	PushBack(&s1, 3);
	PushBack(&s1, 4);
	PushBack(&s1, 5);
	Print(&s1);
	PushFront(&s1, 1);
	PushFront(&s1, 2);
	PushFront(&s1, 3);
	PushFront(&s1, 4);
	Print(&s1);
	SLDestory(&s1);

}


int main()
{
	TestSeqList1();
	//TestSeqList2();
	return 0;
}