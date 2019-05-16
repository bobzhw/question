#include<iostream>
 //Definition for singly-linked list.
 struct ListNode {
     int val;
	 ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};
 class Solution {
 public:
	 ListNode *deleteDuplicates(ListNode *head) {
		 if (head == nullptr)
			 return head;
		 ListNode L(0);
		 L.next = head;
		 ListNode* tmp = head;
		 ListNode* pre = &L;
		 while (tmp != nullptr)
		 {
			 if (tmp != head && tmp->val == pre->val)
			 {
				 pre->next = tmp->next;
			 }
			 else
			 {
				 pre = tmp;
			 }
			 tmp = tmp->next;
		 }
		 return head;
	 }
 };