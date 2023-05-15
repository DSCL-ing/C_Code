#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<stdio.h>


typedef int SLDataType;

#define FORMAT "%d"  //��ʽ

typedef struct SeqList
{
	SLDataType *a;
	int size;
	int capacity;
}SL;


//��ʼ��
void InitSeqList(SL*ps);//

//��ӡ
void Print(SL*ps);

//β��
void PushBack(SL* ps,SLDataType x);

//ͷ��
void PushFront(SL*ps, SLDataType x);

//βɾ
void PopBack(SL*ps);

//ͷɾ
void PopFront(SL*ps);

//�ڴ��ͷ�
void SLDestory(SL*ps);

//����
int SLFind(SL*ps);

//����
void SLInsert(SL*ps, int pos, SLDataType x);
