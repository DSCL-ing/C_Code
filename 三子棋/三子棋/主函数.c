#define _CRT_SECURE_NO_WARNINGS 1
#include"头文件.h"

void menu()
{
	printf("************************************\n");
	printf("三子棋游戏\n1、开始游戏\n2、退出游戏\n");
	printf("************************************\n");

}

void game()
{
	int ret = 0;//
	char board[ROW][COL] = { ' ' };//二维数组传参要学习
	system("cls");
	//游戏显示
	Display(board, ROW, COL);
	//格式化棋盘
	InitBoard(board, ROW, COL);
	while (1)//游戏过程
	{
		system("cls");
		//游戏显示
		Display(board, ROW, COL);
		
		PlayerMove(board, ROW, COL);//玩家移动
		ret=IsWin(board, ROW, COL);	//判断输赢
		if (ret !='c')
		{
			break;
		}
		ComputerMove(board, ROW, COL);		//电脑移动
		ret=IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if ('*' == IsWin(board, ROW, COL))//c（continue）==继续，*==玩家赢，
		//d(draw)==平局，#（lose）==玩家输，电脑赢
	{
		printf("玩家胜利\n");
		printf("按任意键转到菜单");
		getch();
	}
	else if ('#' == IsWin(board, ROW, COL))
	{
		printf("电脑胜利\n");
		printf("请按任意键继续");
		getch();
	}
	else if ('d' == IsWin(board, ROW, COL))
	{
		printf("平局");
		printf("请按任意键继续");
		getch();
	}
}


int main()
{
	srand((unsigned int)time(NULL));

	int input=0;

	do
	{
		system("cls");
		menu();
		scanf("%d", &input);
		//游戏菜单
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("游戏结束，");
			exit(0);

		default:printf("输入错误，请重新输入\n");
		}
	} while (input);
	

	//
	return 0;
}