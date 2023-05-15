#include "saolei.h"
void menu()
{
	printf("************************************\n");
	printf("扫雷\n1、开始游戏\n2、退出游戏      \n");
	printf("************************************\n");

}

void game()
{
	
	srand((unsigned int)time(NULL));
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROW, COL, '0');//格式化排查雷
	InitBoard(show, ROW, COL, '*');//格式化布置雷

	SetMine(mine, ROW, COL);//布置雷

//	Display(mine, ROW, COL);//显示地雷
	Display(show, ROW, COL);//显示棋盘

	FindMine(mine, show, ROW, COL);//排查雷(游戏过程)
}

int main()
{

	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		if (input==1)
		{
			printf("游戏开始\n");
			game();
		}
		else if (input == 2)
		{
			printf("退出游戏，");
			exit(0);
		}
		else
		{
			break;
		}
	} while (input);
	
	return 0;
}