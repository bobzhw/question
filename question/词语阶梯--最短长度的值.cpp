#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<string> q;
		q.push(start);
		int count = 1;
		while (!q.empty())
		{
			int size = q.size();
			while (size--)
			{
				string tmp = q.front();
				q.pop();
				int len = tmp.size();
				for (int i = 0; i < len; i++)
				{
					char ch = tmp[i];
					for (int j = 0; j < 26; j++)
					{
						tmp[i] = 'a' + j;
						if (tmp == end)
							return count + 1;
						if (dict.find(tmp) != dict.end())
						{
							q.push(tmp);
							dict.erase(tmp);
						}
					}
					tmp[i] = ch;
				}
			}
			count++;
		}
		return 0;
	}
};