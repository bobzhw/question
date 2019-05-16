#include<iostream>
#include<vector>
#include<string>

using namespace std;

// ˼·��IP��ַ��ȷ��ʽΪ4�����֣�ÿ������Ϊ0 - 255֮������֣�����ÿһλ���������λ��������1λ
//��ͷ��ʼ�жϷָ��ַ������б������������countΪ3���Ѿ�����4�����֣�������4�����ֶ�����Ч�ģ���ô˵�����ķָ�����ȷ��
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
