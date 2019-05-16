#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> dp(rowIndex + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= rowIndex; i++)
			for (int j = i; j >= 1; j--)
				dp[j] += dp[j - 1];
		return dp;
	}
};