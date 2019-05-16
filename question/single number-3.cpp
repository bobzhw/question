class Solution {
public:
	int singleNumber(int A[], int n) {
		int ones = 0;
		int twos = 0;
		int three;
		for (int i = 0; i < n; i++)
		{
			int t = A[i];
			twos |= t&ones;//第一次出现，ones为0，twos更新为0，第二次出现，ones为t，twos更新为t，第三次出现，ones为0，twos依然为t
			ones ^= t;     //第一次出现，ones更新为t，第二次出现，ones更新为0，第三次出现ones为t
			three = ones&twos;//第一次出现，three为0，第二次出现，three为0，只有第三次three为t
			ones &= ~three;//去掉ones中的第三次出现的情况
			twos &= ~three; //去掉twos中第三次出现的青睐
		}
		return ones | twos;
	}
};