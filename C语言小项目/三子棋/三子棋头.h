#define _CRT_SECURE_NO_DEPRECATE//getch
#define _CRT_NONSTDC_NO_DEPRECATE//getch
#include<stdio.h>
#pragma once
#include <stdlib.h>
#include<time.h>
//参数不能和预处理指令相同
#define ROW 3   //传进大写ROW，参数定义用小写row
#define COL 3   //传进大写COL，参数定义用小写col
#include<conio.h>


void Display(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);

void InitBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row, int col);

char IsFull(char board[ROW][COL], int row, int col);