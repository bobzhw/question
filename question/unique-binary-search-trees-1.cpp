#include<vector>
#include<iostream>

using namespace std;

//动态规划思想：维护一个数组来存储n = i时候的BST的个数。这样的话给定一个数n，可以分为多种情况，
//若根节点是n,那个它就没有右子树，左子树最有n-1个节点，若根节点为i，那么左子树有i-1个节点，右子树有i+1个节点;
//建立递归表达式
class Solution {
public:
	int numTrees(int n) {
		if (n == 0)
			return 0;
		vector<int> vec{ 1,2 };
		for (int i = 3; i <= n ;i++)
		{
			int count = 0;
			for (int j = 0; j < i; j++)
			{
				if (j == 0 || j == i-1)
				{
					count += vec[i - 2];
					continue;
				}
				count += vec[j-1] * vec[i - j - 2];
			}
			vec.push_back(count);	
		}
		return vec[n - 1];
	}
};