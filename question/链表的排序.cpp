#include<iostream>
#include<memory>
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* p = head, *q = head->next;
		while (q != nullptr && q->next != nullptr)
		{
			p = p->next;
			q = q->next->next;
		}
		ListNode* left = sortList(p->next);
		p->next = nullptr;
		ListNode* right = sortList(head);
		ListNode* res = merge(left, right);
		return res;
	}
private:
	ListNode* merge(ListNode* left, ListNode* right)
	{
		ListNode tmp(0);
		ListNode* p = &tmp;
		while (left != nullptr && right != nullptr)
		{

			if (left->val < right->val)
			{
				p->next = left;
				left = left->next;
			}
			else {
				p->next = right;
				right = right->next;
			}
			p = p->next;
		}
		if (left != nullptr)
		{
			p->next = left;
		}
		if (right != nullptr)
		{
			p->next = right;
		}
		p = &tmp;
		return p->next;
	}
};