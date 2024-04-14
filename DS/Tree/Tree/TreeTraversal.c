
#include"Tree.h"







/*创建一个值为x的二叉树节点*/
BTNode* BuyBTNode(BTDataType x)    //创建值为x的节点
{

	BTNode *node = (BTNode*)malloc(sizeof(BTNode));//使用指针要指向实际空间
	if (!node)
	{
		perror("malloc fail!");
		exit(1);
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}






/*前序遍历*/
void PrevOrder(BTNode *root) //previous  order顺序   NLR：前序遍历(Preorder Traversal 亦称
{
	if (!root )
	{
		printf("NULL ");
		return;
	}
							  
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);

}



/*中序遍历*/
void InOrder(BTNode *root)  // ..中
{

	if (!root )
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}




/*后续遍历*/
void PostOrder(BTNode *root) // post- 前缀  ..之后   ..后面  ..后
{
	if (!root )
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);

}





/*求二叉树所有节点个数*/
int BTSize(BTNode* root)
{
/*
	if (root == NULL)
	{
		return 0;
	}

	//思想：左子树 和 右子树 和 自己 的节点数 的和
	return BTSize(root->left) + BTSize(root->right) + 1;
*/

	//两个重复语法可以合并
	return !root ? 0 : BTSize(root->left) + BTSize(root->right) + 1;

}




/*求二叉树叶子节点个数*/
int BTLeafSize(BTNode* root)
{
	if (!root)
	{
		return  0;
	}
//思想：左右节点为空即为叶子
	if(!root->left && !root->right)
	{
		return 1;
	}

	return BTLeafSize(root->left) + BTLeafSize(root->right);

}





/*求二叉树高度*/
int BTHeight(BTNode *root)
{
	if (!root)
	{
		return 0;
	}



	//思路：比较左右子树高度，不要小的  只有关系运算符能够实现：比较两边选一边舍弃另一边

	//方法一：
	//return BTHeight(root->left) > BTHeight(root->right) 
	//	? BTHeight(root->left) + 1 
	//	: BTHeight(root->right) + 1;
/*
	点评；问题很大，递归之后栈帧会销毁，数据不再保存，
		  每次递归都会计算两次子树高度，每个子树高度计算都是指数级*/


	//优化：方法二：

	int leftHeight = BTHeight(root->left);
	int rightHeight = BTHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
/*	点评:通过记下当前栈帧数据，避免重复计算*/
}





/*求二叉树第k层节点个数*/
int BTLevelKSize(BTNode *root , int k)
{
	/*遇到第k层或空怎么做*/
	if (!root)  
	{
		return 0;
	}

	if (k == 1)   //最后一层，第k层
	{
		return 1;
	}

	/*没到第k层怎么做*/
	return BTLevelKSize(root->left,k-1) + BTLevelKSize(root->right,k-1) ;  //不是第k层，继续深入，找到第k层
	//为什么是k-1，因为传的是k
}






/*二叉树查找*/
BTNode *BTFind(BTNode* root, BTDataType x)
{
	if (!root )
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	BTNode*left = BTFind(root->left ,x);
	if (left)
	{
		return left;
	}
	
	BTNode*right = BTFind(root->right,x);
	if (right)
	{
		return right;
	}

	//可以写成下面这种形式，看起来好看
/*
	if (right)
		return right;)*/
	return NULL; //root ！=NULL ， 值不为x ，左右子树找不到，返回空
}










/*构建一个二叉树*/
BTNode *rebuildBinaryTree(BTDataType* str, int *pi)  // pi为数组的下标地址
{
	if (str[*pi] == '#')
	{
		(*pi)++;
		return  NULL;
	}
	BTNode*root = (BTNode*)malloc(sizeof(BTNode));
	root->data = str[(*pi)++];
	root->left = rebuildBinaryTree(str, pi);
	root->right = rebuildBinaryTree(str, pi);

	return root;

}



/*二叉树销毁*/
void BTDestroy(BTNode*root) /*一级指针传值，调用后需要在函数外置空root*/
{
	if (!root)
	{
		return;
	}
	BTDestroy(root->left);
	BTDestroy(root->right);
	free(root);
	root->left = root->right = NULL;
}








/*
遍历命名

N(Node）、L(Left subtree）和R(Right subtree）

根据访问结点操作发生位置命名：
① NLR：前序遍历(Preorder Traversal 亦称（先序遍历））
——访问根结点的操作发生在遍历其左右子树之前。
② LNR：中序遍历(Inorder Traversal)
——访问根结点的操作发生在遍历其左右子树之中（间）。
③ LRN：后序遍历(Postorder Traversal)
——访问根结点的操作发生在遍历其左右子树之后。

前三种次序与后三种次序对称

*/











