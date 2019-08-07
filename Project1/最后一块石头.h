#pragma once
#include "stdfx.h"
namespace Solution {

	int lastStoneWeightII(vector<int>& stones) {
		int size = stones.size();
		int min_v = INT_MAX;
		
		vector<vector<int>> rest(size, vector<int>(size, 0));
		for (int i = 1; i < size; ++i) {
			rest[0][i] = abs(stones[i] - stones[0]);
		}
		for (int i = 1; i < size; ++i)
			for (int j = 1; j < size; ++j) {
				if (i != j) {
					rest[i][j] = abs(stones[i] - rest[i - 1][j]);

				}
			}

		for (int i = 1; i < size; ++i)
			min_v = min(min_v, rest[size - 1][i]);
		return min_v;
	}


	void test() {
		vector<int>t = {1,1,2,3,5,8,13,21,34,55,89,14,23,37,61,98};
		int te = lastStoneWeightII(t);
	}
};