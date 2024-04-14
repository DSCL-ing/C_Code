#pragma once


#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* Left;
	struct BinaryTreeNode* Right;
	BTDataType data;
}BTNode;



int TreeLeafSize(BTNode* root)
{
	//分治思想,
	//最小单位:遇到NULL就返回
	if (root == NULL)
		return 0;
	//合并
	else
		return (root->Left == NULL  && root->Right == NULL) ? 1 : TreeLeafSize(root->Left) + TreeLeafSize(root->Right);

}


BTNode* BTreeInit(BTDataType x)
{
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->data = x;
	root->Left = NULL;
	root->Right = NULL;
	return root;
}

int main()
{
	BTNode* A = BTreeInit('A');
	BTNode* B = BTreeInit('B');
	BTNode* C = BTreeInit('C');
	BTNode* D = BTreeInit('D');
	BTNode* E = BTreeInit('E');

	A->Left = B;
	A->Right = C;
	B->Left = D;
	B->Right = E;

	int LeafSize = 0;
	LeafSize = TreeLeafSize(A);
	printf("%d  \n", LeafSize);

	return 0;
}