#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0)
			return 0;
		vector<vector<int>> vv(m, vector<int>(n, 1));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != 0 && j != 0)
				{
					vv[i][j] = vv[i - 1][j] + vv[i][j - 1];
				}
			}
		}
		return vv[m - 1][n - 1];
	}
};