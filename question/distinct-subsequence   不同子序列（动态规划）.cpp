#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		vector<vector<int>> result(S.size()+1, { 1 });
		//1.初始化结果数组
		for (int i = 1; i < T.size()+1; i++)
			result[0].push_back(0);
		//2.填充数组，动态规划，自底向上
		for (int i = 1; i < S.size()+1; i++)
		{
			
			for (int j = 1; j < T.size()+1; j++)
			{
				if (S[i-1] == T[j-1])
					result[i].push_back(result[i - 1][j] + result[i - 1][j - 1]);
				else
					result[i].push_back(result[i - 1][j]);
			}
		}
		return result[S.size()][T.size()];
		
	}
};