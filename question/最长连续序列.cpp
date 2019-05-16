#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		sort(num.begin(), num.end());
		int count = 1, max = 1;
		for (int i = 1; i < num.size(); i++)
		{
			if (num[i] == num[i - 1])
				continue;
			if (num.at(i) == num.at(i - 1) + 1)
			{
				count++;
				if (max < count)
					max = count;
			}
			else
				count = 1;
				
		}
		return max;
	}
};