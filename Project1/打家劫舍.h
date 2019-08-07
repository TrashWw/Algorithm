#pragma once
#include "stdfx.h"
class Solution {
public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		if (size = 0)
			return 0;
		vector<pair<int, bool>>dp(size + 1, { 0,false });
		dp[0] = { nums[size - 1],true };
		if (dp[0].first>nums[0])
			dp[1] = { dp[0].first,true };
		else
			dp[1] = { nums[0],false };
		for (int i = 2; i<size; ++i) {
			if (i + 1 == size) {
				dp[i] = { max(dp[i - 2].second ? nums[i - 1] : dp[i - 2].first + nums[i - 1],dp[i - 1].first),false };
			}
			else {
				if (dp[i - 2].first + nums[i - 1]>dp[i - 1].first) {
					dp[i] = { dp[i - 2].first + nums[i - 1],dp[i - 2].second };
				}
				else {
					dp[i] = dp[i - 1];
				}
			}
		}

		return dp[size - 1].first;
	}
};