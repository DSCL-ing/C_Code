#define _CRT_SECURE_NO_WARNINGS 1



//https://leetcode-cn.com/problems/univalued-binary-tree/



//�ҵ�һ��д�Ĵ��룺��û����ݹ�����
/*
bool isUnivalTree(struct TreeNode* root){
	int index = 1;

	if (root == NULL)
	{
		return index == 1;
	}

	if (root->left != NULL)
	{
		if (root->val != root->left->val)
		{
			index = 0;
			return index == 1;
		}
		else
			index = isUnivalTree(root->left);
	}

	if (index == 0)   //�ж��������Ƿ������⣬Ȼ���ٵ�������
	{
		return index;
	}

	if (root->right != NULL)
	{
		if (root->val != root->right->val)
		{
			index = 0;
			return index == 1;
		}
		else
			index = isUnivalTree(root->right);
	}

	return index == 1;  
}*/


bool isUnivalTree(struct TreeNode* root){

	if (root == NULL)
	{
		return true;
	}

	if (root->left && root->left->val != root->val)
	{
		return false;
	}

	if (root->right && root->right->val != root->val)
	{
		return false;
	}
	//�ָ��ߣ��������Լ�����һ����

	return isUnivalTree(root->left) && isUnivalTree(root->right);
}