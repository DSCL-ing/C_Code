
#define _CRT_SECURE_NO_WARNINGS 
#include<math.h>
#include<stdio.h>
//#pragma warning(disable:4996)

int main()
{
    int count = 10; //循环条件初始化
    while (count > 10) //循环条件判定
    {
        printf("%d\n", count);
        count--; //循环条件更新
    }
    return 0;
}
