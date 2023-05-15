#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//˳���ʵ��	
struct QSData
{
	int begin;
	int end;
};

typedef struct QSData STDataType;

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