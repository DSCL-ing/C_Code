#include "saolei.h"


void InitBoard(char board[ROWS][COLS],int row, int col, char Sign)
{
	for (int i = 0; i <= row+1; i++)
	{
		for (int j = 0; j <=col+1; j++)
		{
			board[i][j] =Sign;
		}
	}
}

void Display(char board[ROWS][COLS], int row,int col)
{
	printf("---------扫雷游戏-----------\n");
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <=row; i++)
	{
		printf("%d ",i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}


void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;


	for (int i = 0; i < count; i++)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		mine[x][y] = '1';
	}

}

int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - '0' * 8;
}

void ExpandMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win)//expand:展开,拓展，
{

	int count = get_mine_count(mine, x, y);
	//	printf("count=%d", count);
	if (count == 0)//mine[x][y] == '0'//天啊，难，用错条件就会栈溢出，stack overflow
	{

		show[x][y] = ' ';
		if (show[x - 1][y - 1]  == '*'&&x >= 1 && x <= ROW &&y >= 1 && y <= COL)
			ExpandMine(mine, show, x - 1, y - 1, win);
		if (show[x - 1][y]		== '*'&&x >= 1 && x <= ROW &&y >= 1 && y <= COL)
			ExpandMine(mine, show, x - 1, y,     win);
		if (show[x - 1][y + 1]  == '*'&&x >= 1 && x <= ROW &&y >= 1 && y <= COL)
			ExpandMine(mine, show, x - 1, y + 1, win);
		if (show[x][y - 1]		== '*'&&x >= 1 && x <= ROW &&y >= 1 && y <= COL)
			ExpandMine(mine, show, x,     y - 1, win);
		if (show[x][y + 1]		== '*'&&x >= 1 && x <= ROW &&y >= 1 && y <= COL)
			ExpandMine(mine, show, x,     y + 1, win);
		if (show[x + 1][y - 1]	== '*'&&x >= 1 && x <= ROW &&y >= 1 && y <= COL)
			ExpandMine(mine, show, x + 1, y - 1, win);
		if (show[x + 1][y]		== '*'&&x >= 1 && x <= ROW &&y >= 1 && y <= COL)
			ExpandMine(mine, show, x + 1, y,     win);
		if (show[x + 1][y + 1]  == '*'&&x >= 1 && x <= ROW &&y >= 1 && y <= COL)
			ExpandMine(mine, show, x + 1, y + 1, win);
	}
	else 
	{
		show[x][y] = '0' + count;
	}
}

int Win(char show[][COLS], char mine[][COLS])
{
	int win = 0;
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			if (show[i][j] == '*')
			{
				win++;
			}
		}
	}
//	printf("Mine=%d", win);
	if (win == EASY_COUNT)
	{
		system("cls");
		printf("排雷成功\n");
		for (int i = 1; i <= ROW; i++)//成功后打印地雷
		{
			for (int j = 0; j <= COL; j++)
			{
				if (mine[i][j] == '1')
				{
					show[i][j] = '#';
				}
			}
		}
		Display(show, ROW, COL);
		return 1;
	}
	else
	{
		return 0;
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row,int col)//排除，检查
{
	int win;
	int x=0, y = 0;
	int count = get_mine_count(mine, x, y);
	do
	{
		printf("请输入坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row &&y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					system("cls");
					printf("踩中地雷,GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n");
					for (int i = 1; i <= ROW; i++)
					{
						for (int j = 0; j <= COL; j++)
						{
						
							if (mine[i][j] == '1')
							{
								show[i][j] = '#';
							}
							if (show[i][j]=='*')
							{
								show[i][j] = ' ';
							}
						}
					}
					Display(show, row, col);
					getch();
					system("cls");
					break;
				}
				else
				{
					ExpandMine(mine, show, x, y, &win);
					system("cls");
					Display(show, row, col);//显示周围雷数
					if ( Win(show,mine))
					{
						getch();
						system("cls");
						break;
					}
					else
					{
						;
					}
				}
			}
			else
			{
				printf("已经排查，请重新选择\n");
			}
		}
		else
		{
			printf("输入错误\n");
		}
	} while (1);
}





