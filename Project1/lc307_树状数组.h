#pragma once
#include "stdfx.h"
class NumArray {
public:
	vector<int>cache;
	vector<int>c;
	int size;

	NumArray(vector<int>& nums) {
		size = nums.size();
		vector<int> t(size + 1, 0);
		cache.swap(t);
		for (int i = 1; i <= size; ++i) {
			update_(i, nums[i - 1]);
		}
		c = nums;
	}

	void update_(int i, int val) {
		while (i <= size) {
			cache[i] += val;
			i += lowbit(i);
		}

	}

	void update(int i, int val) {
		int tmp = val - c[i];
		c[i] = val;		
		update_(i + 1, tmp);
	}

	int sumRange(int i, int j) {
		return sum(j + 1) - sum(i);

	}

	int lowbit(int k) {
		return k&-k;
	}

	int sum(int i) {
		int total = 0;
		while (i>0) {
			total += cache[i];
			i -= lowbit(i);
		}
		return total;
	}


};

