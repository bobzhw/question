#include<vector>
#include<string>
#include<iostream>
using namespace std;

/*
首先，计算L值是否比string长度小，如果是则返回
其次，以此计算数组中前k个元素以及k-1个空格的和是否大于L，如果大于，则这k-1个字符串处于同一行
接着只需要计算要插入的空格的个数，注意这里分为两种情况，如果是最后一行，那么简单地将所有的除了必要的
空格之外的空格插入之后即可，如果不是最后一行，这一行的要插入空格的位置就为k-1个，那么只需计算平均
空格数即可，如果有多余的加到前面几个空格插入处
*/
class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> res;
		if (words.empty() || L <0)
			return res;
		for (int index = 0; index < words.size(); index++)
		{
			if (words[index].size() > L)
				return res;
		}
		int i = 0, j = 0;

		while (i < words.size())
		{
			int sum = 0;
			while (j < words.size())
			{
				if (sum + words[j].size() > L)
				{
					sum--;
					break;
				}

				sum += words[j].size() + 1;
				j++;
			}
			int spaceplace = j - i - 1;
			if (spaceplace == 0)
			{
				std::string s = words[i];
				addspace(L - words[i].size(), s);
				res.push_back(s);
				i = j;
				continue;
			}
			if (j != words.size())
			{
				int x = (L - sum) / spaceplace;
				int y = (L - sum) % spaceplace;
				std::string s;
				for (int index = i; index < i + y; index++)
				{
					s += words[index];
					addspace(x + 2, s);
				}

				for (int index = i + y; index < j - 1; index++)
				{
					s += words[index];
					addspace(x + 1, s);
				}
				s += words[j - 1];

				res.push_back(s);
				i = j;
			}
			else
			{
				std::string s;
				for (int index = i; index < j - 1; index++)
				{
					s += words[index];
					addspace(1, s);
				}
				s += words[j - 1];
				addspace(L - s.size(), s);
				res.push_back(s);
				i = j;
			}
		}
		return res;
	}
private:
	void addspace(int num, string& s)
	{
		for (int i = 0; i < num; i++)
			s = s + " ";
	}
};