#define _CRT_SECURE_NO_WARNINGS 1

//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking

//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ�
//��֮ǰ ��

//����
//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ��
//����������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/

struct ListNode 
{
	int val;
	struct ListNode *next;
};


class Partition {   //c++����C��ֱ����������c���Է�ʽд�ͺ���
public:
	ListNode* partition(ListNode* pHead, int x) {  //C++��ʡ����struct��
		// write code here
		struct ListNode *lessHead, *greaterHead;  //lessHead��С��x��greaterHead�Ŵ��ڵ���x
		struct ListNode *lessTail, *greaterTail;  
		//lessHead��tail��ָ���ڱ����ṹ�壬
		lessTail = lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
		greaterTail = greaterHead = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode *cur = pHead;
		while (cur)
		{
			if (cur->val < x) //����С��x�Ľ������������֮ǰ
			{
				lessTail->next = cur; 
				lessTail = cur;
			}
			else                //���ڵ��ڵ��ź�
			{
				greaterTail->next = cur;
				greaterTail = cur;
				//greaterTail->next = NULL;   //һ��Ҫ��ѭ��������������һ����С����Ч

			}
			cur = cur->next;
		}
		greaterTail->next = NULL;   //��ֹ�ɻ�
		lessTail->next = greaterHead->next; //���������������ڱ���
		struct ListNode * newnode = lessHead->next;  
		free(lessHead);//�ͷ��ڱ���
		free(greaterHead);
		return newnode;
	}
};