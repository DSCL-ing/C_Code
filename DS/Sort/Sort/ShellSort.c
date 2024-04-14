#include"Sort.h"



/*插入排序类*/

/*
1、把插入排序的换成gap
2、修正gap

*/

void ShellSort(int *a, int n)
{
	int gap = n ;
		while (gap > 1)
	{ 
			//gap /= 2;
			gap = gap/3+1;
		for (int i = 0; i < n - gap; i += 1)  //n个数排列，只需排n-1个，（因为第一个必定有序--默认）
		{
			/*第一个数排序*/
			int end = i;  //下标 ， 已排序数组【0 - end】
			int tmp = a[end + gap];  //要插入的数

			//一个元素排序，排一个数(先假想出一堆乱序数组)
			while (end >= 0)
			{
				/*挪动一次*/
				if (a[end] > tmp)
				{
					a[end + gap] = a[end]; //往后挪动
					end -= gap;   //比下一个元素
				}
				else
				{
					break; //插入
				}
			}
			a[end + gap] = tmp; //插在end后面
		}
	}
}

/*
i < n - gap gap为差距，i要赋给end ， 当gap为1时end 最多为n-1 ...由此 i<n-gap   */


/*
时间复杂度不好算，大概在 n^1.3左右  --- 涉及稷复杂数学*/

































