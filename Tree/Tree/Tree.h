#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//���ı���

//���ݲ�ͬ�ĵݹ��������  ����  ÿ�������ṹ�壩��data�����Һ���  ���в�����

//ÿ�εݹ鵽һ��������ÿ���ڵ㶼��һ����������Ҫ���ж��Ƿ���� ---- �Է�ֹҰָ�����


//---- ���������� ----

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
BTNode* BuyBTNode(BTDataType x);//����ֵΪx�Ľڵ�


/*
printf("%d", root->data);
PrevOrder(root->left);
PrevOrder(root->right);
*/
void PrevOrder(BTNode *root);//�ȸ�����


/*
PrevOrder(root->left);s
printf("%d", root->data);
PrevOrder(root->right);
*/
void InOrder(BTNode *root); //�и�����


/*
PrevOrder(root->left);
PrevOrder(root->right);
printf("%d", root->data);
*/
void PostOrder(BTNode *root); //�������

void LevelOrder(BTNode *root); //�������


/*
return BTSize(root->left) + BTSize(root->right) + 1;
*/
int BTSize(BTNode* root); //��������ڵ����


/**/
int BTLeafSize(BTNode* root); //�������Ҷ�ӽڵ����


int BTHeight(BTNode *root);//��������߶�

int BTLevelKSize(BTNode *root, int k);//�����������k��ڵ�

BTNode *BTFind(BTNode* root, BTDataType x); //����������ĳ�ڵ��ַ

void BTDestroy(BTNode*root); //����������

BTNode * rebuildBinaryTree(BTDataType* str, int *pi);  //����һ�Ŷ�����, piΪ������±��ַ


bool isBTComplete(BTNode *root);















