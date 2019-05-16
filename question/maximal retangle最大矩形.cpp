#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.size() == 0)
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> h(n);
		int maxS = 0;
		int num;
		stack<int> st;
		st.push(-1);
		for (int i = 0; i<m; i++)
		{
			//求当前第i行往上连续1的个数，不连续就置为0，方便下一行统计
			//j表示列号，即直方图的连续序号
			for (int j = 0; j<n; j++)
			{
				if (matrix[i][j] == '1')
					h[j]++;
				else
					h[j] = 0;
			}
			for (int j = 0; j<n; j++)
			{
				//这里主要思路是遇到上升序列就入栈，遇到下降序列就计算当前前一个直方图(即当前栈顶序号)
				//到所有依次出栈（即降序且大于j指向直方图的高度）直方图的距离，然后乘以出栈直方图的高度，
				//即为当前的面积(不一定最大),剩下的序列依然是升序的，迭代下去
				while (st.top() != -1 && h[j]<h[st.top()])
				{
					num = st.top();
					st.pop();
					maxS = max(maxS, (j - 1 - st.top())*h[num]);
				}
				st.push(j);
			}
			//计算栈中最后一个上升序列的面积（方法同上）
			while (st.top() != -1)
			{
				num = st.top();
				st.pop();
				maxS = max(maxS, (n - 1 - st.top())*h[num]);
			}
		}
		return maxS;
	}
	int max(int lhs, int rhs)
	{
		return lhs >= rhs ? lhs : rhs;
	}
};