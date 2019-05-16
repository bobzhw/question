#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int> > combine(int n, int k) {
		vector<int> tmp;
		com(1, k, tmp,k,n);
		return res;
	}
private:
	void com(int n, int k, vector<int> tmp,int size,int v)
	{
		if (k <= 0 || n >v)
		{
			if (tmp.size() == size)
			{
				//reverse(tmp.begin(), tmp.end());
				res.push_back(tmp);
			}	
			return;
		}
		tmp.push_back(n);
		com(n + 1, k - 1, tmp,size,v);
		tmp.pop_back();
		com(n + 1, k, tmp,size,v);
	}
};