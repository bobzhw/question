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
			//����һ�飬���������
			len++;
			p = p->next;
		}
		k = len - k%len;

		p->next = head;//��β����
		for (int step = 0; step<k; step++) {
			p = p->next;//����������
		}
		head = p->next;//�µ��׽ڵ�
		p->next = nullptr;//�Ͽ���
		return head;
	}
};