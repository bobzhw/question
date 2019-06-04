#include<vector>
#include<iostream>
using namespace std;

/*
	You are given an n x n 2D matrix representing an image.
	Rotate the image by 90 degrees (clockwise).
*/
class Solution {
public:
	//解法1：空间复杂度为O(N^2)
	void rotate1(vector<vector<int> > &matrix) {
		if (matrix.empty())
			return;
		int rows = matrix.size();
		int cols = matrix[0].size();
		auto tmpmatrix = matrix;
		for (int i = 0; i <rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[j][cols - i - 1] = tmpmatrix[i][j];
			}
		}
	}
	//解法2：空间复杂度常数,先以y=x翻折，再以x轴翻折
	void rotate2(vector<vector<int> > &matrix) {
		if (matrix.empty())
			return;
		int rows = matrix.size();
		int cols = matrix[0].size();
		if (rows != cols)
			return;
		for (int i = 0; i <rows; i++)
		{
			for (int j = 0; j < cols-i; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[cols-1-j][rows-1-i];
				matrix[cols-1-j][rows-1-i] = tmp;
			}
		}
		for (int i = 0; i < rows / 2; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[rows - 1 - i][j];
				matrix[rows - 1 - i][j] = tmp;
			}
		}
	}
};
