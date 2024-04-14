#include"Sort.h"

/*
1������ȡ��
2��key��λ�㷨����������
3���ݹ�

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

	int mid = getMidIndex(a , begin , end);//mid���м��������м�ֵ���±꣩
	Swap(&a[begin], &a[mid]); //��ȡ���м�ֵ���±��Ի�begin��mid��Ӧ��ֵ��ʹkey��Ӧ�����м�ֵ����������

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

	int mid = getMidIndex(a, begin, end);//mid���м��������м�ֵ���±꣩
	Swap(&a[begin], &a[mid]); //��ȡ���м�ֵ���±��Ի�begin��mid��Ӧ��ֵ��ʹkey��Ӧ�����м�ֵ����������

	int left = begin; int right = end;
	int key = a[left];

	int hole = left;//��һ���Ӹ�begin'
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

	int mid = getMidIndex(a, begin, end);//mid���м��������м�ֵ���±꣩
	Swap(&a[begin], &a[mid]); //��ȡ���м�ֵ���±��Ի�begin��mid��Ӧ��ֵ��ʹkey��Ӧ�����м�ֵ����������

	int prev = begin; int cur = begin+1;
	int keyi = begin;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur) //��һ����������������ָ����ͬ����½��н�������Ϊ�����д��ۣ�����ʱ��
		{										//�Ӳ��ӵȺŶ���,��ò���,�ٽ�����������
			//++prev;
			Swap(&a[prev], &a[cur]);
		} 
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}

/*��·������partition�ָ*/  // ----  ����ʹ�ã����ܷ���key�ˣ���Ϊ�ֳ�����������
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
			Swap(&a[cur++], &a[left++]);//a[left]��ԶС��key
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
* ����Ǵ��ڣ���c������ֻ����right��ǰ�ߣ�ԭ���ǲ�֪����a[right]��С�����߾ͻ�����⡣
�������������a[right--]�󱣳�cur��������ѭ��������һ�֣��Ƚ��µ�a[cur]��key��
����һ�ֵ�ѭ���������һ�ִ�right��������a[cur]��key��Ͷ���ȥ�����С�ڵ��ھͰ�������
�������ܱ�֤	���<key ,�м� == key ,�ұ�>key
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


	if ((end - begin + 1) < 15) //Ϊʲô15�������һ��Ϊ1�������2������������4.... , 1+2+4<15 ���������
	{							//���������ã����ٶ�����---ǰ���ǵݹ�û�еݹ��Ż�����Ȼ����
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
* ����/�����ӽ�����ʱЧ�ʵͣ�n^2  --- keyÿ�ζ��ڱ߱ߣ�������С��ջ֡ÿһ���ʱ�临�Ӷȶ���O��n����
����n�㣬����n^2

* ������ʱ�临�Ӷȣ�ջ֡ÿһ���ʱ�临�Ӷȶ���O��n����ÿ��ÿһ��Ԫ�ر���һ�Σ�ÿһ�㶼���ٵ��Ѿ���λ��key��
���ٵ���ԶС��n�Ľ׼������Ժ��Ե���ʱ�临�ӶȻ���O(n)������õ�����£�ջ֡��logn�㣬�൱��logn��O��n����ӣ�
���Կ���������õ�ʱ�临�Ӷ�ΪO��nlogn����

* �������2��ȫ����һ���������ֻ������ȡ�к�С�����Ż�����O(N^2) ����Ϊkey���ڱ߽�


* ���ַ������Ķ���ÿһ�ֵ�key���ᵽ����ʱ��λ��
*/


//hoare
/*
* Ϊʲô����Ϊkeyʱ�������������� ��Ϊ��߶���С��key �� �ұ߶��Ǵ���key�����Ҫ����keyʱ��key���ڵ�λ�õ�ֵ��Ҫ
С��key�ģ����뱣֤Ҫ������ֵС��key���ұ������ܱ�֤һ�����ҵ�С�ڵ���key����߱�Ȼ�Ǵ��ڵ���key

* �ܲ������ü����ڣ��õݹ���ǰ��ֹ�����ܣ� �����뼫��1���ұ߶���key��  2���ұ߶���keyС ���Ҷ�������ʱʧ��

* ������key��ȵ���ô�죿  ���Ҵ���С����������Ҫͣ��  ���ڻ�С�� => ���ڵ��ڻ�С�ڵ���

* Ϊʲô�ڲ㻹Ҫ����������begin<end�� ��������������������Խ�硣��Ϊÿ�ε��Ҵ���С������������һ��������һ���ģ�
�����Ҵ���̻���С����ֱ��ѭ����ȥ����Խ����
*/


//�ڿӷ�
/*
* �ڿӷ�Ҫ��Ҫ����ȡ�У�Ҫ����Ϊֻ�Ƕ��˸��ӣ��������ߣ���keyֻ����ѭ��������Żύ������������������У���
hoareһ��

*/


//ǰ��ָ�뷨
/*
* ��������Ƚ���

*/


/*
* �ǵݹ�
*/



