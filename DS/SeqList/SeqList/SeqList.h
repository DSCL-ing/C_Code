#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<stdio.h>


typedef int SLDataType;

#define FORMAT "%d"  //格式

typedef struct SeqList
{
	SLDataType *a;
	int size;
	int capacity;
}SL;


//初始化
void InitSeqList(SL*ps);//

//打印
void Print(SL*ps);

//尾插
void PushBack(SL* ps,SLDataType x);

//头插
void PushFront(SL*ps, SLDataType x);

//尾删
void PopBack(SL*ps);

//头删
void PopFront(SL*ps);

//内存释放
void SLDestory(SL*ps);

//查找
int SLFind(SL*ps);

//插入
void SLInsert(SL*ps, int pos, SLDataType x);
