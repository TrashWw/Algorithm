#pragma once
#include <vector>
#include <memory>
using namespace std;
class NumArray {
public:
	unique_ptr<vector<int>>ans;
	int size = 0;
	vector<int>nums_;
	NumArray(vector<int>& nums) {
		size = nums.size();
		nums_.swap(nums);
		ans.reset(new vector<int>(size+1,0));
		(*ans)[0] = 0;
		for (int i = 1; i <= size; ++i) {
			(*ans)[i] = (*ans)[i - 1] + nums_[i - 1];
		}

	}

	void update(int i, int val) {
		int diff = nums_[i] - val;
		nums_[i] = val;
		for (; i < size; ++i) {
			(*ans)[i+1] -= diff;
		}
	}

	int sumRange(int i, int j) {
		return (*ans)[j + 1] - (*ans)[i];
	}
};