#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string>> result;
		vector<vector<int>> mark;
		vector<string> location;
		for (int i = 0; i < n; i++)
		{
			mark.emplace_back(vector<int>());
			for (int j = 0; j < n; j++)
			{
				mark[i].emplace_back(0);
			}
			location.emplace_back();
			location[i].append(n, '.');
		}
		generate(0, n, location, result, mark);
		return result;
	}
private:
	void generate(int k, int n, vector<string>&location, vector<vector<string>>&result, vector<vector<int>>&mark)
	{
		if (k == n)
		{
			result.emplace_back(location);
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (mark[k][i] == 0)
			{
				vector<vector<int>> tmp_mark = mark;
				location[k][i] = 'Q';
				put_down_queue(k, i, mark);
				generate(k + 1, n, location, result, mark);
				mark = tmp_mark;
				location[k][i] = '.';
			}
		}
	}
	void put_down_queue(int x, int y, vector<vector<int>>& mark)
	{
		static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
		static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
		mark[x][y] = 1;
		for (int i = 1; i < mark.size(); i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int r_x = x + i*dx[j];
				int r_y = y + i*dy[j];
				if (r_x >= 0 && r_x < mark.size() && r_y >= 0 && r_y < mark.size())
				{
					mark[r_x][r_y] = 1;
				}
			}
		}
		
	}
};