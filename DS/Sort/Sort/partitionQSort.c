
#include"Sort.h"

/*三路划分快排*/

//没啥用，跑不过oj，仅学习思想

//https://leetcode-cn.com/problems/sort-an-array/


static void Swap(int *p1, int *p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



//直接插入排序
static void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)  //n个数，只需排n-1个，（因为第一个必定有序--默认）
	{
		int end = i;  //下标 ， 已排序数组【0 - end】
		int tmp = a[end + 1];  //元素交换用 ， 数组往后覆盖挪动
		//一个元素排序，排一个(先假想出一堆乱序数组)
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end]; //往后挪动
				end--;   //比下一个元素
			}
			else
			{
				break; //插入
			}
		}
		a[end + 1] = tmp; //插在end后面
	}
}

/*三数取中，消除有序影响*/
static int getMidIndex(int *a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] > a[mid])
	{
		if (a[begin] < a[end])
		{
			return begin;
		}
		else if (a[mid] > a[end])
		{
			return mid;
		}
		else
		{
			return end;
		}
	}
	else
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
}








static void partitionQSort(int *a, int begin, int end)  //[begin , left-1] [left , right] [right , end]
{
	if (begin >= end)
	{
		return;
	}
	int mid = getMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin; int right = end;
	int cur = begin + 1;
	int key = a[left];

	while (cur <= right)
	{
		if (a[cur] < key)
		{
			Swap(&a[cur++], &a[left++]);//a[left]永远小于key
		}
		else if (a[cur] == key)
		{
			cur++;
		}
		else
		{
			Swap(&a[cur], &a[right--]);
		}
		/*
		* 如果是大于，则c不动，只控制right往前走，原因是不知道啊a[right]大小，再走就会出问题。
		解决方法：交换a[right--]后保持cur不动，让循环进入下一轮，比较新的a[cur]和key，
		在新一轮的循环中如果上一轮从right换过来的a[cur]比key大就丢回去，如果小于等于就按命令走
		这样就能保证	左边<key ,中间 == key ,右边>key
		*/
	}




	partitionQSort(a, begin, left - 1);
	partitionQSort(a, right + 1, end);

}