
#include"Sort.h"

/*ѡ������*/

/*
1�������±�����һ��ѡ�������С�±�
2����������һ��
3��ע�������������
*/

static void Swap(int *p1, int *p2);

void SelectSort(int *a, int n)
{
	int begin = 0; int end = n - 1;
	int maxi = begin; int mini = begin;
	while (begin < end)
	{
		//ѭ��һ�� 
		for (int i = begin + 1; i <=end; i++) //�������С�� ���±�
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		//�ҵ��󽻻���[mini]Ҫ��beginλ��
	Swap(&a[begin], &a[mini]);
	if (maxi == begin)  //���maxi�պô���begin��mini�ص�begin��maxi��������ԭ��mini��λ�ã�������
	{
		maxi = mini;
	}
	Swap(&a[end], &a[maxi]);
	//�������С��Χ
	begin++;
	end--;
	}
}

/*ÿһ�ֱȽϴ�begin+1��ʼ �� end+1������Ҫ��end�ȣ�*/



/*��������*/
static void Swap(int *p1, int *p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}







































