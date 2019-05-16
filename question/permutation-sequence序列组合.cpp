#include<string>

using namespace std;
class Solution {
public:
	string getPermutation(int n, int k) {
		string tmp_n;
		for (int i = 1; i<=n; ++i)
		{
			tmp_n += to_string(i);
		}
		
		if (tmp_n.size() == 1)
		{
			if (k == 1)
				return tmp_n;
			else
				return "";
		}
		auto i = tmp_n.end();
		--i;
		while ((k--) > 0)
		{
			for (;;)
			{
				if (i == tmp_n.begin())
				{
					reverse(tmp_n.begin(), tmp_n.end());
					break;
				}
				auto ii = i;
				i--;

				if (*i < *ii)
				{
					auto j = tmp_n.end();
					while (!(*i < *(--j)));
					iter_swap(i, j);
					reverse(ii, tmp_n.end());
					break;
				}
				
			}
		}
		return tmp_n;
		
	}
};