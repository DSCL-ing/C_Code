#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

//�������±귽��

//˼·����ԭ��ɾ�������ж��ظ�
int removeDuplicates(int* nums, int numsSize){
	int begin = 0, dest = 0, end = 0;
	while (end < numsSize)
	{
		if (nums[begin] != nums[end])  //�ж��ظ�����ס�ظ����������
		{
			nums[++dest] = nums[end];//�����ֲ��ȣ���ֵ(�Ӹĵĵ�һ���𣬺���Ķ�Ҫ�޸�)
			begin = end;           //�������
		}
		end++;
	}
	return dest + 1;			//�߼���һ
}