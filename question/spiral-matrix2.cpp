#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		
		if (n <= 0)
			return{};
		vector<vector<int>> res(n, vector<int>(n));
		int value = 0;
		int rowbegin = 0, rowend = n-1;
		int colbegin = 0, colend = n-1;
		while (rowbegin <= rowend && colbegin <= colend)
		{
			for (int i = colbegin; i <= colend; i++)
			{
				res[rowbegin][i] = (++value);
			}
			rowbegin++;
			for (int i = rowbegin; i <= rowend; i++)
			{
				res[i][colend] = (++value);
			}
			colend--;
			if (rowbegin <= rowend)
			{
				for (int i = colend; i >= colbegin; i--)
				{
					res[rowend][i] = (++value);
				}	
			}
			rowend--;
			if (colbegin <= colend)
			{
				for (int i = rowend; i >= rowbegin; i--)
				{
					res[i][colbegin] = (++value);
				}
				
			}
			colbegin++;
		}
		return res;
	}
};