#include"Heap.h"


void HeapText1()
{
	//Heap heap;
	HeapDataType a[10] = { 13, 15, 6, 54, 66, 27, 14, 25, 3, 4 };

	//���ϵ����㷨����
	//HeapInit(&heap); //2727 66 213 25 54 6 14 15 3 4
	//for (int i = 0; i < 10; i++)
	//{
	//	HeapPush(&heap, a[i]);
	//}


	//���µ����㷨����
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
	//HeapTopK(); //TopK���⣬ѡ������ǰK�������ܿ� ֻ��logN
	TopK();
	return 0;
}