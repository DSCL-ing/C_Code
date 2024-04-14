
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
	{
		return 1;
	}
	else if (p == NULL&&p != q || q == NULL && p != q)
	{ /*ע���߼������Ⱥ�˳������if-else���ж���1��NULL����Ϊǰ�ᣬ�����Ҫ�����п�*/
		//�����Ż��� p == NULL && q == NULL,��Ϊ����ǰ��;
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

	if (root->val == subRoot->val) //�����ȣ�������ͬ������������
	{
		if (isSameTree(root, subRoot))
		{
			return true;
		}
	}

	return isSubtree(root->left, subRoot)
		|| isSubtree(root->right, subRoot);
}