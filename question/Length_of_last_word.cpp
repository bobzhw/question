#include<cstring>
#include<stdio.h>
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (s == nullptr)
			return 0;
		auto tmp = s + strlen(s) - 1;
		int count = 0;
		while (tmp >= s)
		{
			if (*tmp == ' ' && count != 0)
				return count;
			else if (*tmp != ' ')
				count++;
			tmp--;
		}
		return count;
	}
};