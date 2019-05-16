#include<iostream>
#include<queue>

using namespace std;
// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//思路很简单，但是我没想到，只要递归的对当前节点的两个子节点进行比较就OK
//当前节点左子树与另一节点的右子树进行对比
class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		return check(root, root);

	}
	bool check(TreeNode* lhs, TreeNode* rhs)
	{
		if (lhs == nullptr && rhs == nullptr)
			return true;
		if (lhs == nullptr || rhs == nullptr)
			return false;
		return lhs->val == rhs->val && check(lhs->left, rhs->right) && check(lhs->right, rhs->left);
	}
};