
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

	printf("原数组：");
	Print(a1, sz);

	//printf("直接插入排序：");
	//InsertSort(a1, sz);
	//Print(a1, sz);

	//printf("希尔排序：");
	//ShellSort(a2, sz);
	//Print(a2, sz);

	//printf("选择排序：");
	//SelectSort(a3, sz);
	//Print(a3, sz);

	//printf("堆排序：");
	//HeapSort(a4, sz);
	//Print(a4, sz);

	//printf("冒泡排序：");
	//BubbleSort(a5, sz);
	//Print(a5, sz);

	//printf("快速排序(R)：");
	//QuickSort(a6, 0, sz - 1);
	//Print(a6, sz);

	//printf("快速排序(NonR)：");
	//_NonRecursionQSort1(a7, 0, sz - 1);
	//Print(a7, sz);

	//printf("归并排序(R)：");
	//MergeSort(a8, sz);
	//Print(a8, sz);

	printf("归并排序(NonR)：");
	int a10[12] = { 4, 13, 5, 7, 2, 11, 9, 8, 6, 0 ,12 ,3};
	sz = sizeof(a10)/sizeof(int);
	MergeSortNonR(a10, sz);
	Print(a10, sz);
}

/*切换到release版本，优化好，更快（少了很多调试信息等）*/
void ClockText()
{
	srand((unsigned int)time(0));

	const int N = 1000000;//下面排序可能会把10000改了，以防意外---不要大于百万
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
		if (x % 7 == 0 && x % 3 == 0 && x % 2 == 0) //造随机数
		{
			a1[i] = x;
			//j++;
		}
		else
		{
			a1[i] = x;  //有序数

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
	//printf("随机数;>%d \n",j);

	//int begin1 = clock();
	//InsertSort(a1, N);
	//int end1 = clock();
	//printf("直接插入排序：%d\n",end1-begin1);


	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	printf("希尔排序：%d\n", end2 - begin2);

	//int begin3 = clock();
	//SelectSort(a3, N);
	//int end3 = clock();
	//printf("选择排序：%d\n", end3-begin3);

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	printf("堆排序：%d\n", end4-begin4);


	//int begin5 = clock();
	//BubbleSort(a5, N);
	//int end5 = clock();
	//printf("冒泡排序：%d\n", end5 - begin5);

	//int begin6 = clock();
	//QuickSort(a6, 0,N-1);
	//int end6 = clock();
	//printf("快速排序(R)：%d\n", end6 - begin6);

	//

	//int begin7 = clock();
	//_NonRecursionQSort1(a7, 0,N-1);
	//int end7 = clock();
	//printf("快速排序(NonR)：%d\n", end7 - begin7);


	int begin8 = clock();
	MergeSort(a8, N );
	int end8 = clock();
	printf("归并排序(R)：%d\n", end8 - begin8);

	int begin9 = clock();
	MergeSortNonR(a9, N);
	int end9 = clock();
	printf("归并排序(NonR)：%d\n", end9 - begin9);
}

int main()
{
	//PrintText();
	ClockText();



	return 0;
}