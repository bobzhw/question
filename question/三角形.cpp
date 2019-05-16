/*
	Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//深度优先遍历
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty())
			return 0;
		return minfunc(triangle, 0, 0);
		
	}

private:
	int minfunc(vector<vector<int>>& triangle, int x, int y)
	{
		if (x > triangle.size() - 1 || y > triangle[x].size())
			return 0;
		return triangle[x][y] + min(minfunc(triangle, x + 1, y), minfunc(triangle, x + 1, y + 1));
	}
	int min(int lhs, int rhs)
	{
		return lhs < rhs ? lhs : rhs;
	}
};
