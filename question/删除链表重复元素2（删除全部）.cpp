
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr)
			return nullptr;
		ListNode* L = new ListNode(0);
		L->next = head;
		ListNode *pre = head;
		ListNode* p = L;
		ListNode* tmp = head->next;
		bool flag = false;
		while (tmp != nullptr)
		{
			if (tmp->val == pre->val)
			{
				pre->next = tmp->next;
				tmp = tmp->next;
				flag = true;
			}
			else
			{
				
				if (flag)
				{
					p->next = tmp;
					flag = false;
				}	
				else
				{
					p = pre;
					
				}
				pre = tmp;
				tmp = tmp->next;
			}
		}
		if (flag)
			p->next = tmp;
		head = L->next;
		delete(L);
		return head;
	}
};