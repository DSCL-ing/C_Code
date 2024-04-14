#pragma once


#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include"stdlib.h"
#include"string.h"



/*ֱ�Ӳ�������*/
void InsertSort(int* a, int n);

/*ϣ������*/
void ShellSort(int *a, int n);

/*ֱ�Ӳ�������*/
void SelectSort(int *a, int n);

/*������*/
void HeapSort(int *a, int size);

/*ð������*/
void BubbleSort(int *a, int n);

/*��������(R)*/
void QuickSort(int *a, int begin ,int end);

/*��·���ֿ���*/
void partitionQSort(int *a, int begin, int end);

/*�ǵݹ����*/
void _NonRecursionQSort(int *a, int begin, int end);
void _NonRecursionQSort1(int *a, int begin, int end);

/*�鲢����*/
void MergeSort(int *a, int n);


void MergeSortNonR(int *a, int n);
















