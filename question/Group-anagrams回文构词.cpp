#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		if (strs.empty())
			return result;
		unordered_map<string, vector<string>> ans;
		for (auto& s : strs)
		{
			string key = s;
			sort(key.begin(),key.end());
			if (ans.find(key) == ans.end())
			{
				ans[key] = vector<string>();
			}
			ans[key].emplace_back(s);
		}
		for (auto& it : ans)
		{
			result.emplace_back(it.second);
		}
		return result;
	}
	
};