#include<iostream>
#include<queue>
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
	int maxDepth(TreeNode *root) {
		if (root == nullptr)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int depth = 0;
		while (!q.empty())
		{
			size_t size = q.size();
			for (size_t i = 0; i < size; i++)
			{
				root = q.front();
				q.pop();
				if (root->left != nullptr)
					q.push(root->left);
				if (root->right != nullptr)
					q.push(root->right);
			}
			++depth;
		}
		return depth;
	}
};