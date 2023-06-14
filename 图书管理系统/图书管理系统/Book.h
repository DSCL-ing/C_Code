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


//ͼ����Ϣ//NAME ISBN PRICE
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

//��ʼ��
void Initialization(struct Book *ps);


//�������
void Add(struct Book * ps);


//ɾ��
void Del(struct Book *ps);

//��ʾ
void Show(const struct Book *ps);

//����
void Search(struct Book *ps);

//�޸�
void Mod(struct Book *ps);

//ð������
void sort(struct Book *ps);

//����
void Destroy(struct Book *ps);

//�洢���ļ�
void Save(struct Book *ps);

//�������������
void CheckCapacity(struct Book*ps);