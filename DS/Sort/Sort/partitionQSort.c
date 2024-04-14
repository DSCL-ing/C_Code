
#include"Sort.h"

/*��·���ֿ���*/

//ûɶ�ã��ܲ���oj����ѧϰ˼��

//https://leetcode-cn.com/problems/sort-an-array/


static void Swap(int *p1, int *p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



//ֱ�Ӳ�������
static void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)  //n������ֻ����n-1��������Ϊ��һ���ض�����--Ĭ�ϣ�
	{
		int end = i;  //�±� �� ���������顾0 - end��
		int tmp = a[end + 1];  //Ԫ�ؽ����� �� �������󸲸�Ų��
		//һ��Ԫ��������һ��(�ȼ����һ����������)
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end]; //����Ų��
				end--;   //����һ��Ԫ��
			}
			else
			{
				break; //����
			}
		}
		a[end + 1] = tmp; //����end����
	}
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








static void partitionQSort(int *a, int begin, int end)  //[begin , left-1] [left , right] [right , end]
{
	if (begin >= end)
	{
		return;
	}
	int mid = getMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin; int right = end;
	int cur = begin + 1;
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




	partitionQSort(a, begin, left - 1);
	partitionQSort(a, right + 1, end);

}