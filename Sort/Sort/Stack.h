#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//顺序表实现	
struct QSData
{
	int begin;
	int end;
};

typedef struct QSData STDataType;

typedef struct Stack
{
	STDataType *a; 
	int top;         //栈顶位置
	int capacity;    //栈容量
}Stack;//缩写ST

//都用一级指针实现
//对栈元素初始化
void StackInit(Stack *ps);

void StackDestroy(Stack *ps);

void StackPush(Stack *ps, STDataType x);

void StackPop(Stack *ps);

STDataType StackTop(Stack *ps);

bool StackEmpty(Stack *ps);

int StackSize(Stack *ps);