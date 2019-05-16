#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int numDecodings(string s)
	{
		/** dp[i] 表示i的字符的合法编码数量，取决于当前字符
		dp[i] += dp[i-1],if s[i-1] ~('0'--'9')
		dp[i] += dp[i-2],if s[i-2] == '1' || (s[i-2]=='2' && s[i-1]>='0' && s[i-1]<='6')

		**/
		if (s.length() == 0 || s[0] == '0')
			return 0;
		int len = s.length();
		vector<int> dp(len + 1, 0);
		dp[0] = 1, dp[1] = 1;
		for (int i = 2; i <= len; i++)
		{
			if (s[i - 1] >= '1' && s[i - 1] <= '9')
				dp[i] += dp[i - 1];
			if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6'))
				dp[i] += dp[i - 2];
		}
		return dp[len];
	}
};