#include"Sort.h"



/*����������*/

/*
1���Ѳ�������Ļ���gap
2������gap

*/

void ShellSort(int *a, int n)
{
	int gap = n ;
		while (gap > 1)
	{ 
			//gap /= 2;
			gap = gap/3+1;
		for (int i = 0; i < n - gap; i += 1)  //n�������У�ֻ����n-1��������Ϊ��һ���ض�����--Ĭ�ϣ�
		{
			/*��һ��������*/
			int end = i;  //�±� �� ���������顾0 - end��
			int tmp = a[end + gap];  //Ҫ�������

			//һ��Ԫ��������һ����(�ȼ����һ����������)
			while (end >= 0)
			{
				/*Ų��һ��*/
				if (a[end] > tmp)
				{
					a[end + gap] = a[end]; //����Ų��
					end -= gap;   //����һ��Ԫ��
				}
				else
				{
					break; //����
				}
			}
			a[end + gap] = tmp; //����end����
		}
	}
}

/*
i < n - gap gapΪ��࣬iҪ����end �� ��gapΪ1ʱend ���Ϊn-1 ...�ɴ� i<n-gap   */


/*
ʱ�临�ӶȲ����㣬����� n^1.3����  --- �漰𢸴����ѧ*/

































