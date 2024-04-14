#define _CRT_SECURE_NO_WARNINGS 1

#include"Tree.h"


int main()
{
	
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);
	BTNode* n7 = BuyBTNode(7);

/*
			1
	2				3
3		N		5		6

*/


	n1->left = n2;
	n1->right =n4;
	n2->left = n3;
	//n2->right =n7;  //--插入标记flag
	n4->left = n5;
	n4->right =n6;

/*
前序：1 2 3 NULL NULL NULL 4 5 NULL NULL 6 NULL NULL
中序：NULL 3 NULL 2 NULL 1 NULL 5 NULL 4 6 NULL NULL
后续：NULL NULL 3 NULL 2 NULL NULL 5 NULL NULL 6 4 1
层序：1     2   4  3   5    6
*/
	PrevOrder(n1);
	printf("\n");
	InOrder(n1);
	printf("\n");
	PostOrder(n1);
	printf("\n");
	LevelOrder(n1);
	printf("\n");

	LevelOrder2(n1);

	printf("节点个数:>%d \n",BTSize(n1));
	printf("叶子节点个数:>%d \n", BTLeafSize(n1));
	printf("数的高度:>%d \n", BTHeight(n1));
	printf("第K层节点个数:>%d \n", BTLevelKSize(n1,3));
	BTNode* n;
	n = BTFind(n1, 7);
	printf("找到值为x的节点%p\n", n);
	printf("是否完全二叉树:>%d \n", isBTComplete(n1));
	BTDestroy(n1); n1 = NULL;


	return 0;

}

