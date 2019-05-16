#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();
		if (len1 + len2 != len3)
			return false;
		vector<vector<bool>> vv(len1 + 1, vector<bool>(len2 + 1, false));
		vv[0][0] = true;
		for (int i = 1; i <= len1; i++)
		{
			vv[i][0] = vv[i - 1][0] && (s1[i - 1] == s3[i - 1]);
		}
		for (int j = 1; j <= len2; j++)
		{
			vv[0][j] = vv[0][j - 1] && (s2[j - 1] == s3[j - 1]);
		}
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				vv[i][j] = (vv[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
					(vv[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return vv[len1][len2];
	}
};