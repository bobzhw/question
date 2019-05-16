#include<iostream>
#include<memory>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode proot(0);
		ListNode* node = &proot;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val <= l2->val)
			{
				node->next = l1;	
				l1 = l1->next;
			}
			else
			{
				node->next = l2;
				l2 = l2->next;
			}
			node = node->next;
		}
		if (l1 != nullptr)
			node->next = l1;
		if (l2 != nullptr)
			node->next = l2;
		return proot.next;
	}
	
};
