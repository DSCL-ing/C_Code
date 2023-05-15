#define _CRT_SECURE_NO_WARNINGS 1


#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType *a;
	int size;
	int capacity;
	//顺序表思想
}Heap;

void HeapPrint(Heap *ps);

void HeapInit(Heap *ps);

void HeapDestroy(Heap *ps);

void HeapPush(Heap *ps,HeapDataType x);

void HeapPop(Heap*ps);

int HeapSize(Heap *ps);

bool HeapEmpty(Heap *ps);

//接受一个堆，数组， 数组大小。建一个堆
void HeapCreate(Heap*ps, HeapDataType *a, int size);

void HeapSort(HeapDataType *a, int size);

void AdjustDown(HeapDataType *a, int size, int parent);

void AdjustUp(HeapDataType *a, int child);

void Swap(HeapDataType *p1, HeapDataType *p2);