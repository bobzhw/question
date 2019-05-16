#include<iostream>
#include<vector>
using namespace std;
class Solution {
	//**思路：做出来很开心
public:
	int candy(vector<int> &ratings) {
		if (ratings.empty())
			return 0;
		vector<int> result{ 1 };
		for (int i = 1; i < ratings.size(); i++)
		{
			if (ratings[i] > ratings[i - 1])
				result.push_back(result[i - 1] + 1);
			else
				result.push_back(1);
		}
		for (int i = ratings.size() - 1; i > 0; i--)
		{
			if (ratings[i - 1] > ratings[i] && result[i - 1] <= result[i])
				result[i - 1] = result[i] + 1;

		}
		int count = 0;
		for (int i = 0; i < result.size(); i++)
		{
			count += result[i];
		}
		return count;
	}
};