#include"Sort.h"

/*有序时效率高，实用性不强，判断有序*/

static void Swap(int *p1, int *p2);

//冒泡排序：
/*
1、与下标后一个比较，符合交换，不符下一轮
2、监视哨
*/

void BubbleSort(int *a, int n)
{

	int end = n - 1;
	while (end>0)
	{
	int exchange = 0;
		for (int i = 0; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;  //交换
			}
		}
		if (exchange == 0)
		{
			break;
		}
		end--;
	}

}





/*交换函数*/
static void Swap(int *p1, int *p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}