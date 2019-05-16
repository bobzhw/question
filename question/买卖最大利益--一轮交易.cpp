#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.empty())
			return 0;
		int buy = INT_MIN, sell = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			buy = max(buy, 0 - prices[i]);
			sell = max(sell, buy + prices[i]);
		}
		return sell;
		
	}
private:
	int max(int lhs, int rhs)
	{
		return (lhs > rhs)?lhs:rhs;
	}
};