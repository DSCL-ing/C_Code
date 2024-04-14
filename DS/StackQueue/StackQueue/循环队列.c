//https://leetcode-cn.com/problems/design-circular-queue/


#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int CQDataType;


/*
���ǿ���rear�����Ԫ�ص���һ�����ռ�����rear == front���Ϳն���ʱһ����
Ϊ�����������������һ���ռ䣬ʹrear->next == frontʱ������
*/

//��һ���ṹ��Ҳ���Եģ���Ϊ�˴�����Ҫǿ��ͷβ����������С������
typedef struct {
	CQDataType* a; //��СΪk+1��������ӿն�������
	int k;        //k�����ÿռ�
	int front;   //ͷ�ڵ�λ�ã���0��ʼ��
	int rear;    //β�ڵ�λ�ã���0��ʼ��
	//ͷβλ�ö���Ҫ������k���ڣ���Ҫģ��ʵ��instantiate
} MyCircularQueue;    


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = (CQDataType*)malloc((k + 1)*sizeof(CQDataType));//�����鿪��k+1��CQDataType�ռ�
	//==42==���󣬿����ǿ��٣�������й¶
	cq->k = k;//Ĭ��Ϊ4
	cq->front = 0;
	cq->rear = 0;
	return cq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;            //front = rear ���
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {

	return obj->front == (obj->rear + 1) % (obj->k + 1);
	//���ɣ���λ����1��ʼ����������0��ʼ����ʵ��ѭ������kΪ����������λ��Ϊk + 1,
	//��n�� = ��n + k+1��%(k+1);//n<=k
	//�κ��߼���ģ��λ����������Ϊ��ֵ��������������߱�����������
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
	
	//����
	int i = (obj->tail + obj->k) % (obj->k + 1);
	return obj->a[i];

	if (obj->rear == 0)   //���rearΪ0����ֱ�ӷ���a[k]����Ϊģʵ�ֵ�ѭ�����ܼ��������鷳��
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
