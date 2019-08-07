#pragma once

#include "stdfx.h"
namespace Solution {

	int get_size(int num) {
		switch (num) {
		case 7:
		case 9:
			return 4;
			break;
		default:
			return 3;

		}
		return 0;
	}


	string get_str(int digit, int num) {
		switch (digit) {
		case 8:
		{
			string add(1, char('a' + 19 + num));
			return add;
			break;
		}
		case 9:
		{
			string add_(1, char('a' + 22 + num));
			return add_;
			break;
		}
		default:
		{
			string add(1, char('a' + digit * 3 + num));
			return add;
		}

		}
		return "";
	}
	vector<string> letterCombinations(string digits) {
		vector<string>ans;
		int size = digits.size();
		if (size == 0)
			return ans;
		int size_num = get_size(digits[0] - '0');
		for (int i = 0; i < size_num; ++i) {
			ans.push_back(get_str(digits[0] - '0', i));
		}
		for (int i = 1; i < size; ++i) {
			int size_1 = ans.size();
			for (int j = 0; j < size_1; ++j) {
				size_num = get_size(digits[0] - '0');
				for (int k = 0; k < size_num - 1; ++k) {
					string t(ans[j] + get_str(digits[i] - '0', k));
					ans.push_back(t);
				}
				ans[j] += get_str(digits[i] - '0', size_num - 1);
			}
		}
		return ans;
	}

	void test() {
		vector<string> t = letterCombinations("999");
	}
};