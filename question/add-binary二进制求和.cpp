#include<string>
#include<iostream>
using namespace std;

//思路：很容易想到，从最后一位开始算起，维护一个carry进位符，遍历两个字符串，
//result每次计算两个对应位之和加上进位符的值，对之和进行比较,最后需要注意，如果
//遍历完之后进位符依然为1，则在结果之前加1即可
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