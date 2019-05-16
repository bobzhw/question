#include<iostream>
#include<vector>
#include<deque>
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> vv;
		if (root == nullptr)
			return vv;
		deque<TreeNode*> dq;
		dq.push_back(root);
		bool left2right = true;
		while (!dq.empty())
		{
			int size = dq.size();
			vector<int> v;
			for (int i = 0; i < size; i++)
			{		
				if (left2right)
				{
					root = dq.front();
					dq.pop_front();
					v.push_back(root->val);
					if (root->left != nullptr)
						dq.push_back(root->left);
					if (root->right != nullptr)
						dq.push_back(root->right);
				}
				else
				{
					root = dq.back();
					dq.pop_back();
					v.push_back(root->val);
					if (root->right != nullptr)
						dq.push_front(root->right);
					if (root->left != nullptr)
						dq.push_front(root->left);
				}
			}
			vv.push_back(v);
			left2right = (left2right) ? false : true;
		}
		return vv;
	}
};