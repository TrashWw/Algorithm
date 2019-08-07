#pragma once
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int>ans;
		int size_num = num.size();
		if (size_num == 0)
			return ans;
		deque<int>max_pro;
		unsigned int i = 0;
		for (i = 0; i < size; ++i) {
			while (!max_pro.empty() && num[i] >= num[max_pro.back()])
				max_pro.pop_back();
			max_pro.push_back(i);
		}

		for (i = size; i<size_num; ++i) {
			ans.push_back(num[max_pro.front()]);

			while (!max_pro.empty() && num[i] >= num[max_pro.back()])
				max_pro.pop_back();
			if (!max_pro.empty() && max_pro.front() <= i - size)
				max_pro.pop_front();
			max_pro.push_back(i);
		}
		ans.push_back(num[max_pro.front()]);
		return ans;
	}
};