#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

        
#define DEFAULT_SZ 1000
#define MAX_NAME 10   
#define MAX_SEX 5
#define MAX_TELE 20
#define MAX_ADDR 30
//#define MAX_SIZE 1000  //size大小


//函数名量化
enum option{ EXIT, ADD, DEL, SEARCH, MOD, SHOW ,SAVE};


//人员信息//name sex age tele address
struct PeopleInformation
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

//通讯录信息
struct Contact
{
    int size;
    int capacity;//容量
    struct PeopleInformation *data;//只能从预处理指令改变数组
};

//初始化
void Initialization(struct Contact *ps);


//添加数据
void Add(struct Contact * ps);


//删除数据
void Del(struct Contact *ps);

//显示数据
void Show(const struct Contact *ps);

//查找数据
void Search(const struct Contact *ps);

//修改数据
void Mod(struct Contact *ps);

//销毁空间
void Destroy(struct Contact *ps);

//存储到文件
void Save(struct Contact *ps);

//容量检查与增容
void CheckCapacity(struct Contact*ps);