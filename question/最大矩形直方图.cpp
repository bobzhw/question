#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

/*
Ŀ�ģ���height[]����һ������ջ,��������м��������
�����ǰheight[i]����ջ��Ԫ�أ�����ջ��
��С��ջ��Ԫ�أ���ջ��Ԫ�ص���������¼�������Σ��������Ե���Ԫ����Ϊ�߶ȵ����������
���ֵret��ֱ������height[i]����ջ��Ԫ�أ��ٽ�������Ԫ����height[i]������ջ��
����Ϊ ��
1��2��ջ��ĿǰջΪ{2}
2��1��2�Ƚϣ�������������2��������¼count=1��ret=2*1��
1����2�ٴ���ջ��Ȼ��ǰ1��ջ��ĿǰջΪ{1,1}
3��5��ջ����������6��ջ��������ĿǰջΪ{1,1,5,6,}
4��height[4]=2��������ջ������2С��ջ��Ԫ��6����6������count=1��ret=max��2,6��=6��
2С��5,5������count=2,ret=max(6,2*5)=10;
6��5 ������2��ջ��Ȼ��height[4]=2��ջ��
ĿǰջΪ{1,1,2,2,2}
5��height[5]=3��ջ���γ�����ջ{1,1,2,2,2,3}
6�����������ջ����ά��retֱ��ջΪ�գ�max(ret,3*1,2*2,2*3,2*4*,1*5,1*6)=10;
*/
class Solution {
public:
	;
	int largestRectangleArea(vector<int> &height) {
		int result = 0;
		stack<int> st;
		for (auto it = height.begin(); it != height.end(); ++it)
		{
			if (st.empty() || st.top() <= *it)
				st.push(*it);
			else
			{
				int count = 0;
				while (!st.empty() && st.top() > *it)
				{
					// [](int a, int b) -> bool { return a < b; }
					count++;
					result = result > count*st.top() ? result : count*st.top();
					st.pop();
				}
				while (count-- > 0)
				{
					st.push(*it);
				}
				st.push(*it);
			}
		}
		for (int i = 0; i < height.size(); i++)
		{
			int com = st.top() * (i+1);
			st.pop();
			result = result > com ? result : com;
		}
		return result;
	}
};