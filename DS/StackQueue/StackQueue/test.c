#include"Stack.h"
#include"Queue.h"

Test1()
{
	Stack stack;
	StackInit(&stack);

	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	//StackPop(&stack);

	printf("StackSize:>%d \n", StackSize(&stack));
	while (!StackEmpty(&stack))
	{
		printf("%d ", (&stack)->top);
		StackPop(&stack);
	}
	StackDestroy(&stack);
}

void Test2()
{
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 5);
	printf("QueueSize:>%d \n", QueueSize(&queue));
	printf("QueueBack:>%d \n", QueueBack(&queue));
	while (!QueueEmpty(&queue))
	{
		printf("%d ", QueueFront(&queue));
		QueuePop(&queue);
	}
	printf("\n ");
	printf("QueueSize:>%d \n", QueueSize(&queue));
	QueueDestroy(&queue);

}






int main()
{
	//Test1(); // Stack test
	Test2(); // Queue test


	return 0;
}