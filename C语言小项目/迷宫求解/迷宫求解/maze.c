

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//˳���ʵ��	

typedef PT STDataType;

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
	return ps->top == 0;//�棨���㣩������tree���٣��㣩������false
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
	//���

	//�ܲ����ߣ�
	//�ǲ���ǽ���ǲ��Ǳ�
	//�ǲ����߹���
	//���ж��۲����ߣ��ú���IsPass�ж��ܲ�����

	//��ʼ��
	//̽���������ߺ�ʼ�ߣ������߾ͷ��أ���GetMazePassʵ���������ߡ����أ��ݹ飩��
	//�����յ����

	//Ҫ��ӡ���յ��·��-? ��Ҫ�õ�ջ��ÿ��һ������ջ�����˾ͳ�ջ��

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
	{ // ע�� while ������ case
		//��������
		int **arr = (int **)malloc(sizeof(int*)*a);
		for (i = 0; i < a; i++)
		{
			*(arr + i) = (int*)malloc(sizeof(int)*b);
		}

		//�����Թ�
		for (int i = 0; i < a; ++i)
		{
			for (int j = 0; j < b; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		printf("\n");

		//��ӡ�Թ�
		PrintMaze(arr, a, b);

		//��������
		for (i = 0; i < a; i++)
		{
			free(*(arr + i));
		}
		free(arr);
	}
	return 0;
}