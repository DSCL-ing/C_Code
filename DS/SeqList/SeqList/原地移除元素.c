#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode-cn.com/problems/remove-element/

//�������±귽��


//OJ��ԭ���Ƴ�Ԫ��
//ԭ�������治����val��ֵ�Ƶ�val��(����˼��Ϊһ��һ��Ų��)
//˼·������ָ�룬begin����������dest������λval,��*begin��Ϊvalʱ����ֵ����*dest��
//ֱ����������ʱ*dest��ǰ�漴Ϊ����������
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

//�������������±꣨�м��ˣ�����ָ���õı����������ࣩ
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
}//�˷�������