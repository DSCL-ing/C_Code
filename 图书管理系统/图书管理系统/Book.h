#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

        
#define DEFAULT_SZ 1000
#define MAX_NAME 30
#define MAX_ISBN 20   
#define MAX_PRICE 10

enum option{ EXIT, ADD, DEL, SEARCH, MOD, SHOW ,SAVE};


//图书信息//NAME ISBN PRICE
struct BookInfo
{
    char name[MAX_NAME];
    char ISBN[MAX_ISBN];
    char price[MAX_PRICE];

};

//控制变量
struct Book
{
    int size;
    int capacity;//容量
    struct BookInfo *data;
};

//初始化
void Initialization(struct Book *ps);


//添加数据
void Add(struct Book * ps);


//删除数据
void Del(struct Book *ps);

//显示数据
void Show(struct Book *ps);

//查找数据
void Search(struct Book *ps);

//修改数据
void Mod(struct Book *ps);

//销毁空间
void Destroy(struct Book *ps);

//存储到文件
void Save(struct Book *ps);

//容量检查与增容
void CheckCapacity(struct Book*ps);