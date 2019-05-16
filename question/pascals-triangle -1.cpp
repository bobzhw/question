#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int>> result;
		if (numRows < 1)
			return result;
		for (int i = 0; i < numRows; i++)
		{
			vector<int> vec;
			for (int j = 0; j < i + 1; j++)
			{
				if (j == 0 || j == i)
					vec.push_back(1);
				else
				{
					vec.push_back(result[i - 1][j - 1] + result[i - 1][j]);
				}
			}
			result.push_back(vec);
		}
		return result;

	}
};
