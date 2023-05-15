#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>


//顺序表实现	


typedef int STDataType;

typedef struct Stack
{
	STDataType *a;
	int top;         //栈顶位置
	int capacity;    //栈容量
}Stack;//缩写ST



void StackInit(Stack *ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackInit(Stack *ps);

void StackDestroy(Stack *ps);

void StackPush(Stack *ps, STDataType x);

void StackPop(Stack *ps);

STDataType StackTop(Stack *ps);

bool StackEmpty(Stack *ps);

int StackSize(Stack *ps);

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
	ps->a[ps->top++] = x;
	//ps->top++;
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



//------------------------------------------------------------------

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


// 三数取中
// begin  mid  end
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else // a[begin] > a[mid]
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}


int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		// 右边先走，找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// 左边再走，找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &a[keyi]);
	keyi = left;

	return keyi;
}



void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort1(a, left, right);
		// [left, keyi-1] keyi [keyi+1, right]
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}

		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
	}

	StackDestroy(&st);
}


void PrintText()
{
	//int a[] = { 6, 1, 2, 7, 9, 3, 4, 5, 8, 10, 8 };
	int a[] = { 6, 1, 2, 7, 9, 3, 4, 5, 6, 8 };
	//QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
	int n = 10;
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void clockText()
{
	srand(time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);
	int* a7 = (int*)malloc(sizeof(int)*N);

	int j = 0;
	for (int i = 0; i < N; ++i)
	{
		//a1[i] = rand()+i;
		a1[i] = i;
		/*int x = rand();
		if (x % 7 == 0 && x % 3 == 0 && x % 2 == 0)
		{
		a1[i] = x;
		++j;
		}
		else
		{
		a1[i] = i;
		}*/

		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}


	int begin6 = clock();
	QuickSortNonR(a6, 0, N-1);
	int end6 = clock();
	printf("sort:%d\n", end6 - begin6);
}

int main()
{
	PrintText();
	clockText();


	return 0;
}