#pragma once
#include <string>
#include "stdfx.h"

class Solution {
public:

	static int countDigitOne(int n) {
		if (n < 1)
			return 0;
		else if (n < 10)
			return 1;
		string number;
		number = to_string(n);
		int size = number.size();
		int restVal = n - (pow(10, size - 1)*(number[0]-'0'));
		int restPow = pow(10, size - 1);
		if (number[0] == '1') {
			return (restVal + 1) + countDigitOne(restVal)+ countDigitOne(restPow-1);
		}
		else {
			return restPow + countDigitOne(restPow-1)*(number[0] - '0') + countDigitOne(restVal);
		}

	}
};