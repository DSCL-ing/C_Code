#include"Heap.h"





void Swap(HeapDataType *p1, HeapDataType *p2)
{
	HeapDataType tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



//���ϵ����㷨����0���뽨�� �Լ� �ڶѵ�ǰ���²��� //���ʺ�ֱ�ӽ��ѣ��������1��ʼ���½��ѣ�
void AdjustUp(HeapDataType *a,int child)
{
	assert(a);
	//С�Ѹĳ�a[child] < a[parent]
	int parent = (child - 1) / 2;
	while (parent >= 0 && child > 0 && a[child] > a[parent]) //�ѱ߽������ȫ����ȥ
	{														  //���û���⣬û���ظ�����������ͬ��if�����԰�����һ�����while��
		Swap(&a[child], &a[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}
}




//���µ����㷨��ǰ�᣺���������Ƕ� //�ʺϽ��ѣ��ݹ����С���׿�ʼ����Ȼ���Դ���С���ӣ�
void AdjustDown(HeapDataType *a,int size, int parent) //С��
{
	////�Ƚ��������������/С�Ľ��н���
	//int child = parent * 2 + 1;
	//if (child < size &&  parent < size && a[child] < a[child + 1]) //// ------------�����߼��ǲ��Եģ�һ����while���棬һ����while���棬�ظ�����size == child��ʱ�򿨵�һ��
	//{																				   //������֣������������while��if������ֳ���
	//	child = child + 1;
	//}
	////������Ҷ�ӽ���	 		                                   //&&���ж����
	//while (child < size &&  parent < size && a[parent] < a[child]) //child ����Խ�磬�ȱ�֤child<size	
	//{
	//	Swap(&a[parent], &a[child]);
	//	parent = child;
	//	child = parent * 2 + 1;
	//	if (child < size &&  parent < size && a[child] < a[child + 1])//-----------------------------------------------------------------------
	//	{
	//		child = child + 1;
	//	}
	//} 


	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size &&a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])//С�Ѵ�����С���Ӿͽ�����
		{						 //���С������Ӿͽ���
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


//-------------------------------------------------------------------------

void HeapPrint(Heap *ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}


void HeapInit(Heap *ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


//����һ���ѣ�һ�����飬һ�������С
void HeapCreate(Heap *ps, HeapDataType *a, int size)
{
	assert(ps);
	//���ٶ�������ռ�
	ps->a = (HeapDataType *)malloc(size * sizeof(HeapDataType));
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	memcpy(ps->a, a, size *sizeof(HeapDataType));//���������ȥ
	ps->size = size;
	ps->capacity = 2 * size;
	//����
	//����С���׿�ʼ���µ���
	//ѭ����ֱ������/���Ӳ�Ϊ0
	int parent = (size - 1 - 1) / 2;
	while (parent >= 0)
	{
		AdjustDown(ps->a, ps->size, parent);
		parent--;
	}
}


void HeapDestroy(Heap *ps)
{
	assert(ps);
	free(ps->a);
	ps->capacity = ps->size = 0;
}




void HeapPush(Heap *ps,HeapDataType x)
{
	assert(ps);
	if (ps->size == ps->capacity)//����/����
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		HeapDataType *tmp = (HeapDataType *)realloc(ps->a, newCapacity * sizeof(HeapDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->size] = x;
	ps->size++;
	AdjustUp(ps->a, ps->size - 1);
}



void HeapPop(Heap *ps)
{
	assert(ps);
	assert(ps->size > 0); // ��֤���д�������
	Swap(&ps->a[ps->size-1], &ps->a[0]);
	ps->size--;
	AdjustDown(ps->a,ps->size, 0);

}


//ѡ���൱�죬ֻ��ҪlogN��
HeapDataType HeapTop(Heap *ps)
{
	assert(ps);
	assert(ps->size > 0);
	return ps->a[0];


}

int HeapSize(Heap *ps)
{
	assert(ps);
	return ps->size;

}


bool HeapEmpty(Heap *ps)
{
	assert(ps);
	return ps->size == 0;
}


