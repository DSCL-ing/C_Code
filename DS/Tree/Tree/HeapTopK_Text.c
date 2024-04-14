#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
#include<time.h>

//ȡǰK�������
#define K 10

void TopK()
{
	
	int n = 10000;//int n = 10000;//������
	int randMax = 10000;//int randMax = 10000;
	int minHeap[K] ;
	//int K = 100;

	memset(minHeap, 0, sizeof(minHeap));//��ʼ������,����sizeof(arr)---����ȡ��ַ
	srand((size_t)time(0));//���ü�size_tҲ�У�NULLʵ���ϻᱻtimeǿ��ת����(void)0
	
	//TopK����˼·s
	//��һ����СΪK�Ķ�

	FILE *fin = fopen("data.txt", "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}

	//���д�����ݣ�rand �� ʹ��fprintf("fout","%d ",)

	int randK = K;//int randK = K;
	for (int i = 0; i < n ;i++)
	{
		int val = rand() % randMax;  //���ֵ������randMax
		if (val % 3 == 0 && randK-- > 0) 
		{
			val = randMax + randK;   //�����Զ������ֵ
		}
		fprintf(fin, "%d ", val);
	}
	//�����������ֵ����K��������ĩβ����  --------���ֵĸ��ʺ�С������
	while (randK-- > 0)
	{
		fprintf(fin, "%d ", randMax+randK);//ע��ָ������ָ����˿��ģ�ʹ�ÿո��\n������fscanfĬ�ϵķָ���ʶ��
	}
	fprintf(fin, "%d ", 99999); //--- ��֤�ܷ�����Ҳ��뵽���

	fclose(fin);


	//for (int i = 0 ; i < K; i++)
	//{
	//	AdjustDown(minHeap, K, 0);
	//}

	FILE *fout = fopen("data.txt", "r");//�����ļ�ָ��
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}



	int tmp;
	while (fscanf(fout, "%d", &tmp) != EOF) //ע�⣬����������scanf��Ĭ�Ϸָ����ո��\n�����ⲻ���ڸ�ʽ%d����ָ���ʶ��
	{
		//���ļ�����ȡ����
		//��һ���ͺͶѶ��Ƚ�һ��
		//�����ļ�ָ������ȥ��Ƚ����ļ���������
		//ASCII�ļ�ʹ��fscanf("��","��ʽ","dest");
		if (tmp >minHeap[0])
		{
			minHeap[0] = tmp;
		}
		AdjustDown(minHeap, K, 0);//��һ�ε���һ��
	}
	fclose(fout);

	for (int i = 0; i < K; i++)//��ӡ����
	{
		printf("%d ", minHeap[i]);
	}
}

