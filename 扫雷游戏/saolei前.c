#include "saolei.h"
void menu()
{
	printf("************************************\n");
	printf("ɨ��\n1����ʼ��Ϸ\n2���˳���Ϸ      \n");
	printf("************************************\n");

}

void game()
{
	
	srand((unsigned int)time(NULL));
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROW, COL, '0');//��ʽ���Ų���
	InitBoard(show, ROW, COL, '*');//��ʽ��������

	SetMine(mine, ROW, COL);//������

//	Display(mine, ROW, COL);//��ʾ����
	Display(show, ROW, COL);//��ʾ����

	FindMine(mine, show, ROW, COL);//�Ų���(��Ϸ����)
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
			printf("��Ϸ��ʼ\n");
			game();
		}
		else if (input == 2)
		{
			printf("�˳���Ϸ��");
			exit(0);
		}
		else
		{
			break;
		}
	} while (input);
	
	return 0;
}