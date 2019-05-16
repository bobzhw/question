#include<string>
#include<iostream>
using namespace std;

//˼·���������뵽�������һλ��ʼ����ά��һ��carry��λ�������������ַ�����
//resultÿ�μ���������Ӧλ֮�ͼ��Ͻ�λ����ֵ����֮�ͽ��бȽ�,�����Ҫע�⣬���
//������֮���λ����ȻΪ1�����ڽ��֮ǰ��1����
class Solution {
public:
	string addBinary(string a, string b) {
		int len1 = a.length();
		int len2 = b.length();
		int carry = 0;
		std::string res;
		int i = len1 - 1, j = len2 - 1;
		while (i >= 0 && j >= 0)
		{
			int result = a[i] + b[j] + carry - 96;	
			add(result, res, carry);
			--i; --j;
		}
		while (i >= 0)
		{
			int result = a[i] - 48 + carry;
			add(result, res, carry);
			--i;
		}
		while (j >= 0)
		{
			int result = b[j] - 48 + carry;
			add(result, res, carry);
			--j;
		}
		if (carry > 0)
			res = to_string(1) + res;
		return res;
		
	}

private:
	void add(int result, string& res, int& carry)
	{
		if (result >= 2)
		{
			carry = 1;
			result = result - 2;
		}
		else if (result < 2)
			carry = 0;
		res = to_string(result) + res;
	}
};