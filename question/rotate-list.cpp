#include<iostream>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == nullptr || k == 0)
			return head;
		int len = 1;
		ListNode *p = head;
		while (p->next) {
			//遍历一遍，求出链表长度
			len++;
			p = p->next;
		}
		k = len - k%len;

		p->next = head;//首尾相连
		for (int step = 0; step<k; step++) {
			p = p->next;//接着往后跑
		}
		head = p->next;//新的首节点
		p->next = nullptr;//断开环
		return head;
	}
};