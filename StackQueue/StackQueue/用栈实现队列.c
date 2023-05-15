//https://leetcode-cn.com/problems/implement-queue-using-stacks/



#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//˳���ʵ��	

typedef int STDataType;

typedef struct Stack
{
	STDataType *a;
	int top;         //ջ��λ��
	int capacity;    //ջ����
}Stack;//��дST

//����һ��ָ��ʵ��
//��ջԪ�س�ʼ��
void StackInit(Stack *ps);

void StackDestroy(Stack *ps);

void StackPush(Stack *ps, STDataType x);

void StackPop(Stack *ps);

STDataType StackTop(Stack *ps);

bool StackEmpty(Stack *ps);

int StackSize(Stack *ps);

void StackInit(Stack *ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestroy(Stack *ps)
{
	assert(ps);
	if (ps->a)//�ǿգ��пռ�ռ�����ͷ�
	{
		free(ps->a);
	}
	ps->top = 0;
	ps->capacity = 0;
	ps->a = NULL;
}

void StackPush(Stack *ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		Stack *tmp = (Stack *)realloc(ps->a, newcapacity*sizeof(Stack));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->capacity = newcapacity;
		ps->a = tmp;
	}
	ps->a[ps->top] = x;
	ps->top++;//���ú�++
}

void StackPop(Stack *ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

STDataType StackTop(Stack *ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

bool StackEmpty(Stack *ps)
{
	assert(ps);
	return ps->top == 0;//�棨���㣩������tree���٣��㣩������false
}

int StackSize(Stack *ps)
{
	assert(ps);
	return ps->top;
}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------


typedef struct 
{
	Stack S1;
	Stack S2;
} MyQueue;


MyQueue* myQueueCreate() 
{
	MyQueue* Q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&Q->S1);
	StackInit(&Q->S2);
	return Q;
}

void myQueuePush(MyQueue* obj, int x) 
{
	assert(obj);

	StackPush(&obj->S1, x);
}

int myQueuePop(MyQueue* obj) 
{
	assert(obj);
	//if (StackEmpty((&obj->S2)))
	//while (!StackEmpty(&obj->S1))
	//{
	//	StackPush(&obj->S2, StackTop(&obj->S1));
	//	StackPop(&obj->S1);
	//}

	//int front = StackTop(&obj->S2);
	int front = myQueuePeek(obj);
	StackPop(&obj->S2);
	return front;
}

int myQueuePeek(MyQueue* obj) //���ض�ͷ
{

	assert(obj);
	if (StackEmpty(&obj->S2))
		while (!StackEmpty(&obj->S1))
		{
		StackPush(&obj->S2, StackTop(&obj->S1));
		StackPop(&obj->S1);
		}
	//return (&obj->S2)->a[StackSize((&obj->S2) - 1)];
	return StackTop(&obj->S2);
}

bool myQueueEmpty(MyQueue* obj) 
{
	assert(obj);
	return StackEmpty(&obj->S1) && StackEmpty(&obj->S2);
}

void myQueueFree(MyQueue* obj) 
{
	assert(obj);
	StackDestroy(&obj->S1);
	StackDestroy(&obj->S2);
	free(obj);
}