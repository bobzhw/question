#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.empty())
			return 0;
		vector<int> res{ 0 };
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] <= prices[i-1])
			{
				res.push_back(res[i-1]);
			}
			else
			{
				res.push_back(res[i-1] + prices[i] - prices[i-1]);
			}
			
		}
		return res[res.size() - 1];

	}
};