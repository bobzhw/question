

class Solution {
public:
	int sqrt(int x) {
		int i = 1;
		int res = 0;
		while (x >= 0)
		{
			x -= i;
			res++;
			i += 2;
		}
		return res - 1;
	}
};