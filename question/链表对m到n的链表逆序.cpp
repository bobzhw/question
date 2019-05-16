#include<iostream>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 //思路：先找到m位置节点以及m位置前一个节点，然后利用头插法进行插入，直到m-n的所
 //有节点都插入完毕即可
 class Solution {
 public:
	 ListNode *reverseBetween(ListNode *head, int m, int n) {
		 if (head == nullptr || m >= n)
			 return head;
		 ListNode node(0);
		 node.next = head;
		 ListNode* prestart = &node;
		 ListNode* start = head;

		 for (int i = 1; i < m; i++)
		 {
			 prestart = start;
			 start = start->next;
		 }
		 for (int i = 0; i < n - m; i++)
		 {
			 ListNode* tmp = start->next;
			 start->next = tmp->next;
			 tmp->next = prestart->next;
			 prestart->next = tmp;

		 }
		 return node.next;

	 }
 };