#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		int c[26] = { 0 };
		for (int i = 0; i < s1.length(); i++)
		{
			c[s1[i] - 'a']++;
			c[s2[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++)
			if (c[i] != 0)
				return false;
		for (int i = 1; i < s1.length(); i++)
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
				isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(s2.length() - i)) &&
				isScramble(s1.substr(i), s2.substr(0, s2.length() - i)))
				return true;

		}
		return false;
	}
};