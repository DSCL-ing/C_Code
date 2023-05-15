
#include"Sort.h"

/*选择排序*/

/*
1、控制下标走完一轮选出最大最小下标
2、交换、下一轮
3、注意特殊情况修正
*/

static void Swap(int *p1, int *p2);

void SelectSort(int *a, int n)
{
	int begin = 0; int end = n - 1;
	int maxi = begin; int mini = begin;
	while (begin < end)
	{
		//循环一轮 
		for (int i = begin + 1; i <=end; i++) //找最大最小数 的下标
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		//找到后交换，[mini]要到begin位置
	Swap(&a[begin], &a[mini]);
	if (maxi == begin)  //如果maxi刚好处于begin，mini回到begin后，maxi被交换到原来mini的位置，需修正
	{
		maxi = mini;
	}
	Swap(&a[end], &a[maxi]);
	//最后再缩小范围
	begin++;
	end--;
	}
}

/*每一轮比较从begin+1开始 ， end+1结束（要和end比）*/



/*交换函数*/
static void Swap(int *p1, int *p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}







































