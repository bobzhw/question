#include<vector>
#include<iostream>

using namespace std;

//��̬�滮˼�룺ά��һ���������洢n = iʱ���BST�ĸ����������Ļ�����һ����n�����Է�Ϊ���������
//�����ڵ���n,�Ǹ�����û��������������������n-1���ڵ㣬�����ڵ�Ϊi����ô��������i-1���ڵ㣬��������i+1���ڵ�;
//�����ݹ���ʽ
class Solution {
public:
	int numTrees(int n) {
		if (n == 0)
			return 0;
		vector<int> vec{ 1,2 };
		for (int i = 3; i <= n ;i++)
		{
			int count = 0;
			for (int j = 0; j < i; j++)
			{
				if (j == 0 || j == i-1)
				{
					count += vec[i - 2];
					continue;
				}
				count += vec[j-1] * vec[i - j - 2];
			}
			vec.push_back(count);	
		}
		return vec[n - 1];
	}
};