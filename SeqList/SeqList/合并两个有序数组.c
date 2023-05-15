#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode-cn.com/problems/merge-sorted-array/

//数组用下标方便


//merge [mɜːrdʒ]  合并，结合


//原理：给两数组开头各设置一个控制下标，依次比较两数组元素大或小，将其在一块空间上排列。
//其中一数组排完后，将另一个剩余的全部拷贝过去

//实现：从大开始，从后开始，谁大谁先放。

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int end1 = m - 1;
	int end2 = n - 1;
	int end = n + m - 1;
	while (end1 >= 0 && end2 >= 0) //下标都大于0继续
	{
		if (nums1[end1] >= nums2[end2])//1大等放1
		{
			nums1[end] = nums1[end1];
			end1--;
			end--;
		}
		else  //二大放2
		{
			nums1[end] = nums2[end2];
			end2--;
			end--;
		}
	}
	while (end2 >= 0)//m为0时执行，即num1中元素拍完（0个也算），num2没排完
	{
		nums1[end] = nums2[end2];
		end2--;
		end--;
	}
}


//法二
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int end1 = m - 1;
	int end2 = n - 1;
	int end = n + m - 1;
	//不要吝啬定义变量，辅助记忆+程序效率更高+不容易越界。
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] >= nums2[end2])
		{
			nums1[end--] = nums1[end1--];//只有下接着自增自减才用后置：同理上接自增自减才能用前置
			//end1--;
			//end--;
		}
		else
		{
			nums1[end--] = nums2[end2--];//只有下接着自增自减才用后置：同理上接自增自减才能用前置
			//end2--;
			//end--;
		}
	}

	//由题意：只考虑nums1先结束。nums2结束，nums1已经在那了。无需再动了。
	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
		//end2--;
		//end--;
	}
}
