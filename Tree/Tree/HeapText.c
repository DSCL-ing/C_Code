#include"Heap.h"


void HeapText1()
{
	//Heap heap;
	HeapDataType a[10] = { 13, 15, 6, 54, 66, 27, 14, 25, 3, 4 };

	//向上调整算法建堆
	//HeapInit(&heap); //2727 66 213 25 54 6 14 15 3 4
	//for (int i = 0; i < 10; i++)
	//{
	//	HeapPush(&heap, a[i]);
	//}


	//向下调整算法建堆
	//HeapCreate(&heap, a, 10);  //2727 66 213 54 15 6 14 25 3 4

	HeapSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}


	//HeapPop(&heap);
	//HeapPop(&heap);


	//HeapPrint(&heap);

	//HeapDestroy(&heap);


}


//void HeapTopK()
//{
//	Heap heap;
//	HeapInit(&heap);
//	HeapDataType a[10] = { 13, 15, 6, 54, 66, 27, 14, 25, 3, 4 };
//	for (int i = 0; i < 10; i++)
//	{
//		HeapPush(&heap, a[i]);
//	}
//
//	int K = 5;
//	while (K--)
//	{
//		printf("%d ", HeapTop(&heap));
//		HeapPop(&heap);
//
//	}
//}

void TopK();

int main()
{
	//HeapText1();
	//HeapTopK(); //TopK问题，选出最大的前K个数，很快 只需logN
	TopK();
	return 0;
}