#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
	void solve(vector<vector<char>> &board) {
		if(board.empty() || board[0].empty())
			return;
		//遍历四条边看是否包含'O'
		int i = 0;
		for (i = 0; i < board[0].size(); i++)
		{
			if (board[0][i] == 'O')
				solveDFS(board,0,i);
			if (board[board.size() - 1][i] == 'O')
				solveDFS(board, board.size() - 1, i);
		}
		for (i = 0; i < board.size(); i++)
		{
			if (board[i][0] == 'O')
				solveDFS(board, i, 0);
			if (board[board[0].size() - 1][i] == 'O')
				solveDFS(board, board[0].size() - 1, i);
		}
		//处理完四条边的'O'相连的'O'，将剩下的'O'换成'X'
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == '%')
					board[i][j] = 'O';
			}
		}
	}
private:
	void solveDFS(vector<vector<char>> &board,int x,int y)
	{
		if (board[x][y] == 'O')
		{
			board[x][y] = '%';
			if (x > 0 && board[x - 1][y] == 'O')
				solveDFS(board, x - 1, y);
			if (x < board.size()-1 && board[x + 1][y] == 'O')
				solveDFS(board, x + 1, y);
			if (y > 0 && board[x][y - 1] == 'O')
				solveDFS(board, x, y - 1);
			if (y < board[0].size() - 1 && board[x][y + 1]=='O')
				solveDFS(board, x, y + 1);
		}
	}
};
