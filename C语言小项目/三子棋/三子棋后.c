#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
#include"头文件.h"



void Display(char board[ROW][COL], int row, int col)
{
	printf("输入坐标如（1，2），按回车键结束\n\n\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
			if (j == col - 1 && i < row - 1)//我的方法是等j合适后再打印横，可读性差，效率低
				//老师的方法是用i来控制
			{
				printf("\n");
				for (int j = 0; j < col; j++)
				{
					printf("---");
					if (j < col - 1)
					{
						printf("|");
					}
				}
			}
		}
		//printf("\n");
		//if (i < row - 1)//老师方法
		//{
		//	for (j = 0; j < col; j++)
		//	{
		//		printf("---");
		//		if (j < col - 1)
		//			printf("|");
		//	}
		//}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");
}

char IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'c';
		}
	}
	return 'd';
}

char IsWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
		if (board[1][1] == board[2][2] && board[2][2] == board[0][0] && board[1][1] != ' ')
			return board[1][1];
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
			return board[1][0];
	}
	int ret = IsFull(board, row, col);
	if ('d'==ret)
	{
		return 'd';
	}
	else
	{
		return 'c';
	}
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				board[i][j] = ' ';
			}
		}
	}
}



void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y = 1;
	printf("玩家走\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <=row&&y >= 1 && y <=col)
			//必须是>=.int转化后为整数，不过不影响
		{
			if (board[x - 1][y - 1] == ' ') // != '*'&&board[x][y] != '#'
			{
				board[x-1][y-1] = '*';
				system("cls");
				Display(board, ROW, COL);
				break;
			}
			else
			{
				printf("坐标已占用，请重新输入\n");
			}
		}
		else
		{
			system("cls");
			Display(board, ROW, COL);
			printf("输入有误，请重新输入\n");
		}

	}


}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走\n");
	int x, y = 1;
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x ][y ] == ' ') //!= '*'&&board[x][y] != '#'
		{
			board[x][y] = '#';
			system("cls");
			Display(board, ROW, COL);
			break;
		}
	}

}