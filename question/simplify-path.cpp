#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string simplifyPath(string path)
	{
		vector<string> res;
		stringstream ss(path);
		string sub;
		while (getline(ss, sub, '/'))
		{
			if (sub == "." || sub == "")
				continue;
			else if (sub == ".." && res.size())
				res.pop_back();
			else if (sub != "..")
				res.push_back(sub);
		}
		string result;
		for (string temp : res)
			result += '/' + temp;
		return res.empty() ? "/" : result;
	}
};