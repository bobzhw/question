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
//˼·�ܼ򵥣�������û�뵽��ֻҪ�ݹ�ĶԵ�ǰ�ڵ�������ӽڵ���бȽϾ�OK
//��ǰ�ڵ�����������һ�ڵ�����������жԱ�
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