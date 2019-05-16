#include<cstring>
#include<regex>
#include<iostream>
using namespace std;
class Solution {
public:
	bool isNumber(const char *s) {		
		//regex r("(\\s)*([+-])?(((\\d)*\\.)?((\\d)+)|((\\d)+)(\\.[0-9]*)?)([eE][+-]?[0-9]+)?(\\s)*");
		regex r("([\+\-]\d*\.\d+)|([\+\-]\d*[Ee]\d+)");
		return regex_match(s, r);
		
		
	}
};