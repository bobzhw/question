#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0 || n == 1)
			return n;
		int res = n;
		for (int i = 2; i < res; i++)
		{
			if (A[i] == A[i - 2] && A[i] == A[i - 1])
			{
				res--;
				for (int j = i; j < n-1; j ++)
				{
					A[j] = A[j + 1];
				}
				i--;
			}
		}
		return res;
	}
};