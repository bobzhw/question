#include<iostream>

using namespace std;
/*
* ���Ž⣺�Ӻ���ǰ����,����Ҫ���ٶ���ռ�
* Runtime: 0 ms.Your runtime beats 45.38 % of java submissions.
*/
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i = m - 1;
		int j = n - 1;
		int index = m + n - 1;
		while (i >= 0 && j >= 0)
		{
			A[index--] = B[j] > A[i] ? B[j--] : A[i--];
		}
		while (j >= 0)
		{
			A[index--] = B[j--];
		}
	}
};