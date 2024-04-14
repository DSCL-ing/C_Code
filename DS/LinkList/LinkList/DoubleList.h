#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#pragma once

//有头双向循环链表
//结构复杂，操作反而简单

typedef int ListDataType;

typedef struct ListNode
{
	struct ListNode *prev;
	ListDataType data;
	struct ListNode *next;
}ListNode;


void Print(ListNode *phead);

//void ListNode(ListNode **pphead);  //改变头地址---不太合适了
ListNode *InitList(void);          //返回值，返回哨兵卫

//保持接口一致性，用一级指针



//创建新节点
ListNode *CreateListNode(ListDataType x);


//初始化
//创建哨兵卫
//初始化成员
ListNode *InitList(void);


//尾插
void PushBackList(ListNode *phead, ListDataType x);


//头插
void PushFrontList(ListNode *phead, ListDataType x);


//尾删
void PopBackList(ListNode *phead);


//头插
void PopFrontList(ListNode *phead);


ListNode *FindList(ListNode *phead, ListDataType x);


//--------------------带头双向循环链表好处
//pos就是所在节点的地址，不用头指针phead
void InsertList(ListNode *pos, ListDataType x);//用不到phead
//Insert和Erase 效率很高，直接插直接删，不用查找，且包含头尾插删
void EraseList(ListNode *pos);//用不到phead


//销毁
void DestroyList(ListNode *phead);

size_t ListSize(ListNode *phead);
