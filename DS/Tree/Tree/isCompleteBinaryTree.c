#include"Tree.h"
#include"Queue.h"

bool isBTComplete(BTNode *root)
{
	if (!root)
	{
		return false;
	}
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, root);

	while (!QueueEmpty(&queue))
	{
		BTNode* front = QueueFront(&queue);
		QueuePop(&queue);
		if (!front) //一定存在下一层节点，所以直接跳出去，不用插入所有节点
		{
			QueuePop(&queue);
			break;
		}
		QueuePush(&queue, front->left);
		QueuePush(&queue, front->right);
	}

	while (!QueueEmpty(&queue))
	{
		if (QueueFront(&queue))
		{
			QueueDestroy(&queue);
			return false;
		}
		QueuePop(&queue);
	}
	QueueDestroy(&queue);
	return true;
}