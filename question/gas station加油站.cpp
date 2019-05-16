#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
/**There are N gas stations along a circular route, where the amount of gas at station i isgas[i].

You have a car with an unlimited gas tank and it costscost[i]of gas to travel from station i to its next station(i + 1).You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
*/
using namespace std;
class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		if (gas.empty() || gas.size() == cost.size())
			return -1;
		int total = 0, sum = 0;
		int index = -1;
		for (int i = 0; i < gas.size(); i++)
		{
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0)
			{
				sum = 0;
				index = i;
			}
		}
		return total >= 0 ? index + 1 : -1;
	}
};