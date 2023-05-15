#include "Stack.h"

/*
* 	NonRecursionQSort
*/

/*
1、用栈模拟二叉树递归

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




/*新手第一次*/
//总思路：1、先走完左。2、走到底后，通过出栈更新数据回到上级位置
void _NonRecursionQSort(int *a, int begin, int end)
{

	struct QSData QSData;
	Stack stack;
	StackInit(&stack);

	int left = begin; int right = end;
	int keyi = left;

	int flag = 0;
	//QSData.begin = begin;
	//QSData.end = end;
	//QSData.keyi = keyi;
	//StackPush(&stack, QSData);

	while (flag==0 || !StackEmpty(&stack))
	{
		flag = 1;
		if (begin >= end)        //返回后用出栈数据
		{
			QSData = StackTop(&stack);
			StackPop(&stack);
			begin = QSData.begin; end = QSData.end;
			left = QSData.begin; right = QSData.end;

		}
		if (begin>=end) //出栈更新数据后是否符合，不符合再次重开判断或出栈
			{
				continue;
			}

		int mid = getMidIndex(a, begin, end);//mid是中间索引（中间值的下标）
		Swap(&a[begin], &a[mid]); //获取到中间值的下标后对换begin和mid对应的值，使key对应的是中间值，消除有序
		keyi = left;

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
		//更新下一轮左的数据前，先把右的数据存起来（入栈）
		Swap(&a[keyi], &a[right]);
		keyi = right;
		QSData.begin = keyi + 1;
		QSData.end = end;
		StackPush(&stack, QSData);
		//更新数据，进入下一轮循环
		begin = begin;
		end = keyi - 1;
		left = begin; right = end;
	}
	StackDestroy(&stack);
}


/*完全模拟递归*/ //--- 把栈DataType改成int,一次连续出入begin和end代码就简化了，再加把核心代码用函数
void _NonRecursionQSort1(int *a, int begin, int end)
{
	//初始化栈
	Stack stack;
	StackInit(&stack);

	//插入第一个数据
	struct QSData QSData;
	QSData.begin = begin; QSData.end = end;
	StackPush(&stack, QSData);


	while (!StackEmpty(&stack))
	{
		
		QSData = StackTop(&stack);
		StackPop(&stack);
		int begin = QSData.begin; int end = QSData.end;

		int mid = getMidIndex(a, begin , end);//mid是中间索引（中间值的下标）
		Swap(&a[begin], &a[mid]); //获取到中间值的下标后对换begin和mid对应的值，使key对应的是中间值，消除有序
		int keyi = begin;
		int left = begin; int right = end;

		/*递归方法中选一*/
		while (left < right)
		{	
			begin = QSData.begin; end = QSData.end;
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

		//相当于递归不满足条件就return
		if (keyi + 1 < end)
		{
			QSData.begin = keyi + 1; QSData.end = end;
			StackPush(&stack, QSData);
		}

		if (begin < keyi - 1)
		{
			QSData.begin = begin; QSData.end = keyi - 1;
			StackPush(&stack, QSData);
		}


	}

	StackDestroy(&stack);


}




//实例
/*
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, left, right);
		// [left, keyi-1] keyi [keyi+1, right]
		if (keyi+1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}

		if (left < keyi-1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
	}

	StackDestroy(&st);
}


int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		// 右边先走，找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// 左边再走，找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &a[keyi]);
	keyi = left;

	return keyi;
}

// 挖坑法
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		// 右边找小，填到左边坑里面
		while (left < right && a[right] >= key)
		{
			--right;
		}

		a[hole] = a[right];
		hole = right;

		// 左边找大，填到右边坑里面
		while (left < right && a[left] <= key)
		{
			++left;
		}

		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int keyi = begin;
	int prev = begin, cur = begin + 1;
	while (cur <= end)
	{
		// 找到比key小的值时，跟++prev位置交换，小的往前翻，大的往后翻
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		++cur;
	}

	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	return keyi;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	if ((end - begin + 1) < 15)
	{
		// 小区间用直接插入替代，减少递归调用次数
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int keyi = PartSort3(a, begin, end);

		// [begin, keyi-1]  keyi [keyi+1, end]
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
}
*/
