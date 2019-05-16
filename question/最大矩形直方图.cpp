#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

/*
目的：用height[]构造一个升序栈,构造过程中计算面积；
如果当前height[i]大于栈顶元素，则入栈；
若小于栈顶元素，则将栈顶元素弹出并做记录弹出几次，并计算以弹出元素作为高度的面积，留下
最大值ret，直到满足height[i]大于栈顶元素，再将弹出的元素以height[i]重新入栈；
过程为 ：
1）2入栈；目前栈为{2}
2）1与2比较，不满足升序，则2弹出，记录count=1；ret=2*1；
1代替2再次入栈，然后当前1入栈；目前栈为{1,1}
3）5入栈，满足升序，6入栈满足升序；目前栈为{1,1,5,6,}
4）height[4]=2，即将入栈，由于2小于栈顶元素6，则6弹出，count=1，ret=max（2,6）=6；
2小于5,5弹出，count=2,ret=max(6,2*5)=10;
6和5 重新以2入栈，然后height[4]=2入栈；
目前栈为{1,1,2,2,2}
5）height[5]=3入栈；形成升序栈{1,1,2,2,2,3}
6）最后按照升序栈继续维护ret直至栈为空，max(ret,3*1,2*2,2*3,2*4*,1*5,1*6)=10;
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