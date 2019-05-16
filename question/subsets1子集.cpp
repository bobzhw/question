#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<int> tmpres;
		dfs(S, 0, tmpres);
		return res;
	}
	void dfs(vector<int> &S, int iend, vector<int> &tmpres) {
		if (iend == S.size())
		{
			res.push_back(tmpres);
			return;
		}
		tmpres.push_back(S[iend]);
		dfs(S, iend + 1, tmpres);
		tmpres.pop_back();
		dfs(S, iend + 1, tmpres);
	}
};