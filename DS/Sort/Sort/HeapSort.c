
#include"Sort.h"

//原理
/*
1、建堆：向下调整算法从下往上建堆
2、选数、向下重新调整堆
*/


/*
向下调整算法建堆时间复杂度计算
假设满二叉树树高度h
各层的节点数为
第一层 2 ^ 0               ------向下调整h-1次
第二层 2 ^ 1               ------向下调整h-2次
第三层 2 ^ 2               ------向下调整h-3次
...    ... 
第h - 1层  2 ^ (h - 2)     ------向下调整1次
第h层  2 ^ (h - 1)

向下调整算法建堆是从最小父亲开始，即第h-1层的最后一个节点 parent = (size-1-1)/2
最坏情况下所有节点需要执行的次数为
f(h) = 2^(h-2)*1 + 2^(h-3)*2 + ... + 2^1*(h-2) + 2^0*(h-1)    错位相减
2*f(h) = 2^(h-1)*1 + 2^(h-2)*2 + ... + 2^2*(h-2) + 2^1*(h-1)
作差、合并得f(h) = 2^h -h-1
其中 满二叉树节点数N = 2^h-1，即h = log(N+1) 代入得
f(N) = N - 1 - log(N+1)  ， 舍去logN(数量级)
所以O(n) = n

-------------------------------------------------------------------------------
而向上调整算法建堆时间复杂度比较吃亏，见图
假设满二叉树树高度h
各层的节点数为
第一层 2 ^ 0               
第二层 2 ^ 1               ------向上调整1次
第三层 2 ^ 2               ------向上调整2次
...    ...
第h - 1层  2 ^ (h - 2)     ------向上调整h-2次
第h层  2 ^ (h - 1)         ------向上调整h-1次
计算方法还是错位相减，由图显然可发现向上调整算法执行次数数量级明显提高
不再计算
O(n) = n*logN



总结：向下调整算法跳过最下层最多节点层，且从下层开始节点多执行次数少。快
	向上调整算法从上开始从节点少往节点多执行次数成倍增加，前面的加起来都没最后一层多，慢
*/

/*选择排序*/
static void Swap(int *p1, int *p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



void AdjustDown(int *a, int size, int parent) //小堆
{

	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size &&a[child] < a[child + 1])  //小于选出大的 ， 大于选出小的
		{
			child++;
		}
		if (a[child] > a[parent])//小堆大于最小孩子就交换，
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

void HeapSort(int *a, int size)  //升序建大堆，降序建小堆
{
	/* ---- 向下调整算法建堆  ----*/  //优点，少去最后一层，也是最多的一层，
	//时间复杂度O(n)
	int parent = (size - 1 - 1) / 2;
	while (parent >= 0)
	{
		AdjustDown(a, size, parent);
		parent--;
	}

	/* ---- 选数 ----*/
	//时间复杂度O(n*logN),好像是说n个数都要高度次调整
	int end = size - 1;//不改变原数据
	while (end>0)
	{
		Swap(&a[0], &a[end]);//选数,选完就少一个
		end--;
		AdjustDown(a, end, 0);//
	}

}




