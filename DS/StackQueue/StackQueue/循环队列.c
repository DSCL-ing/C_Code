//https://leetcode-cn.com/problems/design-circular-queue/


#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int CQDataType;


/*
（非空是rear是最后元素的下一个，空间满后rear == front，和空队列时一样，
为避免这种情况，开多一个空间，使rear->next == front时队满）
*/

//用一个结构体也可以的，因为此处不需要强调头尾，其他都是小变量，
typedef struct {
	CQDataType* a; //大小为k+1个，解决队空队满问题
	int k;        //k个可用空间
	int front;   //头节点位置（从0开始）
	int rear;    //尾节点位置（从0开始）
	//头尾位置都需要控制在k以内，需要模来实现instantiate
} MyCircularQueue;    


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = (CQDataType*)malloc((k + 1)*sizeof(CQDataType));//给数组开辟k+1个CQDataType空间
	//==42==错误，可能是开辟，可能是泄露
	cq->k = k;//默认为4
	cq->front = 0;
	cq->rear = 0;
	return cq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;            //front = rear 则空
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {

	return obj->front == (obj->rear + 1) % (obj->k + 1);
	//规律：进位数从1开始，计量数从0开始。可实现循环。设k为最大数，则进位数为k + 1,
	//则（n） = （n + k+1）%(k+1);//n<=k
	//任何逻辑数模进位（容量）都为基值（减掉容量的最高倍数的正数）
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->a[obj->rear] = value;
	obj->rear++;   
	//obj->rear = (obj->rear ) % (obj->k + 1);
	obj->rear %= (obj->k + 1);
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	obj->front++;
	//obj->front = (obj->front) % (obj->k + 1);
	obj->front %= (obj->k + 1);
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	
	//法二
	int i = (obj->tail + obj->k) % (obj->k + 1);
	return obj->a[i];

	if (obj->rear == 0)   //如果rear为0，则直接返回a[k]。因为模实现的循环不能减法。（麻烦）
	{
		return obj->a[obj->k];
	}
	return obj->a[obj->rear-1];
}


void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->a);
	free(obj);
}


int main()
{
	int k = 4;
	int value = 1;
	MyCircularQueue* obj = myCircularQueueCreate(k);
	bool param_1 = myCircularQueueEnQueue(obj, value);

	bool param_2 = myCircularQueueDeQueue(obj);

	int param_3 = myCircularQueueFront(obj);

	int param_4 = myCircularQueueRear(obj);

	bool param_5 = myCircularQueueIsEmpty(obj);

	bool param_6 = myCircularQueueIsFull(obj);

	myCircularQueueFree(obj);

	return 0;
}
