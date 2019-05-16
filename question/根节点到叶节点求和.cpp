#include<iostream>
#include<deque>
#include<vector>
#include<string>
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
	int sumNumbers(TreeNode *root) {
		int sum = 0;
		if (root == nullptr)
			return sum;
		return preorderSumNumbers(root, sum);
	}
private:
	int preorderSumNumbers(TreeNode* node, int sum)
	{
		if (node == nullptr)
			return 0;
		sum = sum * 10 + node->val;
		if (node->left == nullptr && node->right == nullptr)
			return sum;
		return preorderSumNumbers(node->left, sum) + preorderSumNumbers(node->right, sum);
	}
};