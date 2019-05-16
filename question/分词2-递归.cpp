#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> result;
		if (dict.find(s) != dict.end())
			result.push_back(s);
		for (int i = 1; i<s.size(); i++)
		{
			string w = s.substr(i);
			if (dict.find(w) == dict.end())
				continue;
			string str = s.substr(0, i);
			vector<string> left = wordBreak(str, dict);
			Add(left, w);
			result.insert(result.begin(), left.begin(), left.end());
		}        
		return result;
	}
	void Add(vector<string> &str, string w)
	{
		for (vector<string>::iterator it = str.begin(); it != str.end(); it++)
			*it += " " + w;
	}
};


