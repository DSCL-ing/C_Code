#define _CRT_SECURE_NO_DEPRECATE//getch
#define _CRT_NONSTDC_NO_DEPRECATE//getch
#include<stdio.h>
#pragma once
#include <stdlib.h>
#include<time.h>
//�������ܺ�Ԥ����ָ����ͬ
#define ROW 3   //������дROW������������Сдrow
#define COL 3   //������дCOL������������Сдcol
#include<conio.h>


void Display(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);

void InitBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row, int col);

char IsFull(char board[ROW][COL], int row, int col);