#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {	
		if (grid.empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> vv(m, vector<int>(n, 0));
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (i == 0 && j != 0)
				{
					vv[i][j] = vv[i][j - 1] + grid[i][j];
				}
				else if (j == 0 && i != 0)
				{
					vv[i][j] = vv[i - 1][j] + grid[i][j];
				}
				else if (i != 0 && j != 0)
				{
					vv[i][j] = min(vv[i - 1][j], vv[i][j - 1]) + grid[i][j];
				}
				else
					vv[i][j] = grid[i][j];

			}
		}
		return vv[m - 1][n - 1];
	}
private:
	inline int min(int lhs, int rhs)
	{
		return lhs <= rhs ? lhs : rhs;
	}
};