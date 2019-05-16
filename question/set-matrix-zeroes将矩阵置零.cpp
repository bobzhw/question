#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == 0)
				{
					for (int k = 0; k < rows; k++)
						if (matrix[k][j] != 0)
							matrix[k][j] = -1;
					for (int k = 0; k < cols; k++)
						if (matrix[i][k] != 0)
							matrix[i][k] = -1;
				}
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == -1)
					matrix[i][j] = 0;
			}
		}
	}
};