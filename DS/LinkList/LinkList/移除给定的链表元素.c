#define _CRT_SECURE_NO_WARNINGS 1

//203. �Ƴ�����Ԫ��
//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ����������������
//Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��


//1��ͷɾ
//2���м�ɾ


struct ListNode* removeElements(struct ListNode* head, int val){
	struct  ListNode *cur, *prev;
	cur = head; prev = head;
	while (cur)
	{
		if (cur->val == val)
		{
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;

			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}