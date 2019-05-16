#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //�ڽ��в�α�����ʱ���Ƚ�����һ��������ٰѵ�ǰ�����vv��
class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int>> vv;
		if (root == nullptr)
			return vv;
		queue<TreeNode*> q;
		q.push(root);
		levelOrderBottomAux(vv, q);
		return vv;
	}
private:
	void levelOrderBottomAux(vector<vector<int>>& vv, queue<TreeNode*>& q)
	{
		if (q.empty())
			return;
		int size = q.size();
		vector<int> v;
		for (int i = 0; i < size; i++)
		{
			TreeNode* root = q.front();
			q.pop();
			v.push_back(root->val);
			if (root->left != nullptr)
				q.push(root->left);
			if (root->right != nullptr)
				q.push(root->right);
		}
		levelOrderBottomAux(vv, q);
		vv.push_back(v);
	}
	
};