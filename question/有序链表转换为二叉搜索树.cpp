#include<iostream>

using namespace std;
//要求转换结束后的二叉树高度也是平衡的

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


//Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		return toBST(head,nullptr);
		
	}
private:
	TreeNode* toBST(ListNode* head, ListNode* tail)
	{
		if (head == tail)
			return nullptr;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != tail && fast->next != tail)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode* root = new TreeNode(slow->val);
		root->left = toBST(head, slow);
		root->right = toBST(slow->next, tail);
		return root;
	}
};