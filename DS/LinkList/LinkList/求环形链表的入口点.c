#define _CRT_SECURE_NO_WARNINGS 1


//https://leetcode-cn.com/problems/linked-list-cycle-ii/

//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

//��һ����֤��ǰ����ۣ�
	//���ۣ���head���뻷�㳤��Ϊl���������㳤��Ϊl+x �� ��������㿪ʼһֱ�ߵľ�����ڴ�head��ʼ�ߵ��뻷��ľ��룬�������ǻ����뻷��������
	//֤����
	//2(l+x) = l+nC+x;
	//���� l = nC - x;  
	//l = (n - 1)C + C - x; 
	//��l�ľ���Ϊn-1�����ĺͼ��������㵽�뻷��ĳ��� �� ��֤
//1����ϰʾ��
struct ListNode *detectCycle(struct ListNode *head) {
	//1����ȷ�ϵ�
	struct ListNode* fast;
	struct ListNode* slow;
	slow = fast = head;
	while (fast && fast->next)  //�һ�ȷ����
	{
	fast = fast->next->next;
	slow = slow->next;
	if (fast == slow)  //�����ȱȽϣ���һ���ͻ�pass
	{
		printf("%d,%d\n", slow->val, fast->val);
		break;
	}
	}
	//����д��ѭ���⣬ѭ����ִ�в���
	if (fast == NULL || fast->next == NULL)  //���ǻ��򷵻ؿ�
	{
		return NULL;
	}
	//2����ʽ�����뻷��
	struct ListNode * tail1 = head;
	struct ListNode * tail2 = fast;
	while (tail1 != tail2)
	{
		tail1 = tail1->next;
		tail2 = tail2->next;
	}
	return tail1;
}

//2���Ż�ʾ��
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* fast;
	struct ListNode* slow;
	slow = fast = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)  //�ҵ��������ˣ�ִ����һ��
		{
			struct ListNode * tail = head; 
			while (tail != fast)  //��ͬ�����뻷��
			{
				tail = tail->next;
				fast = fast->next;
			}
			return tail; //�����뻷��
		}
	}
	return NULL; //fast Ϊ�գ�˵�����޻�����
}



//�������󽻵㷨�����(���ܵ��ýӿڣ��ӿڽ����ò���������)
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* fast ;
	struct ListNode* slow;
	slow = fast = head;
	//-------------------------------------------����ʾ��
	//while (fast != slow)  //���־����-------------------------<
	//{
	//	if (fast == NULL || fast->next == NULL)
	//	{
	//		printf("������\n");
	//		return NULL;
	//	}
	//	fast = fast->next->next;
	//	slow = slow->next;
	//}

	while (fast && fast->next)  //�һ�ȷ����
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)  //�����ȱȽϣ���һ���ͻ�pass
		{
			printf("%d,%d\n", slow->val, fast->val);
			break;
		}
	}
	//����д��ѭ���⣬ѭ����ִ�в���
	if (fast == NULL || fast->next == NULL)  //���ǻ��򷵻ؿ�
	{
		return NULL;
	}

	
//--------------��������Ե������л�����ڵ�Ľӿں�����-------------------
//--------------��������Ե������л�����ڵ�Ľӿں�����-------------------
	-- -

	//�ѻ�ȷ���㵱���յ㣬��ȷ�������һ���ڵ�Ϊͷ
	struct ListNode* tail1 = head;
	struct ListNode* tail2 = fast->next;  

	//lenΪ1�ã���Ϊlen2���fast->next���---->��
	int len1 = 1, len2 = 1;
	//����1����
	while (tail1->next != fast->next)
	{
		len1++;
		tail1 = tail1->next;
	}

	//����2����
	while (tail2->next != fast->next)
	{
		len2++;
		tail2 = tail2->next;
	}

	//�ҽ��㣨��ڵ㣩
	int gap = abs(len1 - len2);
	//printf("len1 = %d , len2 = %d , gap = %d \n", len1, len2, gap);  leetcode������
	struct ListNode* longList = head;
	struct ListNode* shortList = fast->next;
	if (len1 < len2)
	{
		longList = fast->next;
		shortList = head;
	}
	
	while (gap--)
	{
		longList = longList->next;
	}

	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}

	return longList;
}


