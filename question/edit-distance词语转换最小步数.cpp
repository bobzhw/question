#include<string>
#include<iostream>
#include<unordered_map>
#include<cmath>
#include<climits>
using namespace std; 

class Solution {
public:
	int minDistance(string word1, string word2)
	{
		
		int len1 = word1.size();
		int len2 = word2.size();
		vector<vector<int>> res(len1+1, vector<int>(len2+1, UINT32_MAX));
		res[0][0] = 0;
		for (int i = 1; i < len1+1; i++)
		{
			res[i][0] = i;
		}
		for (int i = 1; i < len2+1; i++)
			res[0][i] = i;
		for (int i = 1; i < len1 + 1; i++)
		{
			for (int j = 1; j < len2 + 1; j++)
			{
				if (word1[i - 1] == word2[j - 1])
					res[i][j] = res[i - 1][j - 1];
				else
				{
					res[i][j] = min(min(res[i - 1][j], res[i][j - 1]), res[i - 1][j - 1])+1;
				}
			}
		}
		return res[len1][len2];
	}
private:
	int min(int x1,int x2)
	{
		return x1 < x2 ? x1 : x2;
	}
		
};