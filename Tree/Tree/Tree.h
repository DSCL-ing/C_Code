#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//树的遍历

//根据不同的递归遍历方法  访问  每个树（结构体）的data和左右孩子  进行操作。

//每次递归到一颗新树（每个节点都是一颗树），都要先判断是否空树 ---- 以防止野指针错误


//---- 创建二叉树 ----

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode *left;  //left sub tree
	struct BinaryTreeNode *right; //right sub tree
}BTNode;


/*
node->data = x;
node->left = NULL;
node->right = NULL;
*/
BTNode* BuyBTNode(BTDataType x);//构建值为x的节点


/*
printf("%d", root->data);
PrevOrder(root->left);
PrevOrder(root->right);
*/
void PrevOrder(BTNode *root);//先根遍历


/*
PrevOrder(root->left);s
printf("%d", root->data);
PrevOrder(root->right);
*/
void InOrder(BTNode *root); //中根遍历


/*
PrevOrder(root->left);
PrevOrder(root->right);
printf("%d", root->data);
*/
void PostOrder(BTNode *root); //后根遍历

void LevelOrder(BTNode *root); //层序遍历


/*
return BTSize(root->left) + BTSize(root->right) + 1;
*/
int BTSize(BTNode* root); //求二叉树节点个数


/**/
int BTLeafSize(BTNode* root); //求二叉树叶子节点个数


int BTHeight(BTNode *root);//求二叉树高度

int BTLevelKSize(BTNode *root, int k);//计算二叉树第k层节点

BTNode *BTFind(BTNode* root, BTDataType x); //二叉树查找某节点地址

void BTDestroy(BTNode*root); //二叉树销毁

BTNode * rebuildBinaryTree(BTDataType* str, int *pi);  //构建一颗二叉树, pi为数组的下标地址


bool isBTComplete(BTNode *root);















