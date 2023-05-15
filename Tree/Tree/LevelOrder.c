

#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"
#include"Queue.h"


void LevelOrder(BTNode *root)
{
	//通过队列实现
	Queue queue;//不带指针==给空间 ， 带指针==只给指针空间，成员无空间
	QueueInit(&queue);
	if (root)
		QueuePush(&queue, root);

	//通过队列缓存子树滚动数据实现遍历
	while (!QueueEmpty(&queue))
	{
		BTNode* front = QueueFront(&queue);//把数据从队列中取出
		printf("%d ", front->data);
		QueuePop(&queue);
		if (front->left)
		{
			QueuePush(&queue, front->left);
		}
		if (front->right)
		{
			QueuePush(&queue, front->right);
		}
	}
	QueueDestroy(&queue);

}



void LevelOrder2(BTNode *root)
{
	if (!root)
	{
		return;
	}
	Queue queue;
	QueueInit(&queue);
	int levelSize = 0;

	QueuePush(&queue, root);
	levelSize = 1;
	while (!QueueEmpty(&queue))
	{
		while (levelSize--)
		{
			BTNode* front = QueueFront(&queue);
			printf("%d ", front->data);
			QueuePop(&queue);
			if (front->left)
				QueuePush(&queue, front->left);
			if (front->right)
				QueuePush(&queue, front->right);
		}
			printf("\n");
			levelSize = QueueSize(&queue);

	}

	QueueDestroy(&queue);
}