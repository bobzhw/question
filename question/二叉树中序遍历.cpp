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
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root == nullptr)
			return result;
		TreeNode* tmp = root;
		while (!st.empty() || tmp != nullptr)
		{
			while (tmp != nullptr)
			{
				st.push(tmp);
				tmp = tmp->left;
			}
			if (!st.empty())
			{
				tmp = st.top();
				result.push_back(tmp->val);
				st.pop();
				tmp = tmp->right;
			}
			
		}
		return result;
	}
};
