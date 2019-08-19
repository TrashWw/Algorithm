#pragma once
#include "stdfx.h"
class Solution {
public:
	int merge(vector<int>&data, int i, int mid, int j) {
		vector<int> tmp(j - i + 1, 0);
		int p0 = mid;
		int p1 = j;
		int index = j - i;
		int ans = 0;
		while (p0 >= i&&p1>mid) {
			if (data[p0]>data[p1]) {
				ans += (p1 - mid);
				tmp[index--] = data[p0--];
			}
			else {
				tmp[index--] = data[p1--];
			}

		}
		while (p0 >= i) {
			tmp[index--] = data[p0--];
		}
		while (p1>mid) {
			tmp[index--] = data[p1--];
		}
		index = 0;
		for (; i <= j; ++i) {
			data[i] = tmp[index++];
		}
		return ans;
	}

	int getPairs(vector<int>&data, int i, int j) {
		if (i >= j)
			return 0;
		int mid = (i + j) >> 1;
		int bf = getPairs(data, i, mid);
		int af = getPairs(data, mid + 1, j);
		return bf + af + merge(data, i, mid, j);

	}

	int InversePairs(vector<int> data) {
		
		return getPairs(data, 0, data.size() - 1);
	}
};
