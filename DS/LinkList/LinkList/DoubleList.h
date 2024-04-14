#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#pragma once

//��ͷ˫��ѭ������
//�ṹ���ӣ�����������

typedef int ListDataType;

typedef struct ListNode
{
	struct ListNode *prev;
	ListDataType data;
	struct ListNode *next;
}ListNode;


void Print(ListNode *phead);

//void ListNode(ListNode **pphead);  //�ı�ͷ��ַ---��̫������
ListNode *InitList(void);          //����ֵ�������ڱ���

//���ֽӿ�һ���ԣ���һ��ָ��



//�����½ڵ�
ListNode *CreateListNode(ListDataType x);


//��ʼ��
//�����ڱ���
//��ʼ����Ա
ListNode *InitList(void);


//β��
void PushBackList(ListNode *phead, ListDataType x);


//ͷ��
void PushFrontList(ListNode *phead, ListDataType x);


//βɾ
void PopBackList(ListNode *phead);


//ͷ��
void PopFrontList(ListNode *phead);


ListNode *FindList(ListNode *phead, ListDataType x);


//--------------------��ͷ˫��ѭ������ô�
//pos�������ڽڵ�ĵ�ַ������ͷָ��phead
void InsertList(ListNode *pos, ListDataType x);//�ò���phead
//Insert��Erase Ч�ʺܸߣ�ֱ�Ӳ�ֱ��ɾ�����ò��ң��Ұ���ͷβ��ɾ
void EraseList(ListNode *pos);//�ò���phead


//����
void DestroyList(ListNode *phead);

size_t ListSize(ListNode *phead);
