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

//控制变量结构体
//只有一个值，就不用定义结构体，有多个就定义结构题。

typedef struct Queue
{
	struct QueueNode *head; //队头，出队，头删
	struct QueueNode *tail; //队尾，入队，尾插
}Queue;
//是指针变量就传二级指针，是普通变量就传一级

void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);

void QueuePush(Queue *pq, QDataType x);
void QueuePop(Queue *pq);

QDataType QueueFront(Queue *pq);
QDataType QueueBack(Queue *pq);

int QueueSize(Queue *pq);
bool QueueEmpty(Queue *pq);
