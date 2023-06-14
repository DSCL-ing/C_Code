#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

        
#define DEFAULT_SZ 5
#define MAX_NAME 30
#define MAX_ISBN 20   
#define MAX_PRICE 10

enum option{ EXIT, ADD, DEL, SEARCH, MOD,SORT, SHOW ,SAVE};


//图书信息//NAME ISBN PRICE
struct BookInfo
{
    char name[MAX_NAME];
    char ISBN[MAX_ISBN];
    char price[MAX_PRICE];

};


struct Book
{
    int size;
    int capacity;
    struct BookInfo *data;
};

//初始化
void Initialization(struct Book *ps);


//添加数据
void Add(struct Book * ps);


//删除
void Del(struct Book *ps);

//显示
void Show(const struct Book *ps);

//查找
void Search(struct Book *ps);

//修改
void Mod(struct Book *ps);

//冒泡排序
void sort(struct Book *ps);

//销毁
void Destroy(struct Book *ps);

//存储到文件
void Save(struct Book *ps);

//容量检查与增容
void CheckCapacity(struct Book*ps);