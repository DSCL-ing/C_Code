#include"Heap.h"





void Swap(HeapDataType *p1, HeapDataType *p2)
{
	HeapDataType tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



//向上调整算法：从0插入建堆 以及 在堆的前提下插入 //不适合直接建堆（把数组从1开始向下建堆）
void AdjustUp(HeapDataType *a,int child)
{
	assert(a);
	//小堆改成a[child] < a[parent]
	int parent = (child - 1) / 2;
	while (parent >= 0 && child > 0 && a[child] > a[parent]) //把边界和条件全丢进去
	{														  //这个没问题，没有重复出现两个相同的if。可以把条件一起放在while里
		Swap(&a[child], &a[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}
}




//向下调整算法：前提：左右子树是堆 //适合建堆：递归从最小父亲开始（虽然可以从最小孩子）
void AdjustDown(HeapDataType *a,int size, int parent) //小堆
{
	////比较两个孩子中最大/小的进行交换
	//int child = parent * 2 + 1;
	//if (child < size &&  parent < size && a[child] < a[child + 1]) //// ------------这种逻辑是不对的，一个在while外面，一个在while里面，重复，当size == child的时候卡掉一个
	//{																				   //如果出现，务必消除，把while和if条件拆分出来
	//	child = child + 1;
	//}
	////调整到叶子结束	 		                                   //&&先判断左边
	//while (child < size &&  parent < size && a[parent] < a[child]) //child 可能越界，先保证child<size	
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
		if (a[child] < a[parent])//小堆大于最小孩子就交换，
		{						 //大堆小于最大孩子就交换
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


//接受一个堆，一个数组，一个数组大小
void HeapCreate(Heap *ps, HeapDataType *a, int size)
{
	assert(ps);
	//开辟堆中数组空间
	ps->a = (HeapDataType *)malloc(size * sizeof(HeapDataType));
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	memcpy(ps->a, a, size *sizeof(HeapDataType));//拷贝数组过去
	ps->size = size;
	ps->capacity = 2 * size;
	//建堆
	//从最小父亲开始向下调整
	//循环，直到父亲/孩子不为0
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
	if (ps->size == ps->capacity)//开辟/扩容
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
	assert(ps->size > 0); // 保证堆中存在数据
	Swap(&ps->a[ps->size-1], &ps->a[0]);
	ps->size--;
	AdjustDown(ps->a,ps->size, 0);

}


//选数相当快，只需要logN次
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


