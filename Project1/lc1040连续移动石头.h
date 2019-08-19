#pragma once
#include "stdfx.h"

class Solution {
public:
	vector<int> numMovesStonesII(vector<int>& stones) {
		vector<int>ans(2, 0);
		sort(stones.begin(), stones.end());
		int size = stones.size();
		int l = 0, r = size - 1;
		int clip = min(stones[1] - stones[0], stones[r] - stones[r - 1]);
		if (clip == 1)
			ans[1] = stones[r] - stones[l] + 1 - size;
		else
			ans[1] = stones[r] - stones[l] + 1 - size - clip + 1;

		l = r = stones[0];
		int max_s = 0, p0 = 0, p1 = 0, current = 0;
		bool lian = false;
		for (; r <= stones[size - 1]; ++r) {
			int pos1 = p1;
			if (r - l + 1 > size) {
				if (stones[p0] == l) {
					--current;
					++p0;
				}
				++l;
			}
			if (stones[p1] == r) {
				++current;
				++p1;
			}
			if (max_s<current) {
				max_s = current;
				if (stones[pos1] - stones[p0] + 1 == size - 1)
					lian = false;
				else
					lian = true;
			}

		}
		if (stones[size - 1] - stones[0] + 1 == size)
			ans[0] = 0;
		else if (stones[size - 1] - stones[0] + 1 == size + 1)
			ans[0] = 1;
		else
			ans[0] = size - max_s == 1 && lian ? 2 : size - max_s;
		return ans;
	}
};