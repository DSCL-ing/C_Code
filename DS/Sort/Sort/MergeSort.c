
#include"Sort.h"

//递归归并排序分三步
/*
* 1、递归
* 2、合并
* 3、拷贝
*/

/*  时间复杂度分析
归并算法中比较耗时的是归并操作，也就是把两个子数组合并为大数组
* 每一层都要归并n个数，一共logN层，所以O(N*logN)

*/

void _MergeSort(int *a , int begin , int end ,int *tmp)
{
	//返回条件:只有一个的时候返回
	if (begin >= end)
	{	
		return;
	}

	//区间
	int mid = (begin + end) / 2;

	//类后序遍历,递归让子区间有序
	_MergeSort(a, begin, mid , tmp);//另一种时mid+1
	_MergeSort(a, mid+1, end , tmp);

	//合并
	int begin1 = begin; int begin2 = mid + 1; //左右数组最小下标（升序要从小开始比较）
	int end1 = mid;     int end2 = end;
	int i = begin; //tmp起始位置
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i] = a[begin1++];
		}
		else
		{
			tmp[i] = a[begin2++];
		}
		i++;
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//拷贝回去原数组
	/*
	1、一个一个交换
	2、字符函数mem系列
	*/

	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));


}

void MergeSort(int*a, int begin1)
{
	int *tmp = (int *)malloc( begin1 * sizeof(int));
	if (!tmp)
	{
		perror("malloc fail");
		exit(1);
	}
	_MergeSort(a, 0, begin1 - 1, tmp);
	free(tmp);
}


/*
* 当递归到只有一个数时，就相当于有序了，一个即有序，所以直接返回



*/