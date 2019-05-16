#include<iostream>
#include<vector>
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
	 vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		 vector<Interval> res;
		 int index = 0;
		 //��newInterval��intervals[i]���ص�ʱ
		 while (index < intervals.size() && newInterval.start > intervals[index].end)
		 {
			 res.emplace_back(intervals[index++]);
		 }
		 //�����ص�
		 while (index < intervals.size() && newInterval.end >= intervals[index].start)
		 {
			 newInterval.start = min(intervals[index].start, newInterval.start);
			 newInterval.end = max(intervals[index].end, newInterval.end);
			 index++;
		 }
		 res.emplace_back(newInterval);

		 //ʣ��
		 while (index < intervals.size())
		 {
			 res.emplace_back(intervals[index++]);
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