#include"Sort.h"

/*����ʱЧ�ʸߣ�ʵ���Բ�ǿ���ж�����*/

static void Swap(int *p1, int *p2);

//ð������
/*
1�����±��һ���Ƚϣ����Ͻ�����������һ��
2��������
*/

void BubbleSort(int *a, int n)
{

	int end = n - 1;
	while (end>0)
	{
	int exchange = 0;
		for (int i = 0; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;  //����
			}
		}
		if (exchange == 0)
		{
			break;
		}
		end--;
	}

}





/*��������*/
static void Swap(int *p1, int *p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}