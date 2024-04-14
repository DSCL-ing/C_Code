
#include"Sort.h"

//�ݹ�鲢���������
/*
* 1���ݹ�
* 2���ϲ�
* 3������
*/

/*  ʱ�临�Ӷȷ���
�鲢�㷨�бȽϺ�ʱ���ǹ鲢������Ҳ���ǰ�����������ϲ�Ϊ������
* ÿһ�㶼Ҫ�鲢n������һ��logN�㣬����O(N*logN)

*/

void _MergeSort(int *a , int begin , int end ,int *tmp)
{
	//��������:ֻ��һ����ʱ�򷵻�
	if (begin >= end)
	{	
		return;
	}

	//����
	int mid = (begin + end) / 2;

	//��������,�ݹ�������������
	_MergeSort(a, begin, mid , tmp);//��һ��ʱmid+1
	_MergeSort(a, mid+1, end , tmp);

	//�ϲ�
	int begin1 = begin; int begin2 = mid + 1; //����������С�±꣨����Ҫ��С��ʼ�Ƚϣ�
	int end1 = mid;     int end2 = end;
	int i = begin; //tmp��ʼλ��
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

	//������ȥԭ����
	/*
	1��һ��һ������
	2���ַ�����memϵ��
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
* ���ݹ鵽ֻ��һ����ʱ�����൱�������ˣ�һ������������ֱ�ӷ���



*/