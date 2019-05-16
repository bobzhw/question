#include<iostream>
#include<unordered_set>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (dict.empty() || s == "")
			return false;
		size_t size = s.size();
		vector<bool> vec(size + 1, false);
		vec[0] = true;
		for (size_t i = 1; i <= size; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (vec[j] && (count(dict.begin(), dict.end(), s.substr(j, i - j)) > 0))
				{

					vec[i] = true;
					break;
				}
			}
		}
		return vec[size];
	}
};
