#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	bool isFirst;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), isFirst(false) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> result;
		if (root == nullptr)
			return result;
		stack<TreeNode*> st;
		TreeNode* tmp = root;
		TreeNode* pre = nullptr;
		st.push(tmp);
		while (!st.empty())
		{
			tmp = st.top();
			if ((tmp->left == nullptr && tmp->right == nullptr) ||
				(pre != nullptr && (pre == tmp->left || pre == tmp->right)))
			{
				result.push_back(tmp->val);
				st.pop();
				pre = tmp;
			}
			else
			{
				if (tmp->right != nullptr)
					st.push(tmp->right);
				if (tmp->left != nullptr)
					st.push(tmp->left);
			}
		}
		return result;
	}
	vector<int> postorderTraversal02(TreeNode *root)
	{
		vector<int> result;
		if (root == nullptr)
			return result;
		stack<TreeNode*> st;
		TreeNode* tmp = root;
		while (!st.empty() || tmp != nullptr)
		{
			while (tmp != nullptr)
			{
				tmp->isFirst = true;
				st.push(tmp);
				tmp = tmp->left;
			}
			if (!st.empty())
			{
				tmp = st.top();
				st.pop();
				if (tmp->isFirst == true)
				{
					tmp->isFirst = false;
					st.push(tmp);
					tmp = tmp->right;
				}
				else
				{
					result.push_back(tmp->val);
					tmp = nullptr;
				}
			}

		}
		return result;
	}
};