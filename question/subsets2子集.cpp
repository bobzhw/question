#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
		dfs(S, 0);
		return result;
	}
	void dfs(vector<int> set, int start) {
		result.push_back(tmp);
		for (int i = start; i < set.size(); ++i) {
			tmp.push_back(set[i]);
			dfs(set, i + 1);
			while (i<set.size() - 1 && set[i + 1] == set[i]) ++i;//比subset1多出的一行
			tmp.pop_back();
		}
	}
private:
	vector<vector<int> > result;
	vector<int> tmp;
};