#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_DEPRECATE//getch
#define _CRT_NONSTDC_NO_DEPRECATE//getch
#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>




#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 3//���������'_'��ν����ֱ����,ǰ���д


void InitBoard(char board[ROWS][COLS], int row, int col, char Sign);//��ʽ��
      
void Display(char board[ROWS][COLS], int row, int col);//��ʾ����
void SetMine(char mine[ROWS][COLS], int row, int col);//������
int get_mine_count(char mine[ROWS][COLS], int x, int y);
void ExpandMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int* win);
void FindMine(char mine, char show, int row, int col);//�Ų���(��Ϸ����)
