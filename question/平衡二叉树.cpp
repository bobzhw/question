#include<iostream>
#include<queue>

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
	bool isBalanced(TreeNode *root) {
		if (root == nullptr)
			return true;
		if (abs(heightTreenode(root->left) - heightTreenode(root->right)) <= 1)
			return isBalanced(root->left) && isBalanced(root->right);
		return false;

	}
private:
	int heightTreenode(TreeNode* node)
	{
		int count = 0;
		if (node == nullptr)
			return count;
		queue<TreeNode*> q;
		q.push(node);
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				node = q.front();
				q.pop();
				if (node->left != nullptr)
					q.push(node->left);
				if (node->right != nullptr)
					q.push(node->right);
			}
			++count;
		}
		return count;
	}
};