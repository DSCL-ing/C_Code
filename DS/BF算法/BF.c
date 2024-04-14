#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>



int BF(char *str, char *sub)
{
	assert(str != NULL && sub != NULL);
	if (str == NULL || str == sub) //release �汾
	{
		return -1;
	}
	int i = 0, j = 0;   //�������Ӵ��±�
	int lenStr = strlen(str);  //��������
	int lenSub = strlen(sub);  //�ִ�����
	while (i < lenStr && j < lenSub)   //�±곬�����Ⱦͽ���
	{
		if (str[i] == sub[j])  //�����ͬ��ͬ����
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;  //�����ͬ 1������  2��i������ǰ��
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