#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		sort(intervals.begin(), intervals.end(), [](Interval lhs, Interval rhs)->bool {return lhs.start < rhs.start; });
		vector<Interval> res;
		if (intervals.empty())
			return res;
		res.emplace_back(intervals[0]);
		int index = 1;
		
		while (index < intervals.size())
		{
			//没有重叠
			if (intervals[index].start > res[res.size() - 1].end)
			{
				res.emplace_back(intervals[index++]);
			}
			//有重叠
			else if (intervals[index].end >= res[res.size() - 1].start)
			{
				res[res.size() - 1].start = min(intervals[index].start, res[res.size() - 1].start);
				res[res.size() - 1].end=max(intervals[index].end, res[res.size() - 1].end);
				index++;
			}
		}
		return res;
	
	}
private:
	int min(int lhs, int rhs)
	{
		return lhs <= rhs ? lhs : rhs;
	}
	int max(int lhs, int rhs)
	{
		return lhs > rhs ? lhs : rhs;
	}
};