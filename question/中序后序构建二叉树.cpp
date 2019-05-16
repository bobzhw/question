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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTreeAux(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
	TreeNode* buildTreeAux(vector<int>& inorder, int Instart, int Inend, vector<int>& postorder, int Poststart,int Postend)
	{
		if (Instart > Inend)
			return nullptr;
		TreeNode* node = new TreeNode(postorder[Postend]);
		int middle = 0;
		for (middle = Instart; middle < Inend; middle++)
		{
			if (inorder[middle] == node->val)
				break;
		}
		int leftLen = middle - Instart;
		node->left = buildTreeAux(inorder, Instart, middle - 1, postorder, Poststart, Poststart + leftLen - 1);
		node->right = buildTreeAux(inorder, middle + 1, Inend, postorder, Poststart + leftLen, Postend - 1);
		return node;
	}
};

