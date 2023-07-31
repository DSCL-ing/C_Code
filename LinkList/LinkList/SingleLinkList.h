#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SListNode//SingleList
{
	SLDataType data;
	struct SListNode*next;//�Լ������Լ����͵�ָ��

}SListNode;



//SListNode* phead = NULL;//���ڱ�����ֻ����ʼ�����ò��뺯�����ɱ�ͷ
//


// Ҫ�ı䴫������ָ���һ���ڵ��ָ��ʹ�����
// ���ı䴫������ָ���һ���ڵ��ָ��ʹ�һ��
// ֻ���ĺ����ӿڴ�һ��


//�����ڵ�
//���ٿռ䡢���ص�ַ�����ٱ���������ַ��Ч
SListNode * CreateSListNode(SLDataType x);

//---------------------------һ��ָ��----------//

//��ӡ����Ԫ��
void PrintSList(SListNode *phead);

//���������С
int SizeSList(SListNode *phead);

//����
SListNode *FindSList(SListNode *phead, SLDataType x);

//----------------------------------------------//


//---------------------------����ָ��----------//

//β��
//�ж��Ƿ�ձ�:
//�ǿձ�->����CreateNode��
//�ǿ�->��β����
void PushBackSList(SListNode **phead, SLDataType x);




//ͷ��
//�����ж�
void PushFrontSList(SListNode **pphead,SLDataType x);


//βɾ
void PopBackSList(SListNode **pphead);


//ͷɾ
void PopFrontSList(SListNode **pphead);


//�ͷſռ�
void DestroySListNode(SListNode**phead);

//----------------------------------------------//


/*
��������ȱ��
ǰ�����Ҫ֪ǰ�ڵ�
*/



//posλ��ǰ��x
//��Ҫ���Findʹ��
void InsertSList(SListNode **pphead, SListNode *pos, SLDataType x);



//posλ�ú��x;
//��Ҫ���Findʹ��;
void InsertAfterSList(SListNode **pphead, SListNode *pos, SLDataType x);


//����
void EraseSList(SListNode **pphead, SListNode *pos);


void SListEraseAfter(SListNode* pos);

SListNode* FindElement(SListNode*L, SLDataType x);