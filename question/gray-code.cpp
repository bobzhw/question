#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		result.push_back(0);
		for (int i = 0; i < n; i++) {
			const int hight_bit = 1 << i;
			for (int j = result.size() - 1; j >= 0; j--) 
				result.push_back(hight_bit | result[j]);
		}
		return result;
	}
};