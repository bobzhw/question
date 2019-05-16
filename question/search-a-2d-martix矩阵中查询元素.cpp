#include<iostream>

#include<vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.empty())
			return false;
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int i = 0; i < rows; i++)
		{
			if (target >= matrix[i][0] && target <= matrix[i][cols-1])
				return binarySearch(matrix[i], 0, cols-1, target);
		}
		return false;
	}
private:
	bool binarySearch(vector<int> v,int left,int right, int target)
	{
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (v[mid] == target)
				return true;
			if (v[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;

		}
		return false;
	}
};