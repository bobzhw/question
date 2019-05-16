#include<iostream>
#include<stack>

using namespace std;
// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		if (root == nullptr)
			return false;
		if (root->left == nullptr && root->right == nullptr && sum - root->val == 0)
		{
			return true;
		}
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};
