#include<iostream>
using namespace std;
// Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	/*
	* ˼·��1�����ȿ��������½ڵ������������ڵ����
	*		 2������randomָ��
	*		 3��������������
	*/
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == nullptr)
			return nullptr;
		RandomListNode* tmp, *copy, *ptr;
		for (tmp = head; tmp != nullptr;)
		{
			copy = new RandomListNode(tmp->label);
			ptr = tmp->next;
			tmp->next = copy;
			copy->next = ptr;
			tmp = ptr;
		}
		for (tmp = head; tmp != nullptr;)
		{
			tmp->next->random = (tmp->random) ? (tmp->random->next) : nullptr;
			tmp = tmp->next->next;
		}
		tmp = head;
		ptr = head->next;
		copy = ptr;
		while (ptr->next != nullptr)
		{
			ptr = tmp->next;
			tmp->next = ptr->next;
			tmp = ptr;
		}
		return copy;
	}
};