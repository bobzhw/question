#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		unordered_map<char, int> maps;
		string result;
		for (int i = 0; i < T.size(); i++)
		{
			if (maps.find(T[i]) == maps.end())
				maps[T[i]] = 1;
			else
				maps[T[i]]++;
		}
		int start = 0;
		int count = 0;
		int minlen = S.size() + 1;
		for(int end = 0;end < S.size();end++)
		{
			if (maps.find(S[end]) != maps.end())
			{
				if (maps[S[end]] > 0)
					count++;
				maps[S[end]]--;
				//此时所有元素都在区间内
				while (count == T.size())
				{
					if (maps.find(S[start]) != maps.end())
					{
						if (minlen > end - start + 1)
						{
							minlen = end - start + 1;
							result = S.substr(start, minlen);
						}
						//此处很精妙！！！maps[S[start]]++代表当前元素被踢出区间，如果区间内不含该元素
						//那么这个值就大于0，如果仍然包含这个值那么值就小于等于0
						maps[S[start]]++;
						if (maps[S[start]] > 0)
							count--;
					}
					start++;
				}
			}
		}
		return result;
	}

	string minWindow2(string S, string T)
	{
		unordered_map<char, int> maps;
		for (int i = 0; i < T.size(); i++)
		{
			if (maps.find(maps[T[i]]) != maps.end())
				maps[T[i]] = 1;
			else
				maps[T[i]]++;
		}
		
		int end = 0;
		int minlen = S.size() + 1;
		string result;
		for (int start = 0; start < S.size(); start++)
		{
			int count = 0;
			end = start;
			if (maps.find(S[start]) != maps.end())
			{
				while (count != T.size() &&end < S.size())
				{
					if (maps.find(S[end]) != maps.end())
						count++;
					end++;
				}
				if (count == T.size())
				{
					if (minlen > end - start)
					{
						minlen = end - start;
						result = S.substr(start, minlen);
					}
				}
				maps[S[start]]++;
			}
		}
		return result;
	}
};