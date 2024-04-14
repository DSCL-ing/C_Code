

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//顺序表实现	

typedef PT STDataType;

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

typedef struct position
{
	int x;
	int y;
}PT;

PT cur ;

IsPass(int **a, int N, int M)
{

}

bool getPath(int *a, PT cur)
{
	//起点

	//能不能走：
	//是不是墙，是不是边
	//是不是走过的
	//先判断嫩不能走，用函数IsPass判断能不能走

	//开始走
	//探测四周能走后开始走，不能走就返回，用GetMazePass实现往四周走、返回（递归）、
	//遇到终点结束

	//要打印到终点的路径-? 需要用到栈。每走一步就入栈，回退就出栈。

	StackPush(a, cur);

	if (cur.x == N - 1 && cur.y == M - 1)
	{
		return true;
	}

	cur.x += 1;
	StackPush(&stack, cur);
	if (getPath(a, cur))
	{
		return true;
	}
	StackPop(&stack);

	cur.x -= 1;
	StackPush(&stack, cur);
	if (getPath(a, cur))
	{
		return true;
	}
	StackPop(&stack);

	cur.y += 1;
	StackPush(&stack, cur);
	if (getPath(a, cur))
	{
		return true;
	}
	StackPop(&stack);

	cur.y -= 1;
	StackPush(&stack, cur);
	if (getPath(a, cur))
	{
		return true;
	}
	StackPop(&stack);

	return false;
}

void PrintPath(Stack *r_stack)
{
	while (!StackEmpty(r_stack))
	{
		cur = StackTop(r_stack);
		printf("(%d,%d)\n", cur.x, cur.y);
		StackPop(&r_stack);
	}
}

void PrintMaze(int **a, int N; int M)
{
	int i = 0; int j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", *(*(a + i) + j));
		}
		printf("\n");
	}
	printf("\n");
}


int main() {

	int a, b;
	int i = 0, j = 0;
	while (scanf("%d %d", &a, &b) != EOF)
	{ // 注意 while 处理多个 case
		//开辟数组
		int **arr = (int **)malloc(sizeof(int*)*a);
		for (i = 0; i < a; i++)
		{
			*(arr + i) = (int*)malloc(sizeof(int)*b);
		}

		//输入迷宫
		for (int i = 0; i < a; ++i)
		{
			for (int j = 0; j < b; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		printf("\n");

		//打印迷宫
		PrintMaze(arr, a, b);

		//销毁数组
		for (i = 0; i < a; i++)
		{
			free(*(arr + i));
		}
		free(arr);
	}
	return 0;
}