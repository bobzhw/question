#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> vv(m, vector<int>(n, 1));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (obstacleGrid[i][j] == 1)
					vv[i][j] = 0;
				else if (i != 0 && j != 0)
				{
					vv[i][j] = vv[i - 1][j] + vv[i][j - 1];
				}
				else if (i == 0 && j != 0)
				{
					vv[i][j] = vv[i][j - 1];
				}
				else if (i != 0 && j == 0)
				{
					vv[i][j] = vv[i - 1][j];
				}
			}
		}
		return vv[m - 1][n - 1];
	}
};