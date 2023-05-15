#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define ROW 3
#define COL 3


int MateData(int num[ROW], char name[ROW][COL]) //匹配
{
    int input = 0;
    printf("请输入ISBN： ");
    scanf("%d", &input);
    int i = 0;
    for (i = 0; i < ROW; i++)
    {
        if (input == num[i])
        {
            return i;
        }
    }

}

void InitData(int num[ROW],char name[ROW][COL])//init 初始化
{

    int i = 0;
    for ( i = 0; i < ROW; i++)
    {
        printf("请输入ISBN：");
        scanf("%d", &num[i]);
        printf("请输入书名：");
        getchar();
        gets(name[i]);//scanf("%s", &name[ROW][0]);
    }
    printf("初始化完成,");
    system("pause");
}

void sort(int num[ROW], char name[ROW][COL])   //排序
{
    int i = 0;        
    int j = 0;
    int tmp1 = 0;
    char tmp2[10] = { 0 };
    for ( i = 0; i < ROW-1; i++)
    {
        for ( j = i; j <ROW; j++)
        {
            if (num[i] > num[j])
            {
                tmp1 = num[i];
                num[i] = num[j];
                num[j] = tmp1;
                strcpy(tmp2, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tmp2);
            }
        }
    }
}

void Search(int num[], char name[][COL])   //二分查找
{
    sort(num, name);
    int left = 0, right = ROW-1;
    int mid = 0;
    int input = 0;
    input = MateData(num,name);
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (input < mid)
            right = mid-1;
        else if (input > mid)
            left = mid+1;
        else
        {
            printf("name:%s\n", name[input]);
            system("pause");
            return;
        }
    }
    printf("\n error");
    system("pause");
}

void Print(int num[], char name[][COL])   //遍历打印
{
    sort(num,name);
    int i = 0;
    for ( i = 0; i < ROW; i++)
    {
        printf("ISBN:%-5d 书名:%s\n", num[i],name[i]);
    }
    system("pause");
}
void ChangeData(int num[], char name[][COL])   //更改数据
{
    int i =MateData(num, name);
    printf("请修改ISBN和书名：");
    scanf("%d%s", &num[i],name[i]);
    printf("修改完成,");
    system("pause");
}

void menu()
{
    printf("*****************************************\n");
    printf("*** 1.初始化数据   2.显示已存储数据   ***\n");
    printf("*** 3.查找数据     4.修改数据         ***\n");
    printf("*** 0.exit                            ***\n");
    printf("*****************************************\n");

}

int main()
{

    int input = 1;
    char name[ROW][COL] = { 0 };
    int num[ROW] = { 0 };

    while (input)
    {
        menu();
        printf("请选择功能:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:InitData(num,name); break;
        case 2:Print(num,name); break;
        case 3:Search(num,name); break;
        case 4:ChangeData(num, name); break;
        case 0:exit(0);
        }
        system("cls");
    }
    return 0;
}