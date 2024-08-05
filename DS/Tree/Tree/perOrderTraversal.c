#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"

int TreeSize(struct BinaryTreeNode *root)
{
	return !root ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void _preorderTraversal(struct BinaryTreeNode *root, int *str, int* pi)
{
	if (!root)
	{
		return ;
	}
	str[(*pi)++] = root->data;
	_preorderTraversal(root->left, str, pi);
	_preorderTraversal(root->right, str, pi);
}

int* preorderTraversal(struct BinaryTreeNode* root, int* returnSize){

	*returnSize = TreeSize(root);
	int *a = (int*)malloc(*returnSize * sizeof(int));
	int i = 0;
	_preorderTraversal(root, a, &i);
	return a;
}



























