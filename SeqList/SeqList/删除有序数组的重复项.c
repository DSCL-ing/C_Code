#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

//数组用下标方便

//思路：比原地删除多了判断重复
int removeDuplicates(int* nums, int numsSize){
	int begin = 0, dest = 0, end = 0;
	while (end < numsSize)
	{
		if (nums[begin] != nums[end])  //判断重复，记住重复的数的起点
		{
			nums[++dest] = nums[end];//当出现不等，赋值(从改的第一个起，后面的都要修改)
			begin = end;           //重置起点
		}
		end++;
	}
	return dest + 1;			//逻辑加一
}