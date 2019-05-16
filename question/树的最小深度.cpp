#include<queue>
using namespace std;
struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
};

class Solution {
public:
	int run(TreeNode *root) {
		queue<TreeNode*> q;
		if (root == nullptr)
			return 0;
		q.push(root);
		int height = 0;
		while (!q.empty())
		{
			int len = q.size();
			height++;
			for (int i = 0; i < len; i++)
			{
				TreeNode* temp = q.front();
				q.pop();
				if (temp->left == nullptr && temp->right == nullptr)
				{
					return height;
				}
				if (temp->left != nullptr)
					q.push(temp->left);
				if (temp->right != nullptr)
					q.push(temp->right);
			}
		}
		return height;
	}
};