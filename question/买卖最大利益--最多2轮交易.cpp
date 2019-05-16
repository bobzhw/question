#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
		for (int i = 0; i < prices.size(); i++) {
			buy1 = max(buy1, 0 -prices[i]);
			sell1 = max(sell1, buy1 + prices[i]);
			buy2 = max(buy2, sell1 - prices[i]);
			sell2 = max(sell2, buy2 + prices[i]);
		}
		return sell2;
	}
private:
	int max(int lhs, int rhs)
	{
		return (lhs > rhs) ? lhs : rhs;
	}
};