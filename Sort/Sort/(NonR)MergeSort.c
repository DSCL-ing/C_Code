



#include "Sort.h"






/*
首先就是不使用栈和队列，更加复杂

思路：从现实起，递归本质就是一堆乱序数从两两排序[0,1][2,3][4,5]...到[0,1,2,3]...如此下去
每一轮提升两倍两倍这样合并

问题：当有一轮出现奇数数组时
递归是因为有[ begin1 <= end1 ]限制，不满足就不跑，奇不奇数无所谓，实现比较简单
非递归难点是处理数学问题，设计
*/


//首先两层循环套上，最外层是控制层数；第二层是控制合并的组号



void MergeSortNonR(int *a, int n)
{
	//range = 范围、区间。layer = 层数

	//  第一个结束下标是第二个起始下标-1    
	//  每个起始位置可以由循环次数控制 ----		设一个循环次数i  ----  要循环多少次？
	//	结束条件是：range == n
	//	下一轮区间变大可以由层数控制   ----  设一个层数控制N
	//	合并时需要两组 ,两组区间一轮循环---- 设两组起始和结束下标
	int *tmp = (int*)malloc(n*sizeof(int));
	if (!tmp)
	{
		perror("malloc fail");
		exit(-1);
	}

	int begin1 = 0;		int begin2 = 0;
	int end1 = 0;		int end2  = 0;
	//int i = 0;
	int rangeN = 1;//一个begin到end 的范围

	while (rangeN < n)
	{
		int j = 0;
		//控制变量让其进入下一轮
		
		for (int i = 0; 2 * rangeN * i < n; i++)
		{   //范围：2、4、8、16 --- 2^rangeN  == range=range*2
			//[0,1][2,3][4,5]...到[0,1,2,3][4,5,6,7][8,9,10,11]
			begin1 =  2 * rangeN * i;			// 0 ,2 ,4   /   0 ,4 ,8   /  0 ， 8 ，16 ， 24  /
			begin2 = begin1 + rangeN ;		// 1 ,3 ,5   /   2 ,6 ,10  /  4 ,  12, 20  , 28
			end1 = begin1 + rangeN - 1;
			end2 = begin2 + rangeN - 1;
			

			//修正
			if (end1 >= n-1)
			{
				end1 = n - 1;
				// 不存在区间
				begin2 = n;		//随便写
				end2 = n - 1;//小于begin2就行
			}
			//else if (end1 == n-1)
			//{
			//	// 不存在区间
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			else if (end2 > n-1) //必须要if，否则就是end1 < n-1 => 可能出现end2 也小于n-1
			{
				end2 = n - 1;
			}

			//归并
			/*
			1、一组一组拷贝：比较一组完拷贝到tmp后，就拷贝回原数组，
			2、一轮一轮拷贝：比较完一轮所有组后，再拷贝回原数组
			*/
			j = 2 * rangeN * i;//起始位置
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j] = a[begin1++];
				}
				else
				{
					tmp[j] = a[begin2++];
				}
				j++;
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];  //只能一个一个拷，或memcpy
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			//归并完一组就拷贝回一组
			//memcpy(a + 2 * rangeN * i, tmp + 2 * rangeN * i, (end2 - 2 * rangeN * i + 1) * sizeof(int));

		}
		memcpy(a, tmp, (n)*sizeof(int));
		rangeN *= 2;
	}




}
