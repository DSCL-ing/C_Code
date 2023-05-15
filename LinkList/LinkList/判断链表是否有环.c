#define _CRT_SECURE_NO_WARNINGS 1

//快指针一次走的步数 - 慢指针一次走的步数 = 相对速度
//v = 1 ,第一此追时相差N，此后N-1,N-2···2,1,0 ，最终一定会追上。
//v = 2，第一次追时相差N为奇时，则下次追的距离为C-1是奇，下下次又是C-1，无限循环，永远无法相遇
//v = 3 ,第一次追时相差N，则N-3，N-6,N -9,··· ，0 ，-1（C-1），-2（C-2） 递归下去

//总结：每一次追时差距N为v的倍速即可追上。N = kv

//应用：v = 1 能一次找到交点。


//？怎样判断是否有环:如果快指针走到头就不带环，等于慢指针就带环-----------------------原理

//has 美 [həz]   有;have 的第三人称单数现在时形式
//cycle  美[ˈsaɪkl]  周期; 循环; 自行车; 摩托车

bool hasCycle(struct ListNode *head) {
	//1·快慢指针
	struct ListNode* fast;
	struct ListNode* slow;
	fast = slow = head;
	while (fast && fast->next)  //fast为NULL时结束，fast==slow 时返回，所以用NULL为循环条件
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}