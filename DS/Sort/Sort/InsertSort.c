
#include"Sort.h"

/*
1、只排一个时：往前比较，满足插入，不满足继续往前，同时前面数组往后挪动
2、全部一起排：从0开始到n-1
*/



//直接插入排序
void InsertSort(int* a, int n)
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