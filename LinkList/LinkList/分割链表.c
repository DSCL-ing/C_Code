#define _CRT_SECURE_NO_WARNINGS 1

//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking

//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结
//点之前 。

//描述
//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点
//排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

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


class Partition {   //c++兼容C，直接在里面用c语言方式写就好了
public:
	ListNode* partition(ListNode* pHead, int x) {  //C++中省略了struct，
		// write code here
		struct ListNode *lessHead, *greaterHead;  //lessHead放小于x，greaterHead放大于等于x
		struct ListNode *lessTail, *greaterTail;  
		//lessHead和tail都指向哨兵卫结构体，
		lessTail = lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
		greaterTail = greaterHead = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode *cur = pHead;
		while (cur)
		{
			if (cur->val < x) //所有小于x的结点排在其余结点之前
			{
				lessTail->next = cur; 
				lessTail = cur;
			}
			else                //大于等于的排后
			{
				greaterTail->next = cur;
				greaterTail = cur;
				//greaterTail->next = NULL;   //一定要放循环结束，如果最后一个是小则无效

			}
			cur = cur->next;
		}
		greaterTail->next = NULL;   //防止成环
		lessTail->next = greaterHead->next; //链接两链表，丢掉哨兵卫
		struct ListNode * newnode = lessHead->next;  
		free(lessHead);//释放哨兵卫
		free(greaterHead);
		return newnode;
	}
};