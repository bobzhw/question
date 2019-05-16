#include<iostream>
#include<string>
#include<deque>
#include<vector>
using namespace std;

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     bool isFirst;
     TreeNode(int x) : val(x), left(NULL),right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> result;
		if (root == nullptr)
			return result;
		deque<TreeNode*> dq;
		TreeNode* tmp = root;
		dq.push_back(tmp);
		while (!dq.empty())
		{
			tmp = dq.front();
			dq.pop_front();
			result.push_back(tmp->val);
			if (tmp->left)
				dq.push_back(tmp->left);
			if (tmp->right)
				dq.push_back(tmp->right);
		}
		return result;

	}
};
