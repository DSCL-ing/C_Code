


//https://leetcode-cn.com/problems/symmetric-tree/




#include "Tree.h"


bool _isSymmetric(BTNode *root1, BTNode *root2)
{
	if (!root1 &&!root2)
	{
		return true;
	}
	if (!root1 || !root2)
	{
		return false;

	}

	if (root1->data != root2->data)
	{
		return false;
	}

	return _isSymmetric(root1->left, root2->right) && _isSymmetric(root1->right, root2->left);
}


bool isSymmetric(BTNode *root)
{
	return !root || _isSymmetric(root->left, root->right);

}