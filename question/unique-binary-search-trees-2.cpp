#include<vector>
#include<iostream>
using namespace std;
// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //˼·���ݹ��˼�룬������iΪ���ڵ����������������Ϊ1��i-1,��������Ϊi+1��n��
 //���Եݹ��������������������������left > right �����ݹ顣
class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		return createTrees(1, n);
	}

	vector<TreeNode*> createTrees(int left, int right)
	{
		vector<TreeNode*> res;
		if (left > right)
		{
			res.push_back(nullptr);
			return res;
		}
		for (int i = left; i <= right; i++)
		{
			vector<TreeNode*> left_res = createTrees(left, i - 1);
			vector<TreeNode*> right_res = createTrees(i + 1, right);

			int lsize = left_res.size();
			int rsize = right_res.size();
			for (int j = 0; j < lsize; j++) 
			{
				for (int k = 0; k < rsize; k++)
				{
					TreeNode* root = new TreeNode(i);
					root->left = left_res[j];
					root->right = right_res[k];
					res.push_back(root);
				}
			}
		}
		return res;
	}
};