#include<iostream>
#include<vector>
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
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<int> v;
		vector <vector<int>> vv;
		pathSumAux(root, sum, v, vv);
		return vv;

	}
private:
	void pathSumAux(TreeNode* root, int sum, vector<int> v, vector<vector<int>>& vv)
	{
		if (root == nullptr)
			return;
		v.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr && sum - root->val == 0)
			vv.push_back(v);
		pathSumAux(root->left, sum - root->val, v, vv);
		pathSumAux(root->right, sum - root->val, v, vv);
	}
};
