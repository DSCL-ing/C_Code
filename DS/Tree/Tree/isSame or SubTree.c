
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

#include<stdio.h>
struct TreeNode
{
	int val;
	struct TreeNode* left;  //left sub tree
	struct TreeNode* right; //right sub tree
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
	{
		return 1;
	}
	else if (p == NULL&&p != q || q == NULL && p != q)
	{ /*注意逻辑运算先后顺序，整个if-else是判断有1个NULL以上为前提，运算符要求先有空*/
		//可以优化成 p == NULL && q == NULL,因为已有前提;
		return 0;
	}

	if (p->val != q->val)
	{
		return 0;
	}
	else
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
	if (subRoot == NULL)
	{
		return true;
	}

	if (root == NULL)
	{
		return false;
	}

	if (root->val == subRoot->val) //如果相等，且是相同子树，返回真
	{
		if (isSameTree(root, subRoot))
		{
			return true;
		}
	}

	return isSubtree(root->left, subRoot)
		|| isSubtree(root->right, subRoot);
}