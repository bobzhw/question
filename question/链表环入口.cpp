#include<iostream>


using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle01(ListNode *head) {
		if (head == nullptr)
			return nullptr;
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				break;
		}
		//有环时
		if (fast == slow)
		{
			//计算环中节点个数
			int count = 1;
			fast = slow->next;
			while (slow != fast)
			{
				count++;
				fast = fast->next;
			}
			ListNode* tmp = head;
			for (int i = count; i > 0; i--)
			{
				tmp = tmp->next;
			}
			while (head != tmp)
			{
				head = head->next;
				tmp = tmp->next;
			}
			return head;

		}
		return nullptr;

	}
};