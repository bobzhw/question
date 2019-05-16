#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		string tmp = "";
		for (int i = 0; i < s.size(); i++)
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
			{
				if (s[i] >= 'A'&& s[i] <= 'Z')
					s[i] = tolower(s[i]);
				string str(1, s[i]);
				tmp.append(str);
			}
		}
		return tmp == string(tmp.rbegin(), tmp.rend());
	}
};
