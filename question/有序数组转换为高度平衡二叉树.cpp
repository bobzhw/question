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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if (num.empty())
			return nullptr;
		return BST_aux(num, 0, num.size());
	}

private:
	TreeNode* BST_aux(vector<int>& num, int start, int end)
	{
		if (start >= end)
			return nullptr;
		int mid = (start + end) / 2;
		TreeNode* tmp = new TreeNode(num[mid]);
		tmp->left = BST_aux(num, start, mid);
		tmp->right = BST_aux(num, mid + 1, end);
		return tmp;
	}
};