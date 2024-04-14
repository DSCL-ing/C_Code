
#include"Tree.h"







/*����һ��ֵΪx�Ķ������ڵ�*/
BTNode* BuyBTNode(BTDataType x)    //����ֵΪx�Ľڵ�
{

	BTNode *node = (BTNode*)malloc(sizeof(BTNode));//ʹ��ָ��Ҫָ��ʵ�ʿռ�
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






/*ǰ�����*/
void PrevOrder(BTNode *root) //previous  order˳��   NLR��ǰ�����(Preorder Traversal ���
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



/*�������*/
void InOrder(BTNode *root)  // ..��
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




/*��������*/
void PostOrder(BTNode *root) // post- ǰ׺  ..֮��   ..����  ..��
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





/*����������нڵ����*/
int BTSize(BTNode* root)
{
/*
	if (root == NULL)
	{
		return 0;
	}

	//˼�룺������ �� ������ �� �Լ� �Ľڵ��� �ĺ�
	return BTSize(root->left) + BTSize(root->right) + 1;
*/

	//�����ظ��﷨���Ժϲ�
	return !root ? 0 : BTSize(root->left) + BTSize(root->right) + 1;

}




/*�������Ҷ�ӽڵ����*/
int BTLeafSize(BTNode* root)
{
	if (!root)
	{
		return  0;
	}
//˼�룺���ҽڵ�Ϊ�ռ�ΪҶ��
	if(!root->left && !root->right)
	{
		return 1;
	}

	return BTLeafSize(root->left) + BTLeafSize(root->right);

}





/*��������߶�*/
int BTHeight(BTNode *root)
{
	if (!root)
	{
		return 0;
	}



	//˼·���Ƚ����������߶ȣ���ҪС��  ֻ�й�ϵ������ܹ�ʵ�֣��Ƚ�����ѡһ��������һ��

	//����һ��
	//return BTHeight(root->left) > BTHeight(root->right) 
	//	? BTHeight(root->left) + 1 
	//	: BTHeight(root->right) + 1;
/*
	����������ܴ󣬵ݹ�֮��ջ֡�����٣����ݲ��ٱ��棬
		  ÿ�εݹ鶼��������������߶ȣ�ÿ�������߶ȼ��㶼��ָ����*/


	//�Ż�����������

	int leftHeight = BTHeight(root->left);
	int rightHeight = BTHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
/*	����:ͨ�����µ�ǰջ֡���ݣ������ظ�����*/
}





/*���������k��ڵ����*/
int BTLevelKSize(BTNode *root , int k)
{
	/*������k������ô��*/
	if (!root)  
	{
		return 0;
	}

	if (k == 1)   //���һ�㣬��k��
	{
		return 1;
	}

	/*û����k����ô��*/
	return BTLevelKSize(root->left,k-1) + BTLevelKSize(root->right,k-1) ;  //���ǵ�k�㣬�������룬�ҵ���k��
	//Ϊʲô��k-1����Ϊ������k
}






/*����������*/
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

	//����д������������ʽ���������ÿ�
/*
	if (right)
		return right;)*/
	return NULL; //root ��=NULL �� ֵ��Ϊx �����������Ҳ��������ؿ�
}










/*����һ��������*/
BTNode *rebuildBinaryTree(BTDataType* str, int *pi)  // piΪ������±��ַ
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



/*����������*/
void BTDestroy(BTNode*root) /*һ��ָ�봫ֵ�����ú���Ҫ�ں������ÿ�root*/
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
��������

N(Node����L(Left subtree����R(Right subtree��

���ݷ��ʽ���������λ��������
�� NLR��ǰ�����(Preorder Traversal ��ƣ������������
�������ʸ����Ĳ��������ڱ�������������֮ǰ��
�� LNR���������(Inorder Traversal)
�������ʸ����Ĳ��������ڱ�������������֮�У��䣩��
�� LRN���������(Postorder Traversal)
�������ʸ����Ĳ��������ڱ�������������֮��

ǰ���ִ���������ִ���Գ�

*/











