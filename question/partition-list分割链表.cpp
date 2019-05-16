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
	ListNode *partition(ListNode *head, int x) {
		if (head == nullptr)
			return head;
		ListNode* tmphead = new ListNode(x);
		ListNode* tmp = tmphead;
		ListNode* tmptail = tmphead;
		ListNode* res = tmphead;
		ListNode* q = tmphead;
		while (head != nullptr)
		{
			ListNode* p = head->next;
			if (head->val < x)
			{
				if (tmphead == tmp)
				{
					head->next = tmp;
					tmphead = head;
					q = head;
				}
				else
				{
					head->next = tmp;
					tmphead->next = head;
					tmphead = head;
				}
				res = head;
			}
			else
			{
				tmptail->next = head;
				tmptail = head;
			}
			head = p;
		}
		tmptail->next = nullptr; 
		if (tmphead == tmp)
		{
			res = tmphead->next;
			delete tmphead;
			return res;
		}
			
		else
		{
			tmphead = res->next;
			res->next = res->next->next;
			delete tmphead;
			return q;
		}
			
	}
};