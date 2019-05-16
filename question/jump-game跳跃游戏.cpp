#include<iostream>
using namespace std;
class Solution {
public:
	bool canJump(int A[], int n) {
		int index = 0;
		while (index < n)
		{
			if (A[index] == 0)
				return false;
			index += A[index];
		}
		return true;
	}
};
int main()
{
	Solution so;
	int A[5] = { 2,3,1,1,4 };
	cout << so.canJump(A, 5) << endl;;
}