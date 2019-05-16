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
			//��ǰ��i����������1�ĸ���������������Ϊ0��������һ��ͳ��
			//j��ʾ�кţ���ֱ��ͼ���������
			for (int j = 0; j<n; j++)
			{
				if (matrix[i][j] == '1')
					h[j]++;
				else
					h[j] = 0;
			}
			for (int j = 0; j<n; j++)
			{
				//������Ҫ˼·�������������о���ջ�������½����оͼ��㵱ǰǰһ��ֱ��ͼ(����ǰջ�����)
				//���������γ�ջ���������Ҵ���jָ��ֱ��ͼ�ĸ߶ȣ�ֱ��ͼ�ľ��룬Ȼ����Գ�ջֱ��ͼ�ĸ߶ȣ�
				//��Ϊ��ǰ�����(��һ�����),ʣ�µ�������Ȼ������ģ�������ȥ
				while (st.top() != -1 && h[j]<h[st.top()])
				{
					num = st.top();
					st.pop();
					maxS = max(maxS, (j - 1 - st.top())*h[num]);
				}
				st.push(j);
			}
			//����ջ�����һ���������е����������ͬ�ϣ�
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