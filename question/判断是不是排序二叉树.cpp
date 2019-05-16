#include<iostream>
// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
 public:
	 TreeNode* pre;
	 bool isValid;

	 bool isValidBST(TreeNode* root)
	 {
		 isValid = true;
		 pre = nullptr;
		 InorderJudge(root);
		 return isValid;
	 }
	 void InorderJudge(TreeNode* root)
	 {
		 if (root == nullptr)
			 return;
		 InorderJudge(root->left);
		 if (pre != nullptr && pre->val >= root->val)
			 isValid = false;
		 pre = root;
		 InorderJudge(root->right);
	 }
 };