#pragma once
#include "stdfx.h"
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int size = nums.size();
		vector<bool>dp(size, false);
		dp[0] = true;
		for (int i = 0; i < size; ++i) {
			if (dp[i]) {
				int k = nums[i];
				while (k) {
					dp[i + k] = true;
					--k;
				}
			}
		}
		return dp[size - 1];
	}
};