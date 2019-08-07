#pragma once
#include "stdfx.h"
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		/*sort(coins.begin(), coins.end());
		int size = coins.size();
		vector<vector<int>> nums(size + 1, vector<int>(amount + 1, 0));
		for (int i = 1; i <= amount; i++) {
			nums[0][i] = amount + 1;
		}
		for (int i = 1; i <= size; ++i)
			for (int j = 1; j <= amount; ++j) {
				if (j - coins[i-1]>=0)
					nums[i][j] = min(nums[i - 1][j], nums[i][j - coins[i-1]] + 1);
				else
					nums[i][j] = nums[i - 1][j];
			}

		return nums[size][amount];*/

		vector<int> dp(amount + 1, 0);
		for (int i = 1; i <= amount; ++i) {
			if (i - coins[0] >= 0 && dp[i - coins[0]] != INT_MAX)
				dp[i] = dp[i - coins[0]] + 1;
			else
				dp[i] = INT_MAX;
		}
		int size = coins.size();
		for (int i = 1; i < size; ++i) {
			for (int j = 1; j <= amount; ++j) {
				if (j - coins[i] >= 0 && dp[j - coins[i]] != INT_MAX)
					dp[j] = dp[j - coins[i]] + 1;
			}
		}
		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}
};