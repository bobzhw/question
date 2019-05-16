#include<vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> res;
		if (matrix.empty())
			return res;
		int rowbegin = 0, rowend = matrix.size() - 1;
		int colbegin = 0, colend = matrix[0].size() - 1;
		while (rowbegin <= rowend && colbegin <= colend)
		{
			//左--->右
			for (int i = colbegin; i <= colend; i++)
			{
				res.emplace_back(matrix[rowbegin][i]);
			}
			rowbegin++;
			//上--->下
			for (int i = rowbegin; i <= rowend; i++)
			{
				res.emplace_back(matrix[i][colend]);
			}
			colend--;
			//右--->左
			if (rowbegin <= rowend)
			{
				for (int i = colend; i >= colbegin; i--)
				{
					res.emplace_back(matrix[rowend][i]);
				}
				
			}
			rowend--;
			//下--->上
			if (colbegin <= colend)
			{
				for (int i = rowend; i >= rowbegin; i--)
				{
					res.emplace_back(matrix[i][colbegin]);
				}
			}
			colbegin++;
		}
		return res;
	}
};