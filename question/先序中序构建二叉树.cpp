#include<iostream>
#include<vector>

using namespace std;


//Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
	{
		return buildTreeAux(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
private:
	TreeNode* buildTreeAux (vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend)
	{
		if (instart > inend)
			return nullptr;
		TreeNode* node = new TreeNode(preorder[prestart]);
		int middle = 0;
		for (middle = instart; middle <= inend; middle++)
		{
			if (inorder[middle] == node->val)
				break;
		}
		int leftLen = middle - instart -1;
		node->left = buildTreeAux(preorder,prestart+1,prestart+leftLen+1, inorder, instart, middle - 1);
		node->right = buildTreeAux(preorder, prestart+ leftLen + 2,preend, inorder, middle + 1, inend);
		return node;
	}
};