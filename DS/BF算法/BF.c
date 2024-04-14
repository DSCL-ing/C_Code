#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>



int BF(char *str, char *sub)
{
	assert(str != NULL && sub != NULL);
	if (str == NULL || str == sub) //release 版本
	{
		return -1;
	}
	int i = 0, j = 0;   //主串、子串下标
	int lenStr = strlen(str);  //主串长度
	int lenSub = strlen(sub);  //字串长度
	while (i < lenStr && j < lenSub)   //下标超过长度就结束
	{
		if (str[i] == sub[j])  //如果相同就同步走
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;  //如果不同 1、重置  2、i独自往前走
			j = 0;
		}
	}
	if (j >= lenSub)
	{
		return i-j;
	}
	return -1;
}

int main()
{
	printf("%d\n", BF("abcdefga", "def"));//3
	printf("%d\n", BF("abcdefhagav", "abf"));//-1
	printf("%d\n", BF("abcdefwtywa", "abc"));//0
	return 0;
}