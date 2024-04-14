#pragma once


#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include"stdlib.h"
#include"string.h"



/*直接插入排序*/
void InsertSort(int* a, int n);

/*希尔排序*/
void ShellSort(int *a, int n);

/*直接插入排序*/
void SelectSort(int *a, int n);

/*堆排序*/
void HeapSort(int *a, int size);

/*冒泡排序*/
void BubbleSort(int *a, int n);

/*快速排序(R)*/
void QuickSort(int *a, int begin ,int end);

/*三路划分快排*/
void partitionQSort(int *a, int begin, int end);

/*非递归快排*/
void _NonRecursionQSort(int *a, int begin, int end);
void _NonRecursionQSort1(int *a, int begin, int end);

/*归并排序*/
void MergeSort(int *a, int n);


void MergeSortNonR(int *a, int n);
















