

#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"
#include"Queue.h"


void LevelOrder(BTNode *root)
{
	//ͨ������ʵ��
	Queue queue;//����ָ��==���ռ� �� ��ָ��==ֻ��ָ��ռ䣬��Ա�޿ռ�
	QueueInit(&queue);
	if (root)
		QueuePush(&queue, root);

	//ͨ�����л���������������ʵ�ֱ���
	while (!QueueEmpty(&queue))
	{
		BTNode* front = QueueFront(&queue);//�����ݴӶ�����ȡ��
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