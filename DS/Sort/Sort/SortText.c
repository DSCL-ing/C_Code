
#include"Sort.h"
#include"time.h"
#include<stdlib.h>

void Print(int*a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void PrintText()
{
	int a[10] = { 4, 3, 5, 7, 2, 1, 9, 8, 6, 0 };
	int sz = sizeof(a) / sizeof(int);
	int a1[10];
	int a2[10];
	int a3[10];
	int a4[10];
	int a5[10];
	int a6[10];
	int a7[10];
	int a8[10];
	int a9[10];
	for (int i = 0; i < sz; i++)
	{
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
		a4[i] = a[i];
		a5[i] = a[i];
		a6[i] = a[i];
		a7[i] = a[i];
		a8[i] = a[i];
		a9[i] = a[i];
	}
	//int sz = sizeof(a) / sizeof(int);

	printf("ԭ���飺");
	Print(a1, sz);

	//printf("ֱ�Ӳ�������");
	//InsertSort(a1, sz);
	//Print(a1, sz);

	//printf("ϣ������");
	//ShellSort(a2, sz);
	//Print(a2, sz);

	//printf("ѡ������");
	//SelectSort(a3, sz);
	//Print(a3, sz);

	//printf("������");
	//HeapSort(a4, sz);
	//Print(a4, sz);

	//printf("ð������");
	//BubbleSort(a5, sz);
	//Print(a5, sz);

	//printf("��������(R)��");
	//QuickSort(a6, 0, sz - 1);
	//Print(a6, sz);

	//printf("��������(NonR)��");
	//_NonRecursionQSort1(a7, 0, sz - 1);
	//Print(a7, sz);

	//printf("�鲢����(R)��");
	//MergeSort(a8, sz);
	//Print(a8, sz);

	printf("�鲢����(NonR)��");
	int a10[12] = { 4, 13, 5, 7, 2, 11, 9, 8, 6, 0 ,12 ,3};
	sz = sizeof(a10)/sizeof(int);
	MergeSortNonR(a10, sz);
	Print(a10, sz);
}

/*�л���release�汾���Ż��ã����죨���˺ܶ������Ϣ�ȣ�*/
void ClockText()
{
	srand((unsigned int)time(0));

	const int N = 1000000;//����������ܻ��10000���ˣ��Է�����---��Ҫ���ڰ���
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);
	int* a7 = (int*)malloc(sizeof(int)*N);
	int* a8 = (int*)malloc(sizeof(int)*N);
	int* a9 = (int*)malloc(sizeof(int)*N);

	int j = 0;
	for (int i = 0; i < N; ++i)
	{	
			//a1[i] = rand() + i;
		int x = rand()+i;
		//int x = 2;
		if (x % 7 == 0 && x % 3 == 0 && x % 2 == 0) //�������
		{
			a1[i] = x;
			//j++;
		}
		else
		{
			a1[i] = x;  //������

		}
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
	}
	//printf("�����;>%d \n",j);

	//int begin1 = clock();
	//InsertSort(a1, N);
	//int end1 = clock();
	//printf("ֱ�Ӳ�������%d\n",end1-begin1);


	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	printf("ϣ������%d\n", end2 - begin2);

	//int begin3 = clock();
	//SelectSort(a3, N);
	//int end3 = clock();
	//printf("ѡ������%d\n", end3-begin3);

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	printf("������%d\n", end4-begin4);


	//int begin5 = clock();
	//BubbleSort(a5, N);
	//int end5 = clock();
	//printf("ð������%d\n", end5 - begin5);

	//int begin6 = clock();
	//QuickSort(a6, 0,N-1);
	//int end6 = clock();
	//printf("��������(R)��%d\n", end6 - begin6);

	//

	//int begin7 = clock();
	//_NonRecursionQSort1(a7, 0,N-1);
	//int end7 = clock();
	//printf("��������(NonR)��%d\n", end7 - begin7);


	int begin8 = clock();
	MergeSort(a8, N );
	int end8 = clock();
	printf("�鲢����(R)��%d\n", end8 - begin8);

	int begin9 = clock();
	MergeSortNonR(a9, N);
	int end9 = clock();
	printf("�鲢����(NonR)��%d\n", end9 - begin9);
}

int main()
{
	//PrintText();
	ClockText();



	return 0;
}