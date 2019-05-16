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
 //思路：递归的思想，构建以i为根节点的树，其左子树必为1到i-1,右子树必为i+1到n。
 //可以递归的求解左子树与右子树，到最后当left > right 跳出递归。
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