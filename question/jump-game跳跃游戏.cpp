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