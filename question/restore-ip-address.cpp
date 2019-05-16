#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 思路：IP地址正确格式为4个数字，每个数字为0 - 255之间的数字，所以每一位都最多有三位，最少有1位
//从头开始判断分割字符串进行遍历，如果满足count为3即已经有了4个数字，并且这4个数字都是有效的，那么说这样的分割是正确的
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		if (s.length() < 4 || s.length() > 12)
			return res;
		dfs(s, "", res, 0);
		return res;
	}

private:
	bool isValid(string s) {
		if (s == "")
			return false;
		if (s[0] == '0')
			return s == "0";
		int num = stoi(s);
		return num <= 255 && num >0;
	}
	void dfs(string s, string tmp, vector<string>& res, int count)
	{
		if (count == 3 && isValid(s))
		{
			res.push_back(tmp + s);
		}
		for (int i = 0; i < 4 && i < s.length(); i++)
		{
			string substring = s.substr(0, i);
			if (isValid(substring)) 
			{
				dfs(s.substr(i), tmp + substring + ".", res, count + 1);
			}
		}
	}

};
