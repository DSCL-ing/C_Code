#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode *next;
	QDataType data;
}QNode;

//���Ʊ����ṹ��
//ֻ��һ��ֵ���Ͳ��ö���ṹ�壬�ж���Ͷ���ṹ�⡣

typedef struct Queue
{
	struct QueueNode *head; //��ͷ�����ӣ�ͷɾ
	struct QueueNode *tail; //��β����ӣ�β��
}Queue;
//��ָ������ʹ�����ָ�룬����ͨ�����ʹ�һ��

void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);

void QueuePush(Queue *pq, QDataType x);
void QueuePop(Queue *pq);

QDataType QueueFront(Queue *pq);
QDataType QueueBack(Queue *pq);

int QueueSize(Queue *pq);
bool QueueEmpty(Queue *pq);
