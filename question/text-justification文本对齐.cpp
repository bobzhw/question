#include<vector>
#include<string>
#include<iostream>
using namespace std;

/*
���ȣ�����Lֵ�Ƿ��string����С��������򷵻�
��Σ��Դ˼���������ǰk��Ԫ���Լ�k-1���ո�ĺ��Ƿ����L��������ڣ�����k-1���ַ�������ͬһ��
����ֻ��Ҫ����Ҫ����Ŀո�ĸ�����ע�������Ϊ�����������������һ�У���ô�򵥵ؽ����еĳ��˱�Ҫ��
�ո�֮��Ŀո����֮�󼴿ɣ�����������һ�У���һ�е�Ҫ����ո��λ�þ�Ϊk-1������ôֻ�����ƽ��
�ո������ɣ�����ж���ļӵ�ǰ�漸���ո���봦
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