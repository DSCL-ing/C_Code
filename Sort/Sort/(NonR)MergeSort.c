



#include "Sort.h"






/*
���Ⱦ��ǲ�ʹ��ջ�Ͷ��У����Ӹ���

˼·������ʵ�𣬵ݹ鱾�ʾ���һ������������������[0,1][2,3][4,5]...��[0,1,2,3]...�����ȥ
ÿһ�������������������ϲ�

���⣺����һ�ֳ�����������ʱ
�ݹ�����Ϊ��[ begin1 <= end1 ]���ƣ�������Ͳ��ܣ��治��������ν��ʵ�ֱȽϼ�
�ǵݹ��ѵ��Ǵ�����ѧ���⣬���
*/


//��������ѭ�����ϣ�������ǿ��Ʋ������ڶ����ǿ��ƺϲ������



void MergeSortNonR(int *a, int n)
{
	//range = ��Χ�����䡣layer = ����

	//  ��һ�������±��ǵڶ�����ʼ�±�-1    
	//  ÿ����ʼλ�ÿ�����ѭ���������� ----		��һ��ѭ������i  ----  Ҫѭ�����ٴΣ�
	//	���������ǣ�range == n
	//	��һ������������ɲ�������   ----  ��һ����������N
	//	�ϲ�ʱ��Ҫ���� ,��������һ��ѭ��---- ��������ʼ�ͽ����±�
	int *tmp = (int*)malloc(n*sizeof(int));
	if (!tmp)
	{
		perror("malloc fail");
		exit(-1);
	}

	int begin1 = 0;		int begin2 = 0;
	int end1 = 0;		int end2  = 0;
	//int i = 0;
	int rangeN = 1;//һ��begin��end �ķ�Χ

	while (rangeN < n)
	{
		int j = 0;
		//���Ʊ������������һ��
		
		for (int i = 0; 2 * rangeN * i < n; i++)
		{   //��Χ��2��4��8��16 --- 2^rangeN  == range=range*2
			//[0,1][2,3][4,5]...��[0,1,2,3][4,5,6,7][8,9,10,11]
			begin1 =  2 * rangeN * i;			// 0 ,2 ,4   /   0 ,4 ,8   /  0 �� 8 ��16 �� 24  /
			begin2 = begin1 + rangeN ;		// 1 ,3 ,5   /   2 ,6 ,10  /  4 ,  12, 20  , 28
			end1 = begin1 + rangeN - 1;
			end2 = begin2 + rangeN - 1;
			

			//����
			if (end1 >= n-1)
			{
				end1 = n - 1;
				// ����������
				begin2 = n;		//���д
				end2 = n - 1;//С��begin2����
			}
			//else if (end1 == n-1)
			//{
			//	// ����������
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			else if (end2 > n-1) //����Ҫif���������end1 < n-1 => ���ܳ���end2 ҲС��n-1
			{
				end2 = n - 1;
			}

			//�鲢
			/*
			1��һ��һ�鿽�����Ƚ�һ���꿽����tmp�󣬾Ϳ�����ԭ���飬
			2��һ��һ�ֿ������Ƚ���һ����������ٿ�����ԭ����
			*/
			j = 2 * rangeN * i;//��ʼλ��
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
				tmp[j++] = a[begin1++];  //ֻ��һ��һ��������memcpy
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			//�鲢��һ��Ϳ�����һ��
			//memcpy(a + 2 * rangeN * i, tmp + 2 * rangeN * i, (end2 - 2 * rangeN * i + 1) * sizeof(int));

		}
		memcpy(a, tmp, (n)*sizeof(int));
		rangeN *= 2;
	}




}
