#include<iostream>
#include<cmath>\
#include<numeric_limits>
using namespace std;
//Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	int maxPathSum(TreeNode *root) {
		int maxvalue = INT_MIN;
		maxPath(root, maxvalue);
		return maxvalue;
	}
private:
	int maxPath(TreeNode* node, int& maxvaule)
	{
		if (node == nullptr)
			return 0;
		int left = max(0,maxPath(node->left, maxvaule));
		int right = max(0,maxPath(node->right, maxvaule));
		maxvaule = max(maxvaule, left + right + node->val);
		return max(0,max(left, right) + node->val);
	}
	int max(int lhs, int rhs)
	{
		return (lhs > rhs) ? lhs : rhs;
	}
};
