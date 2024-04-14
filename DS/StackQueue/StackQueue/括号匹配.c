//https://leetcode-cn.com/problems/valid-parentheses/

#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//˳���ʵ��	

typedef char STDataType;

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


bool isValid(char * s){
	Stack stack;
	StackInit(&stack);
	//���������ţ���ջ
	//���������ţ���ջƥ�䣬
	//���ջΪ�գ�����
	//������ԣ����󡣶��ˣ���һ��
	//����ʱջ��Ϊ�գ�����



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
