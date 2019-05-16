
class Solution {
public:
	 int singleNumber(int A[], int n) {
		 int one = 0;
		 for (int i = 0; i < n; i++)
			 one ^= A[i];
		 return one;
	}
};
