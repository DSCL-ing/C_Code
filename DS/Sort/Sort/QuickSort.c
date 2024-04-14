#include"Sort.h"

/*
1、三数取中
2、key归位算法、划分区间
3、递归

*/


/*交换函数*/
static void Swap(int *p1, int *p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
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
		else if (a[begin]>a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}


int _HoareQuickSort(int *a, int begin , int end)
{

	int mid = getMidIndex(a , begin , end);//mid是中间索引（中间值的下标）
	Swap(&a[begin], &a[mid]); //获取到中间值的下标后对换begin和mid对应的值，使key对应的是中间值，消除有序

	int left = begin; int right = end;
	int keyi = left;

	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}

		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[right]);
	keyi = right;

	return keyi;

}

int _HoleQuickSort(int *a, int begin, int end)
{

	int mid = getMidIndex(a, begin, end);//mid是中间索引（中间值的下标）
	Swap(&a[begin], &a[mid]); //获取到中间值的下标后对换begin和mid对应的值，使key对应的是中间值，消除有序

	int left = begin; int right = end;
	int key = a[left];

	int hole = left;//第一个坑给begin'
	while (left < right)
	{
		while (left < right && key <= a[right])
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;

		while (left < right && key >= a[left])
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;

	//_HoleQuickSort(a, begin, hole - 1);
	//_HoleQuickSort(a, hole + 1, end);
}

int _PointQuickSort(int *a, int begin, int end)
{

	int mid = getMidIndex(a, begin, end);//mid是中间索引（中间值的下标）
	Swap(&a[begin], &a[mid]); //获取到中间值的下标后对换begin和mid对应的值，使key对应的是中间值，消除有序

	int prev = begin; int cur = begin+1;
	int keyi = begin;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur) //后一个条件是用于限制指针相同情况下进行交换，因为交换有代价，减少时间
		{										//加不加等号都行,最好不加,少交换减少消耗
			//++prev;
			Swap(&a[prev], &a[cur]);
		} 
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}

/*三路“划分partition分割”*/  // ----  独立使用，不能返回key了，因为分成了两个区间
void partitionQSort(int *a, int begin, int end)  //[begin , left-1] [left , right] [right , end]
{
	if (begin >= end)
	{
		return;
	}
	int mid = getMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin; int right = end;
	int cur = begin+1;
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



	
	QuickSort(a, begin, left - 1);
	QuickSort(a, right+1, end);

}


void QuickSort(int *a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}


	if ((end - begin + 1) < 15) //为什么15？，最后一层为1个，其次2，倒数第三层4.... , 1+2+4<15 即最后三层
	{							//最后三层最好，多少都会慢---前提是递归没有递归优化，不然相差不大
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int keyi = _PointQuickSort(a, begin, end);
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
}

//void QuickSort(int *a, int n)
//{
//	_HoareQuickSort(a, 0, n - 1);
//	//_HoleQuickSort(a, 0, n - 1);
//	//_PointQuickSort(a, 0, n - 1);
//
//}

//
/*
* 有序/逆序或接近有序时效率低，n^2  --- key每次都在边边，最大或最小，栈帧每一层的时间复杂度都是O（n），
但有n层，所以n^2

* 最好情况时间复杂度：栈帧每一层的时间复杂度都是O（n），每层每一个元素遍历一次，每一层都会少掉已经归位的key，
但少的数远小于n的阶级，所以忽略掉，时间复杂度还是O(n)。在最好的情况下，栈帧有logn层，相当于logn个O（n）相加，
所以快速排序最好的时间复杂度为O（nlogn）。

* 极端情况2：全都是一个数，如果只有三数取中和小区间优化，则O(N^2) ，因为key都在边界


* 三种方法核心都是每一轮的key都会到有序时的位置
*/


//hoare
/*
* 为什么最左为key时，先走右再走左？ 因为左边都是小于key ， 右边都是大于key，最后要交换key时，key所在的位置的值是要
小于key的，必须保证要交换的值小于key，右边先走能保证一定能找到小于等于key，左边必然是大于等于key

* 能不能设置监视哨，让递归提前终止？不能： 例子想极端1、右边都比key大  2、右边都比key小 。且都是无序时失败

* 遇到和key相等的怎么办？  让找大找小走起来，不要停留  大于或小于 => 大于等于或小于等于

* 为什么内层还要加限制条件begin<end？ 如果不加限制条件，则会越界。因为每次的找大找小过程是先走完一个再走下一个的，
可能找大过程或找小过程直接循环出去导致越界了
*/


//挖坑法
/*
* 挖坑法要不要三数取中？要：因为只是多了个坑，交换两边，而key只有在循环结束后才会交换，还是在最左或最有，和
hoare一样

*/


//前后指针法
/*
* 这个方法比较慢

*/


/*
* 非递归
*/



