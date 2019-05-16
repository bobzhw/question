#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		vector<string> sym{ "+","-","*","/" };
		for (int i = 0; i < tokens.size(); i++)
		{
			if (count(sym.begin(), sym.end(), tokens[i]) == 1)
			{
				if (i - 2 < 0)
					return 0;
				int res = 0;
				if (tokens[i] == "+")
				{
					res = stoi(tokens[i - 2]) + stoi(tokens[i - 1]);
					tokens[i] = to_string(res);
				}
				if (tokens[i] == "-")
				{
					res = stoi(tokens[i - 2]) - stoi(tokens[i - 1]);
					tokens[i] = to_string(res);
				}
				if (tokens[i] == "*")
				{
					res = stoi(tokens[i - 2]) * stoi(tokens[i - 1]);
					tokens[i] = to_string(res);
				}
				if (tokens[i] == "/")
				{
					res = stoi(tokens[i - 2]) / stoi(tokens[i - 1]);
					tokens[i] = to_string(res);
				}
				auto it = tokens.begin();
				tokens.erase(it + i - 1);
				tokens.erase(it + i - 2);
				i = 0;

			}
		}
		if (tokens.size() != 1)
			return 0;
		return stoi(tokens[0]);
	}
};