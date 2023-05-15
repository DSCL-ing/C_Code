#define _CRT_SECURE_NO_WARNINGS 1

typedef int TreeDataType;




struct TreeNode
{
	TreeDataType data;
	struct TreeNode *child;
	struct TreeNode *brother;
};


