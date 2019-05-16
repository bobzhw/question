#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
	
	bool exist(vector<vector<char> > &board, string word) {
		for (int i = 0; i < board.size(); i++)
		{
			vector<vector<bool>> flags(board.size(), vector<bool>(board[0].size()));
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == word[0])
				{
					if (dfs_search(board, word, i, j, flags))
						return true;
				}
					
			}
		}
		return false;
	}
private:
	int step[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
	bool dfs_search(vector<vector<char> > &board, string word,int startX,int startY, vector<vector<bool>>& flags)
	{
		int rows = board.size();
		int cols = board[0].size();
		if (word.empty())
			return true;
		if (startX<0 || startX >= rows || startY < 0 || startY >= cols)
			return false;
		if (board[startX][startY] != word[0] || flags[startX][startY])
			return false;
		flags[startX][startY] = true;
		for (int i = 0; i < 4; i++)
		{
			if (dfs_search(board, word.substr(1), startX + step[i][0], startY + step[i][1], flags))
				return true;
			
		}
		flags[startX][startY] = false;
		return false;
	}
};