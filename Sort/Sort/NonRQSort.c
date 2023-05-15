#include "Stack.h"

/*
* 	NonRecursionQSort
*/

/*
1����ջģ��������ݹ�

*/

/*��������*/
static void Swap(int *p1, int *p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/*����ȡ�У���������Ӱ��*/
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




/*���ֵ�һ��*/
//��˼·��1����������2���ߵ��׺�ͨ����ջ�������ݻص��ϼ�λ��
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
		if (begin >= end)        //���غ��ó�ջ����
		{
			QSData = StackTop(&stack);
			StackPop(&stack);
			begin = QSData.begin; end = QSData.end;
			left = QSData.begin; right = QSData.end;

		}
		if (begin>=end) //��ջ�������ݺ��Ƿ���ϣ��������ٴ��ؿ��жϻ��ջ
			{
				continue;
			}

		int mid = getMidIndex(a, begin, end);//mid���м��������м�ֵ���±꣩
		Swap(&a[begin], &a[mid]); //��ȡ���м�ֵ���±��Ի�begin��mid��Ӧ��ֵ��ʹkey��Ӧ�����м�ֵ����������
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
		//������һ���������ǰ���Ȱ��ҵ����ݴ���������ջ��
		Swap(&a[keyi], &a[right]);
		keyi = right;
		QSData.begin = keyi + 1;
		QSData.end = end;
		StackPush(&stack, QSData);
		//�������ݣ�������һ��ѭ��
		begin = begin;
		end = keyi - 1;
		left = begin; right = end;
	}
	StackDestroy(&stack);
}


/*��ȫģ��ݹ�*/ //--- ��ջDataType�ĳ�int,һ����������begin��end����ͼ��ˣ��ټӰѺ��Ĵ����ú���
void _NonRecursionQSort1(int *a, int begin, int end)
{
	//��ʼ��ջ
	Stack stack;
	StackInit(&stack);

	//�����һ������
	struct QSData QSData;
	QSData.begin = begin; QSData.end = end;
	StackPush(&stack, QSData);


	while (!StackEmpty(&stack))
	{
		
		QSData = StackTop(&stack);
		StackPop(&stack);
		int begin = QSData.begin; int end = QSData.end;

		int mid = getMidIndex(a, begin , end);//mid���м��������м�ֵ���±꣩
		Swap(&a[begin], &a[mid]); //��ȡ���м�ֵ���±��Ի�begin��mid��Ӧ��ֵ��ʹkey��Ӧ�����м�ֵ����������
		int keyi = begin;
		int left = begin; int right = end;

		/*�ݹ鷽����ѡһ*/
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

		//�൱�ڵݹ鲻����������return
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




//ʵ��
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
		// �ұ����ߣ���С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// ������ߣ��Ҵ�
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

// �ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		// �ұ���С�����߿�����
		while (left < right && a[right] >= key)
		{
			--right;
		}

		a[hole] = a[right];
		hole = right;

		// ����Ҵ���ұ߿�����
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
		// �ҵ���keyС��ֵʱ����++prevλ�ý�����С����ǰ�����������
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
		// С������ֱ�Ӳ�����������ٵݹ���ô���
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
