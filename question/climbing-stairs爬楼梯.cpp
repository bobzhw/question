#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		vector<int> v{ 1,1 };
		if (n == 1)
			return 1;
		for (int i = 2; i <= n; i++)
		{
			v.push_back(v[i - 2] + v[i - 1]);
		}
		return v[n];
	}
};