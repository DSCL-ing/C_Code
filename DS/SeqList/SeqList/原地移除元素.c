#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode-cn.com/problems/remove-element/

//数组用下标方便


//OJ：原地移除元素
//原理：将后面不等于val的值移到val。(常规思想为一个一个挪动)
//思路：快慢指针，begin用来遍历，dest用来定位val,当*begin不为val时，将值赋给*dest，
//直到结束，此时*dest的前面即为所求新数组
int removeElement(int* nums, int numsSize, int val){
	int *begin, *dest;
	begin = dest = nums;
	int sz = 0;
	while (numsSize)
	{
		if (*begin != val)
		{
			*dest = *begin;
			sz++;
			dest++;
		}
		begin++;
		numsSize--;
	}
	return sz;
}

//方法二：快慢下标（中计了，快慢指针用的变量反而更多）
int removeElement(int* nums, int numsSize, int val){
	int begin = 0, dest = 0;
	while (begin<numsSize)
	{
		if (nums[begin] != val)
		{
			nums[dest] = nums[begin];
			dest++;
		}
		begin++;
	}
	return dest;
}//此方法更快