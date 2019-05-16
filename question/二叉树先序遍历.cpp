#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> result;
		if (root == nullptr)
			return result;
		stack<TreeNode*> st;
		TreeNode* tmp = root;
		while (tmp != nullptr || !st.empty())
		{
			while (tmp != nullptr)
			{
				result.push_back(tmp->val);
				st.push(tmp);
				tmp = tmp->left;
			}
			if (!st.empty())
			{
				tmp = st.top();
				st.pop();
				tmp = tmp->right;
			}
		}
		return result;
			
	}
};
