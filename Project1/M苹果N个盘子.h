#pragma once
#include "stdfx.h"
void test() {
	int apple = 0;
	cin >> apple;
	int pan = 0;
	cin >> pan;
	vector<vector<int>>dp(apple + 1, vector<int>(pan + 1, 0));
	for (int i = 0; i <= apple; ++i)
		dp[i][1] = 1;
	for (int i = 0; i <= pan; ++i)
		dp[0][i] = 1;

	for (int i = 1; i <= apple; ++i)
		for (int j = 1; j <= pan; ++j) {
			if (i >= j)
				dp[i][j] = dp[i][j - 1] + dp[i - j][j];
			else
				dp[i][j] = dp[i][i];
		}
	cout << dp[apple][pan];
	


}
