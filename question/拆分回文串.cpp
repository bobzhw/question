#include<vector>
#include<string>
#include<iostream>
using namespace std;
//"aab"->"a","a","b" ---> "aa","b"
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> cur;
		dfs(s, cur, result);
		return result;
	}
private:
	bool IsPalindrome(string& s)
	{
		return s == string(s.rbegin(), s.rend());
	}
	void dfs(string& s, vector<string>& cur, vector<vector<string>>& res)
	{
		if (s == "")
		{
			res.push_back(cur);
			return;
		}
		for (int i = 1; i <= s.length(); i++)
		{
			string sub = s.substr(0, i);
			if (IsPalindrome(sub))
			{
				cur.push_back(sub);
				dfs(s.substr(i, s.length() - i), cur, res);
				cur.pop_back();
			}
		}
	}
};

