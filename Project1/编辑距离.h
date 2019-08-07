#pragma once
#include "stdfx.h"
class Solution {
public:
	int minDistance(string word1, string word2) {
		int size_1 = word1.size();
		int size_2 = word2.size();
		vector<vector<int>> diff(size_1, vector<int>(size_2, 0));
		bool hasSame = false;
		for (int i = 0; i < size_1; ++i) {
			if (!hasSame&&word1[i] == word2[0])
				hasSame = true;
			if (hasSame)
				diff[i][0] = i - 1;
			else
				diff[i][0] = i;
		}
		hasSame = false;
		for (int i = 0; i < size_2; ++i) {
			if (!hasSame&&word1[0] == word2[i])
				hasSame = true;
			if (hasSame)
				diff[0][i] = i - 1;
			else
				diff[0][i] = i;
		}

		for (int i = 1; i < size_1; ++i)
			for (int j = 1; j < size_2; ++j) {
				diff[i][j] = min(min(diff[i - 1][j] + 1, diff[i][j - 1] + 1), diff[i - 1][j - 1] + (word1[i] == word2[j] ? 0 : 1));
			}

		return diff[size_1 - 1][size_2 - 1];
	}

	void test() {
		string str1 = "horse";
		string str2 = "ros";
		int e = minDistance(str1,str2);
	
	}

};