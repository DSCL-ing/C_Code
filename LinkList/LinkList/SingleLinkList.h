#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SListNode//SingleList
{
	SLDataType data;
	struct SListNode*next;//自己定义自己类型的指针

}SListNode;



//SListNode* phead = NULL;//非哨兵卫，只是起始，调用插入函数后变成表头
//


// 要改变传过来的指向第一个节点的指针就传二级
// 不改变传过来的指向第一个节点的指针就传一级
// 只读的函数接口传一级


//创建节点
//开辟空间、返回地址：销毁变量，但地址有效
SListNode * CreateSListNode(SLDataType x);

//---------------------------一级指针----------//

//打印链表元素
void PrintSList(SListNode *phead);

//计算链表大小
int SizeSList(SListNode *phead);

//查找
SListNode *FindSList(SListNode *phead, SLDataType x);

//----------------------------------------------//


//---------------------------二级指针----------//

//尾插
//判断是否空表:
//是空表->调用CreateNode；
//非空->找尾插入
void PushBackSList(SListNode **phead, SLDataType x);




//头插
//不用判断
void PushFrontSList(SListNode **pphead,SLDataType x);


//尾删
void PopBackSList(SListNode **pphead);


//头删
void PopFrontSList(SListNode **pphead);


//释放空间
void DestroySListNode(SListNode**phead);

//----------------------------------------------//


/*
单项链表缺陷
前插必须要知前节点
*/



//pos位置前插x
//需要配合Find使用
void InsertSList(SListNode **pphead, SListNode *pos, SLDataType x);



//pos位置后插x;
//需要配合Find使用;
void InsertAfterSList(SListNode **pphead, SListNode *pos, SLDataType x);


//擦除
void EraseSList(SListNode **pphead, SListNode *pos);


void SListEraseAfter(SListNode* pos);

SListNode* FindElement(SListNode*L, SLDataType x);