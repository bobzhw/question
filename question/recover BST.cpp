#include<iostream>

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //������������µ���������������С�������У�����ֻҪ�ҵ�������������еĴ���������ڵ�
 //���ɣ�ȥ���������ڵ�������������������˳���С����

 class Solution {
 public:
	 void recoverTree(TreeNode *root) {
		 mistake1 = mistake2 = pre = nullptr;
		 inOrderFindMistakes(root);
		 swap(mistake1, mistake2);
	 }
 private:
	 TreeNode* mistake1;
	 TreeNode* mistake2;
	 TreeNode* pre;
	 void inOrderFindMistakes(TreeNode* root)
	 {
		 if (root == nullptr)
			 return;
		 inOrderFindMistakes(root->left);
		 if (pre != nullptr && pre->val > root->val)
		 {
			 if (mistake1 == nullptr)
			 {
				 mistake1 = pre;
				 mistake2 = root;
			 }
			 else
				 mistake2 = root;
		 }
		 pre = root;
		 inOrderFindMistakes(root->right);
	 }
	 static void swap(TreeNode* node1, TreeNode* node2)
	 {
		 int tmp = node1->val;
		 node1->val = node2->val;
		 node2->val = tmp;
	 }
 };
  