//https://leetcode-cn.com/problems/valid-parentheses/

#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//顺序表实现	

typedef char STDataType;

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
	if (ps->a)//非空，有空间占用再释放
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
		STDataType *tmp = (STDataType *)realloc(ps->a, newcapacity*sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->capacity = newcapacity;
		ps->a = tmp;
	}
	ps->a[ps->top] = x;
	ps->top++;//先用后++
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
	return ps->top == 0;//真（非零）：返回tree。假（零）：返回false
}

int StackSize(Stack *ps)
{
	assert(ps);
	return ps->top;
}


bool isValid(char * s){
	Stack stack;
	StackInit(&stack);
	//遇到左括号，入栈
	//遇到右括号，出栈匹配，
	//如果栈为空，错误，
	//如果不对，错误。对了，下一个
	//结束时栈不为空，错误



	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
		{
			StackPush(&stack, *s);
		}
		else
		{
			if (StackEmpty(&stack))
			{
				StackDestroy(&stack);
				return false;
			}
			if (*s == ')'&&'('== StackTop(&stack) ||
				*s == '}'&&'{' == StackTop(&stack)||
				*s == ']'&&'[' == StackTop(&stack))
			{
				StackPop(&stack);
			}
			else
			{
				StackDestroy(&stack);
				return false;
			}
		}

		s++;
	}
	if (!StackEmpty(&stack))
	{
		StackDestroy(&stack);
		return false;
	}
	StackDestroy(&stack);
	return true;
}

bool isValid2_1(char * s){
	Stack stack;
	StackInit(&stack);
	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
		{
			StackPush(&stack, *s);
		}
		else
		{
			if (StackEmpty(&stack))
			{
				StackDestroy(&stack);
				return false;
			}
			STDataType top = StackTop(&stack);
			StackPop(&stack);

			if (*s == ')'&&'(' == top ||
				*s == '}'&&'{' == top ||
				*s == ']'&&'[' == top)
			{
				s++;
			}
			else
			{
				StackDestroy(&stack);
				return false;
			}
		}
		s++;
	}
	bool ret = StackEmpty(&stack);
	StackDestroy(&stack);
	return ret;
}

bool isValid2_2(char *s)
{
	Stack stack;
	StackInit(&stack);
	while (*s)
	{
		switch (*s)
		{
		case '(':
		case '{':
		case '[':
		{
			StackPush(&stack , *s);
			s++;
			break;
		}
		case ')':
		case '}':
		case ']':
		{
			if (StackEmpty(&stack))
			{
				StackDestroy(&stack);
				return false;
			}
			STDataType top = StackTop(&stack);
			StackPop(&stack);
			if ((*s == ')'&& top != '(') ||
				(*s == '}'&& top != '{') ||
				(*s == ']'&& top != '['))
			{
				StackDestroy(&stack);
				return false;
			}
			else
			{
				s++;
			}
			break;
		}
		default:break;
		}
	}
	bool ret = StackEmpty(&stack);
	StackDestroy(&stack);
	return ret;
}

int main()
{
	char arr[] = "{{{{{{[]}}}}}}()[{}]{}()[]{}{[{}(){}]}";

	printf("%d \n",isValid(arr));

	return 0; []
}
