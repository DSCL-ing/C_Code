
#include"Stack.h"	

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

void StackPush(Stack *ps,STDataType x)
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

