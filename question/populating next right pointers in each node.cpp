#include<iostream>
#include<queue>
using namespace std;
// Definition for binary tree with next pointer.
 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
	void connect(TreeLinkNode *root) {
		queue<TreeLinkNode*> dq;
		if (root == nullptr)
			return;
		dq.push(root);
		while (!dq.empty())
		{
			int size = dq.size();
			TreeLinkNode* pre;
			for (int i = 0; i < size; i++)
			{
				TreeLinkNode* tmp = dq.front();
				dq.pop();
				if (i != 0)
				{
					pre->next = tmp;
				}
				pre = tmp;
				if (tmp->left != nullptr)
					dq.push(tmp->left);
				if (tmp->right != nullptr)
					dq.push(tmp->right);
			}
		}
	}
};