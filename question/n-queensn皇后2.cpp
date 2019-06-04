#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		vector<vector<int>> mark(n, vector<int>(n, 0));
		int count = 0;
		generate(0, n, mark, count);
		return count;
		
	}
private:
	void generate(int k, int n, vector<vector<int>>&mark,int& count)
	{
		if (k == n)
		{
			count++;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (mark[k][i] == 0)
			{
				auto tmpmark = mark;
				put_down_queen(k, i, mark);
				generate(k + 1, n, mark,count);
				mark = tmpmark;
			}
		}
	}
	void put_down_queen(int x, int y, vector<vector<int>>&mark)
	{
		vector<int> dx{ -1,1,0,0,-1,-1,1,1 };
		vector<int> dy{ 0,0,-1,1,-1,1,-1,1 };
		mark[x][y] = 1;
		for (int i = 1; i < mark.size(); i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int new_x = x + i*dx[j];
				int new_y = y + i*dy[j];
				if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size())
				{
					mark[new_x][new_y] = 1;
				}
			}
		}
	}
};