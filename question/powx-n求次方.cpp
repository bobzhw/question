#include<iostream>


class Solution {
public:
	double pow(double x, int n) {
		//Çó x^n = x^(n/2) + x^(n/2) + x^(n%2)
		if (n < 0) return 1.0 / power(x, -n);
		else return power(x, n);
	}
private:
	double power(double x, int n) {
		if (n == 0) return 1;
		double tmp = power(x, n / 2);
		if (n % 2 == 0) return tmp * tmp;
		else return tmp * tmp * x;
	}
};