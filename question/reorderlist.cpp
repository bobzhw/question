#include<iostream>
#include<vector>
//L0->L1->L2->L3->...->Ln-1->Ln
//L0->Ln->L1->Ln-1->L2->Ln-2->...
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	void reorderList(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return;
		
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* before = slow->next;
		//逆序后半部分
		slow->next = nullptr;
		ListNode* tmp = new ListNode(0);
		ListNode* pHead = nullptr;
		while (before != nullptr)
		{
			ListNode* ptr = before->next;
			tmp->next = before;
			before->next = pHead;
			pHead = before;
			before = ptr;
		}
		//tmp作为合并后链表的头节点
		pHead = tmp->next;
		tmp->next = nullptr;
		ListNode* current = tmp;
		//合并两个链表head,pHead;
		while (head != nullptr && pHead != nullptr)
		{
			current->next = head;
			head = head->next;
			current->next->next = pHead;
			pHead = pHead->next;
			current = current->next->next;
		}
		head = tmp->next;
		if (tmp != nullptr)
		{
			delete(tmp);
			tmp = nullptr;
		}
	}
};