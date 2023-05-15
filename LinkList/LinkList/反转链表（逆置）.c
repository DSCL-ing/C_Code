#define _CRT_SECURE_NO_WARNINGS 1


//https://leetcode-cn.com/problems/reverse-linked-list/description/

//206. ��ת����
//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
//�����ͷ�ڵ㲻���ڱ�����


//struct ListNode {
//	int val;
//	struct ListNode *next;
//};

//1���ļ�ͷ�����ö��ָ��������ƽ��м�ͷ��ת
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	//��ʼ����
	struct ListNode* n1 = NULL;    
	struct ListNode* n2 = head; 
	struct ListNode* n3 = head->next;
	while (n2)  //ѭ�����һ��Ҫ��ͨ������n3�����ʱ����ǰ������ֹNULL�����ã�
	{                                          //�����һ����ת���Խ���
		//�����߼�:��ת
		n2->next = n1;

		//����������
		n1 = n2;   
		n2 = n3;
		if (n3) //ָ��ָ̫Զ�ˣ������һ�����У�ͬʱʹn3������
		{
			n3 = n3->next;
		}
	}
	return n1;//n1Ϊ��ת���ͷ�ڵ㡣

}


//������ͷ�嵽��ͷָ�롣
struct ListNode* reverseList(struct ListNode* head){
	//��ʼ����
	struct ListNode* newnode = NULL; //����������
	struct ListNode *cur = head;     //curָ��ԭ�����ͷ�ڵ�
	while (cur)  //������ͼ�����һ����curΪ�ոպ�
	{
		//ͷ��
		//�����߼�
		//����ԭ������һ���ڵ�ĵ�ַ
		struct ListNode *next = cur->next;   
		//cur��nextָ��ͷ�ڵ㣬Ȼ���½ڵ�cur����newnode,ʹnewnodeָ���½ڵ�
		cur->next = newnode;     
		newnode = cur;        

		//����������
		cur = next;
	}
	return newnode;
}