#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"


void InitSeqList(SL*ps)
{
	ps->size = ps->capacity = 0;
	//ps->a = (SL*)realloc(ps->a, (ps->capacity)*sizeof(SL));
	ps->a = NULL;
}

void Print(SL*ps)
{
	int i = 0;
	while (i<=ps->size-1)
	{
		printf(FORMAT(%d), ps->a[i++]);
	}
	printf("\n");
}


void checkcapacity(SL*ps)
{
	if (ps->size == ps->capacity)
	{
		//扩容二倍是个适中的方式
		int newcapacity = ps->capacity == 0 ? 4 : 2 * (ps->capacity);
		SLDataType *ptr = (SLDataType *)realloc(ps->a, newcapacity* sizeof(SLDataType));
		if (ptr == NULL)
		{
			perror("realloc fail");
			//exit(-1);
			return;
		}
		ps->a = ptr;
		ps->capacity = newcapacity;
	}
}

void PushBack(SL*ps, SLDataType x)
{
	checkcapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;	
}


void PushFront(SL*ps, SLDataType x)
{
	checkcapacity(ps);
		int end = ps->size-1;
		for (; end >= 0;end--)
		{
			ps->a[end+1] = ps->a[end];
		}
		ps->a[0] = x;
		ps->size++;
}


void PopBack(SL*ps)
{
	if (ps->size > 0)
	{
		ps->size--;
	}
}


void PopFront(SL*ps)
{
	if (ps -> size >= 0)
	{
		int begin = 0;
		for (; begin < ps->size - 1; begin++)
		{
			ps->a[begin] = ps->a[begin + 1];
		}
	}
	ps->size--;
}

//内存释放
void SLDestory(SL*ps)
{
	free(ps->a);
	ps->a == NULL;
}

int SLFind(SL*ps)
{
	{
		SLDataType x = 0;
		scanf(FORMAT(%d), &x);
		if (ps->size > 0)
		{
			int begin = 0;
			for (; begin <= ps->size - 1; begin++)
			{
				if (strcmp(ps->a[begin], x) == 0)
					return begin;
			}
			return -1;
		}
		
	}
}

//position:等级位置，定位（立场，高度）  location:位置
void SLInsert(SL*ps, int pos, SLDataType x)
{
	;
}

void SLErase(SL*ps, int pos)
{
	;
}