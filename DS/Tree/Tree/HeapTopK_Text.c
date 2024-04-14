#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
#include<time.h>

//取前K个最大数
#define K 10

void TopK()
{
	
	int n = 10000;//int n = 10000;//数据量
	int randMax = 10000;//int randMax = 10000;
	int minHeap[K] ;
	//int K = 100;

	memset(minHeap, 0, sizeof(minHeap));//初始化数组,且用sizeof(arr)---不用取地址
	srand((size_t)time(0));//不用加size_t也行，NULL实际上会被time强制转换成(void)0
	
	//TopK问题思路s
	//建一个大小为K的堆

	FILE *fin = fopen("data.txt", "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}

	//随机写入数据，rand ， 使用fprintf("fout","%d ",)

	int randK = K;//int randK = K;
	for (int i = 0; i < n ;i++)
	{
		int val = rand() % randMax;  //最大值不超过randMax
		if (val % 3 == 0 && randK-- > 0) 
		{
			val = randMax + randK;   //插入自定义最大值
		}
		fprintf(fin, "%d ", val);
	}
	//如果插入的最大值不够K个，就在末尾补上  --------出现的概率很小，忽略
	while (randK-- > 0)
	{
		fprintf(fin, "%d ", randMax+randK);//注意分隔符，分隔给人看的，使用空格或\n方便用fscanf默认的分隔符识别
	}
	fprintf(fin, "%d ", 99999); //--- 验证能否插入且插入到最后

	fclose(fin);


	//for (int i = 0 ; i < K; i++)
	//{
	//	AdjustDown(minHeap, K, 0);
	//}

	FILE *fout = fopen("data.txt", "r");//重置文件指针
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}



	int tmp;
	while (fscanf(fout, "%d", &tmp) != EOF) //注意，由于设置了scanf的默认分隔符空格或\n，随意不用在格式%d后带分隔符识别
	{
		//从文件中提取数据
		//提一个就和堆顶比较一次
		//随着文件指针走下去会比较完文件所有数据
		//ASCII文件使用fscanf("流","格式","dest");
		if (tmp >minHeap[0])
		{
			minHeap[0] = tmp;
		}
		AdjustDown(minHeap, K, 0);//换一次调堆一次
	}
	fclose(fout);

	for (int i = 0; i < K; i++)//打印数组
	{
		printf("%d ", minHeap[i]);
	}
}

